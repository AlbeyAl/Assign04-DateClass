#pragma once

#include "stdafx.h"
#include "Date.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void Date::setDate(int mm, int dd, int yyyy)
{
	Date::month = mm;
	Date::day = day;
	Date::year = yyyy;

	if (!Date::validDate())
	{
		cout << "ERROR: " << mm << ", " << dd << ", " << yyyy << endl << endl;
	}
}

void Date::setDefaultDate()
{
	Date::month = 01;
	Date::day = 01;
	Date::year = 1970;
}

int Date::getMonth() const
{
	return Date::month;
}

int Date::getDay() const
{
	return Date::day;
}

int Date::getYear() const
{
	return Date::year;
}

void Date::displayDate() const
{
	cout << right << setw(2) << Date::month << '/' << right << setw(2) << Date::day << '/' << right << setw(4) << Date::year << endl;
}

bool Date::validMonth() const
{
	bool result = true;

	if (Date::month < 1 || Date::month > 12)
	{
		result = false;
	}

	return result;
}

bool Date::validDay() const
{
	bool result = true;
	int d = Date::day;

	if (Date::validMonth())
	{
		switch (Date::month)
		{
		/* 
			January,
			March,
			May,
			July,
			August,
			October,
			and December have 1-31 days;
		*/
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (d < 1 || d > 31)
				result = false;
			else
				result = true;
			break;

		// February 1-28 days on non-leap years, 1-29 on leap years;
		case 2:
			if (Date::isLeapYear())
			{
				if (d < 1 || d > 29)
					result = false;
				else
					result = true;
			}
			else
			{
				if (d < 1 || d > 28)
					result = false;
				else
					result = true;
			}
			break;

		/*
			April,
			June,
			September,
			and November have 1-30 days;
		*/
		case 4:
		case 6:
		case 9:
		case 11:
			if (d < 1 || d > 30)
				result = false;
			else
				result = true;
			break;

		}
	}
	else
		result = false;

	return result;
}

bool Date::validYear()
{
	bool result = true;
	int y = Date::year;

	if (y < 0)
		result = false;

	if (y < 100)
	{
		if (y >= 0 && y <= 30)
			Date::year += 2000;
		else
			Date::year += 1900;
	}

	return result;
}

bool Date::validDate()
{
	bool result = true;

	if (!Date::validMonth())
		cout << "ERROR: invalid month;" << endl;

	if (!Date::validDay())
		cout << "ERROR: invalid day;" << endl;
	
	if (!Date::validYear())
		cout << "ERROR: invalid year;" << endl;

	if (Date::validMonth() && Date::validDay() && Date::validYear())
		result = true;
	else
	{
		result = false;
		Date::setDefaultDate();
	}

	return result;
}

bool Date::isLeapYear() const
{
	bool result = false;

	if (Date::year % 4 == 0)
	{
		if (Date::year % 100 == 0)
		{
			if (Date::year % 400 == 0)
			{
				result = true;
			}
			else
			{
				result = false;
			}
		}
		else
		{
			result = true;
		}
	}
	else
	{
		result = false;
	}
	
	return result;
}

Date::Date()
{
	Date::setDefaultDate();
}

Date::Date(int mm, int dd, int yyyy)
{
	Date::setDate(mm, dd, yyyy);
}