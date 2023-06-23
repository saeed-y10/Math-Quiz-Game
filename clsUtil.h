#pragma once

#include <iostream>
#include <string>
#include <ctime>
//#include "clsDate.h"

using namespace std;

class clsUtil
{

public:

	static void Srand()
	{
		//Seeds the random number generator in C++, called only once
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		return rand() % (To - From + 1) + From;
	}

	enum enCharType
	{
		CapitalLetter = 1,
		SmallLetter = 2,
		Digit = 3,
		SpecialCharacter = 4,
		MixChars = 5,
	};

	static char RandomCharacter(enCharType CharType)
	{
		//this method to accept mixchars
		if (CharType == MixChars)
		{
			//Capital/Samll/Digits only
			CharType = (enCharType)RandomNumber(1, 3);

		}

		switch (CharType)
		{
		case enCharType::CapitalLetter:
			return char(RandomNumber(65, 90));

		case enCharType::SmallLetter:
			return char(RandomNumber(97, 122));

		case enCharType::SpecialCharacter:
			return char(RandomNumber(33, 47));

		case enCharType::Digit:
			return char(RandomNumber(48, 57));

		case enCharType::MixChars:
			 return RandomCharacter((enCharType)RandomNumber(1, 3));

		default:
			return char(RandomNumber(65, 90));
		}

		return char(RandomNumber(65, 90));
	}

	static string GenerateWord(enCharType CharType, int Length)
	{
		string Word = "";

		for (int i = 1; i <= Length; i++)
		{
			Word += RandomCharacter(CharType);
		}

		return Word;
	}

	static string GenerateKey(enCharType CharType = CapitalLetter)
	{
		string Key = "";

		Key = GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4);

		return Key;
	}

	static void GenerateKeys(int TotalKeys, enCharType CharType = CapitalLetter)
	{
		for (int i = 1; i <= TotalKeys; i++)
		{
			cout << "Key [" << i << "] : " << GenerateKey(CharType) << "\n";
		}
	}

	template <typename T> void Swap(T& a, T& b)
	{
		T Temp = a;
		a = b;
		b = Temp;
	}

	static void FillArrayWithRandomNumbers(int arr[], int arrLength, int From, int To)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = RandomNumber(From, To);
		}
	}

	static void FillArrayWithOrderedNumbers(int arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = i + 1;
		}
	}

	static void FillArrayWithRandomWords(string arr[], int arrLength, enCharType CharType, int WordLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = GenerateWord(CharType, WordLength);
		}
	}
	 
	static void FillArrayWithRandomKeys(string arr[], int arrLength, enCharType CharType)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = GenerateKey(CharType);
		}
	}

	template <typename T> void Shuffle(T arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static string Tabs(short NumberOfTabs)
	{
		string Tab = "";

		for (short i = 1; i < NumberOfTabs; i++)
		{
			Tab += "\t";
		}

		return Tab;
	}

	static string Spaces(short NumberOfTabs)
	{
		string Space = "";

		for (short i = 1; i < NumberOfTabs; i++)
		{
			Space += " ";
		}

		return Space;
	}

	static void ResetScreen()
	{
		system("cls");
	}

	static string EncryptText(string Text, short EncryptionKey = 2)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}

		return Text;
	}

	static string DecryptText(string Text, short EncryptionKey = 2)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}

		return Text;
	}

	static string NumberToText(size_t Number)
	{
		if (Number <= 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string Array[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
				"Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
				"Sixteen", "Seventeen", "Eighteen", "Nineteen" };

			return Array[Number] + " ";
		}

		else if (Number >= 20 && Number <= 99)
		{
			string Array[] = { "", "", "Twenty", "Thirty", "Fouty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

			return Array[Number / 10] + " " + NumberToText(Number % 10);
		}

		else if (Number >= 100 && Number <= 199)
		{
			return "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return "One Billion " + NumberToText(Number % 1000000000);
		}

		if (Number >= 2000000000 && Number <= 999999999999)
		{
			return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}

		
		return "";
	}

};


