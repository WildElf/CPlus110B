// class implementation for week 14, exercise A
// stores a measurement in feet & inches
#include "FeetInches.h"

FeetInches::FeetInches()
{
	feet = inches = 0;
}

FeetInches::FeetInches(int f, int i)
{
	if (f >= 0)
		feet = f;
	else
		feet = -f;
	
	if (i < 0)
		i = -i;

	if ( i <= 12)
		inches = i;
	else
	{
		feet += i / 12;
		inches = i % 12;
	}
}

// if only a single double is passed, assume the value is in feet
FeetInches::FeetInches(double height)
{
	int h = height;
	feet = height;
	inches = (height - feet) * 12;
}

// if only a single int is passed, assume the value is in inches
FeetInches::FeetInches(int i)
{
	feet = i / 12;
	inches = i % 12;
}

int FeetInches::getFeet()
{
	return feet;
}

int FeetInches::getInches()
{
	return inches;
}

double FeetInches::getHeight()
{
	return feet + (inches/12);
}
