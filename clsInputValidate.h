#pragma once

#include <iostream>
//#include "clsDate.h"
#include "clsString.h"

using namespace std;

class clsInputValidate
{
public:
	
	template <typename T> static bool IsNumberBetween(T Number, T From, T To)
	{
		return (Number >= From && Number <= To);
	}

	template <typename T> static T ReadNumber(string ErrorMessage)
	{
		T Number = 0;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << ErrorMessage;
		}

		return Number;
	}

	template <typename T> static T ReadNumberbetween(T From, T To, string ErrorMessage)
	{
		T Number = 0;

		Number = ReadNumber<T>(ErrorMessage);

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadNumber<T>(ErrorMessage);
		}

		return Number;
	}

	static string ReadString()
	{
		string str;

		getline(cin >> ws, str);

		return str;
	}

};

