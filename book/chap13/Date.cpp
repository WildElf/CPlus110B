// Class implementation file
#include "Date.h"
#include <iostream>

using namespace std;

// public functions
void Date::setMonth(int mon)
{
	if (mon < 1)
		month = 1;
	else if (mon > 12)
		month = 12;
	else
		month = mon;
}

void Date::setDay(int d)
{
	if (d < 1)
		day = 1;
	else if (d > 31)
		day = 31;
	else
		day = d;
}

void Date::setYear(int yr)
{
	year = yr;
}

int Date::getYear()
{
	return year; 
}

int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}
