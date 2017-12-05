// DateClass.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Date.h"
#include <iostream>

using namespace std;

int main()
{
	Date	date01;					// create with default constructor
	Date	date02(24, 33, 93);		// invalid month and day values
	Date	date03(9, 17, -51);		// invalid year value
	Date	date04(12, 25, 14);		// 2000 year range - 2014
	Date	date05(10, 31, 31);		// 1900 year range - 1931
	Date	date06(4, 31, 11);		// invalid day value for April
	Date	date07(2, 29, 3);		// 2003 is not a leap year
	Date	date08(2, 29, 1900);	// 1900 is not a leap year
	Date	date09(2, 29, 2000);	// 2000 is a leap year
	Date*	date10;					// pointer to Date class type

	cout << endl;

	date01.displayDate();
	date02.displayDate();
	date03.displayDate();
	date04.displayDate();
	date05.displayDate();
	date06.displayDate();
	date07.displayDate();
	date08.displayDate();
	date09.displayDate();

	date10 = new Date(2, 29, 2004);	// create new instance of Date class
	date10->displayDate();			// display function for class referenced with class pointer ->

	date01.setDate(2, 29, 12);
	date01.displayDate();

	date01.setDate(2, 29, 11);
	date01.displayDate();

	date01.setDate(11, 30, 14);
	date01.displayDate();

	cout << endl;
	system("pause");
	return 0;
}