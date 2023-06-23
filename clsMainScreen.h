#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include "clsInputValidate.h"
#include "clsString.h"
#include "clsUtil.h"
#include "clsQuestion.h"
#include "clsQuiz.h"

class clsMainScreen
{

private:

	static clsQuestion::enOperationType _ReadOperationType()
	{
		cout << "\n 1 - Add (+)";
		cout << "\n 2 - Sub (-)";
		cout << "\n 3 - Mul (*)";
		cout << "\n 4 - Div (/)";
		cout << "\n 5 - Random";

		cout << "\n\n Enter Operations Type? ";

		return (clsQuestion::enOperationType) clsInputValidate::ReadNumberbetween<short>(1, 5, " Enter Operations Type? ");
	}

	static clsQuestion::enDifficultyLevel _ReadDifficultlyLevel()
	{
		cout << "\n 1 - Easy";
		cout << "\n 2 - Medium";
		cout << "\n 3 - Hard";
		cout << "\n 4 - Random";
		
		cout << "\n\n Enter Difficultly Level? ";

		return (clsQuestion::enDifficultyLevel) clsInputValidate::ReadNumberbetween<short>(1, 4, " Enter Difficultly Level? ");
	}

	static short _ReadTotalQuestions()
	{
		cout << " How Many Qustions Do You Want From 1 To 100? ";
		
		return clsInputValidate::ReadNumberbetween<short>(1, 100, " How Many Qustions Do You Want From 1 To 100? ");
	}

	static void _ChangeScreenColor(bool Result)
	{
		if (Result)
			system("color 2F");

		else
			system("color 4F");
	}

	static void _ResetScreenColor()
	{
		system("color 0F");
	}

	static void _PrintFinalResult(clsQuiz &Quiz)
	{
		_ChangeScreenColor(Quiz.IsPass());

		cout << "\n" << clsUtil::Tabs(4) << "__________________________________________________\n\n";
		cout << clsUtil::Tabs(6) << "  RESULT : " << clsQuestion::getPassOrFail(Quiz.IsPass()) << endl;
		cout << clsUtil::Tabs(4) << "__________________________________________________\n\n";

		cout << clsUtil::Tabs(4) << "________________ [Final RESULTS] _________________\n\n";
		cout << clsUtil::Tabs(5) << "Total Questions   :       " << Quiz.TotalQuestions() << endl;
		cout << clsUtil::Tabs(5) << "Difficultly Level :       " << Quiz.getDifficultyLevelName() << endl;
		cout << clsUtil::Tabs(5) << "Operation Type    :       " << Quiz.getOperationsSympol() << endl;
		cout << clsUtil::Tabs(5) << "Right Answers     :       " << Quiz.RightAnswersCount() << endl;
		cout << clsUtil::Tabs(5) << "Wrong Answers     :       " << Quiz.WrongAnswersCount() << endl;
		cout << clsUtil::Tabs(5) << "Percentage        :       " << setprecision(2) << fixed << Quiz.Average() << endl;
		cout << clsUtil::Tabs(5) << "Result            :       " << clsQuestion::getPassOrFail(Quiz.IsPass()) << endl;
		cout << clsUtil::Tabs(4) << "__________________________________________________\n\n";
	}

	static void _PrintQuestion(short QuestionNumber, short TotalQuestions, clsQuestion Question)
	{
		cout << "\n Question [" << QuestionNumber<< "/" << TotalQuestions << "]\n\n";

		cout << "  " << Question.Number1() << endl;
		cout << "  " << Question.Number2() << "  " << Question.getOperationSympol();
		cout << "\n ______________________\n  ";
	}

	static void _PauseScreen()
	{
		cout << "\n Press Any Key To Continue...\n ";

		system("pause > 0");
	}

	static void _AskAndQorrectQuestions(clsQuiz& Quiz)
	{
		short TotalQuestions = Quiz.TotalQuestions();

		for (short i = 0; i < TotalQuestions; i++)
		{
			clsQuestion Question = *Quiz.QuestionsList(i);

			_PrintQuestion(i + 1, TotalQuestions, Question);

			Quiz.QuestionsList(i)->Answer = (clsInputValidate::ReadNumber<int>(""));

			if (Quiz.QuestionsList(i)->IsPass())
			{
				cout << "\n Right Answer -:)\n";
			}

			else
			{
				cout << "\n Wrong Answer -:(";
				cout << "\n Right Answer is: " << Quiz.QuestionsList(i)->RightAnswer() << endl;
			}

			_ChangeScreenColor(Quiz.QuestionsList(i)->IsPass());
			_PauseScreen();
			clsUtil::ResetScreen();
			_ResetScreenColor();
		}

	}

	static bool _PlayAgain()
	{
		char PlayAgain = 'N';

		cout << "\n DO YOU WANT TO PLAY AGAIN? Y/N? ";
		cin >> PlayAgain;

		return toupper(PlayAgain) == 'Y';
	}

	static void _PlayGame()
	{
		short TotalQuestions = _ReadTotalQuestions();
		clsQuestion::enDifficultyLevel DifficultyLevel = _ReadDifficultlyLevel();
		clsQuestion::enOperationType OT = _ReadOperationType();

		clsQuiz Quiz(TotalQuestions, OT, DifficultyLevel);

		_AskAndQorrectQuestions(Quiz);

		Quiz.FillFinalResult();

		_PrintFinalResult(Quiz);
	}

public:

	static void ShowMainScreen()
	{
		do
		{
			clsUtil::ResetScreen();

			_ResetScreenColor();

			_PlayGame();

		} while (_PlayAgain());

	}

};

