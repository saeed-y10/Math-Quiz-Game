#pragma once

#include <iostream>
#include <vector>
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsQuestion.h"

class clsQuiz
{

private:

	vector <clsQuestion> _Quiz;
	short _TotalQuestions;
	short _RightAnswers;
	short _WrongAnswers;

	clsQuestion::enOperationType _OperationsType;
	clsQuestion::enDifficultyLevel _DifficultyLevel;

	void _GenerateQuiz(short TotalQuestions, clsQuestion::enOperationType OperationsType, clsQuestion::enDifficultyLevel DifficultyLevel)
	{
		for (short i = 1; i <= TotalQuestions; i++)
		{
			_Quiz.push_back(clsQuestion(OperationsType, DifficultyLevel));
		}
	}
	

public:

	clsQuiz(short TotalQuestions, clsQuestion::enOperationType OperationsType, clsQuestion::enDifficultyLevel DifficultyLevel)
	{
		_TotalQuestions = TotalQuestions;
		_OperationsType = OperationsType;
		_DifficultyLevel = DifficultyLevel;
		_RightAnswers = 0;
		_WrongAnswers = 0;

		_GenerateQuiz(TotalQuestions, OperationsType, DifficultyLevel);
	}

	short TotalQuestions()
	{
		return _Quiz.size();
	}

	bool IsEmpty()
	{
		return _Quiz.empty();
	}

	void setOperationsType(clsQuestion::enOperationType OperationsType)
	{
		_OperationsType = OperationsType;
	}

	clsQuestion::enOperationType getOperationsType()
	{
		return _OperationsType;
	}
	__declspec(property(get = getOperationsType, put = setOperationsType)) clsQuestion::enOperationType OperationsType;

	void setDifficultyLevel(clsQuestion::enDifficultyLevel DifficultyLevel)
	{
		_DifficultyLevel = DifficultyLevel;
	}

	clsQuestion::enDifficultyLevel getDifficultyLevel()
	{
		return _DifficultyLevel;
	}
	__declspec(property(get = getDifficultyLevel, put = setDifficultyLevel)) clsQuestion::enDifficultyLevel DifficultyLevel;

	clsQuestion* QuestionsList(int Index)
	{
		if (_Quiz.empty())
			return NULL;

		if (Index >= _Quiz.size())
			return NULL;
		
		return &_Quiz[Index];
	}

	clsQuestion* getLastQuestion()
	{
		if (_Quiz.empty())
			return NULL;

		return &_Quiz.back();
	}

	void FillFinalResult()
	{
		if (_Quiz.empty())
			return;

		for (clsQuestion &Question : _Quiz)
		{
			(Question.IsPass() ? _RightAnswers++ : _WrongAnswers++);
		}

	}

	vector<clsQuestion> getQuestionsList()
	{
		return _Quiz;
	}

	short WrongAnswersCount()
	{
		return _WrongAnswers;
	}

	short RightAnswersCount()
	{
		return _RightAnswers;
	}

	float Average()
	{
		if (_Quiz.empty())
			return 0;

		return (float) _RightAnswers * 100 / _Quiz.size();
	}

	bool IsPass()
	{
		if (_WrongAnswers == 0 && _RightAnswers == 0)
			return false;
	
		return _RightAnswers >= _WrongAnswers;
	}

	void AddQuestions(short NumberOfQusteions)
	{
		for (short i = 1; i <= NumberOfQusteions; i++)
		{
			_Quiz.push_back(clsQuestion(_OperationsType, _DifficultyLevel));
		}

		_TotalQuestions += NumberOfQusteions;
	}

	void Clear()
	{

		while (!_Quiz.empty())
		{
			_Quiz.pop_back();
		}

		_TotalQuestions = 0;
		_RightAnswers = 0;
		_WrongAnswers = 0;
	}

	string getOperationsSympol()
	{
		return clsQuestion::getOperationSympol(_OperationsType);
	}

	string getDifficultyLevelName()
	{
		return clsQuestion::DifficultyLevelName(_DifficultyLevel);
	}

};

