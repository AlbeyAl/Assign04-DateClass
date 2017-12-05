#pragma once

class Date
{
public:									// public member functions
	Date();									// default constructor (no parameters)
	Date(int, int, int);					// constructor with month day year parameters - check for validity

	void	setDate(int mm, int dd, int yyyy);
	void	Date::setDefaultDate();		// set month day year values to default date ( 1/01/1970)

	int		getMonth()		const;			// return current month value
	int		getDay()		const;			// return current day   value
	int		getYear()		const;			// return current 4-digit year value

	void	displayDate()	const;			// display current date  value in mm/dd/yyyy format

private:								// private data members
	bool	validMonth()	const;			// check for valid month range
	bool	validDay()		const;			// check for valid day   range
	bool	validYear();					// check for valid year  value (must be >= zero)
	bool	validDate();				    // check for valid month, day, and year
	bool	isLeapYear()	const;			// Added function to determine if year is a leap year - Alex Crossley

	int		month;							// current month value
	int		day;							// current day   value
	int		year;							// current year  value
};