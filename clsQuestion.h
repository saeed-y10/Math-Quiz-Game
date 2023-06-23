#pragma once

#include <iostream>
#include <vector>
#include "clsInputValidate.h"
#include "clsUtil.h"

class clsQuestion
{

private:

	enum enOperationType;
	enum enDifficultyLevel;

	int _Number1;
	int _Number2;
	enOperationType _OperationType;
	enDifficultyLevel _DifficultyLevel;
	int _RightAnswer;
	int _UserAnswer;
	int _Result;

	enOperationType _GetRandomOperationType()
	{
		return (enOperationType)clsUtil::RandomNumber(1, 4);
	}

	enDifficultyLevel _GetRandomDifficultyLevel()
	{
		return (enDifficultyLevel)clsUtil::RandomNumber(1, 3);
	}

	int _GetNumberByDifficultyLevel(enDifficultyLevel DifficultyLevel)
	{
		switch (DifficultyLevel)
		{
		case clsQuestion::lEasy:
			return clsUtil::RandomNumber(1, 20);

		case clsQuestion::lMedium:
			return clsUtil::RandomNumber(21, 40);

		case clsQuestion::lHard:
			return clsUtil::RandomNumber(41, 100);

		default:
			return clsUtil::RandomNumber(1, 20);
		}
	}

	int _Calculator(int Number1, int Number2, enOperationType OperationType)
	{
		switch (OperationType)
		{
		case enOperationType::oAddition:
			return Number1 + Number2;

		case enOperationType::oSubtract:
			return Number1 - Number2;

		case enOperationType::oMultiply:
			return Number1 * Number2;

		case enOperationType::oDivision:

			if (Number2 == 0)
				return 0;
			else
				return Number1 / Number2;

		default:
			return 0;
		}
	}

	void _GenerateQuestion()
	{
		if (_OperationType == enOperationType::oRandom)
			_OperationType = _GetRandomOperationType();

		if (_DifficultyLevel == enDifficultyLevel::lRandom)
			_DifficultyLevel = _GetRandomDifficultyLevel();

		_Number1 = _GetNumberByDifficultyLevel(_DifficultyLevel);
		_Number2 = _GetNumberByDifficultyLevel(_DifficultyLevel);

		_RightAnswer = _Calculator(_Number1, _Number2, _OperationType);
	}

public:

	clsQuestion(enOperationType OperationType, enDifficultyLevel DifficultyLevel)
	{
		_Number1 = 0;
		_Number2 = 0;
		_OperationType = OperationType;
		_DifficultyLevel = DifficultyLevel;
		_RightAnswer = 0;
		_UserAnswer = 0;
		_Result = false;

		_GenerateQuestion();
	}

	enum enOperationType
	{
		oAddition = 1,
		oSubtract = 2,
		oMultiply = 3,
		oDivision = 4,
		oRandom = 5,
	};

	enum enDifficultyLevel
	{
		lEasy = 1,
		lMedium = 2,
		lHard = 3,
		lRandom = 4,
	};

	void setAnswer(int Answer)
	{
		_UserAnswer = Answer;

		_Result = (_UserAnswer == _RightAnswer);
	}

	int getAnswer()
	{
		return _UserAnswer;
	}
	__declspec(property(get = getAnswer, put = setAnswer)) int Answer;

	bool IsPass()
	{
		return (_UserAnswer == _RightAnswer);
	}

	static string getPassOrFail(bool Result)
	{
		return (Result ? "Pass" : "Fail");
	}

	string getPassOrFail()
	{
		getPassOrFail(IsPass());
	}

	int RightAnswer()
	{
		return _RightAnswer;
	}

	int Number1()
	{
		return _Number1;
	}

	int Number2()
	{
		return _Number2;
	}

	enOperationType getOperationType()
	{
		return _OperationType;
	}

	enDifficultyLevel getDifficultyLevel()
	{
		return _DifficultyLevel;
	}

	static string getOperationSympol(enOperationType OperationType)
	{
		switch (OperationType)
		{
		case clsQuestion::oAddition:
			return "+";
		case clsQuestion::oSubtract:
			return "-";
		case clsQuestion::oMultiply:
			return "*";
		case clsQuestion::oDivision:
			return "/";
		case clsQuestion::oRandom:
			return "Random";
		default:
			return "";
		}
	}

	string getOperationSympol()
	{
		return getOperationSympol(_OperationType);
	}

	static string DifficultyLevelName(enDifficultyLevel DifficultyLevel)
	{
		switch (DifficultyLevel)
		{
		case clsQuestion::lEasy:
			return "Easy";
		case clsQuestion::lMedium:
			return "Medium";
		case clsQuestion::lHard:
			return "Hard";
		case clsQuestion::lRandom:
			return "Random";
		default:
			return "";
		}
	}

	string DifficultyLevelName()
	{
		return DifficultyLevelName(_DifficultyLevel);
	}

};

