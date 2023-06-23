// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Programmer: Saeed Lahmdi

#include <iostream>
#include "clsUtil.h"
#include "clsMainScreen.h"

using namespace std;

int main()
{
    clsUtil::Srand();

    clsMainScreen::ShowMainScreen();

    return 0;
}
