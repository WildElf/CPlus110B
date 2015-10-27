// Number guesser class implementation
#include "NumberGuesser.h"

// sets the upper and lower bounds of a potential guess
NumberGuesser::NumberGuesser(int lowerBound, int upperBound)
{
	// we'll let users go ahead with the error of setting upper and lower as equal
	if (lowerBound <= upperBound)
	{
		lowPoint = startLow = lowerBound;
		highPoint = startHigh = upperBound;
	}
	else // ...but fix things if upper and lower are obviously reversed
	{
		lowPoint = startHigh = upperBound;
		highPoint = startLow = lowerBound;
	}	
}

// if input says the number is higher
void NumberGuesser::higher()
{
	// raise the low point of guessing
	lowPoint = getCurrentGuess() + 1;
}

// if input says the number is lower
void NumberGuesser::lower()
{
	// lower the high point of guessing
	highPoint = getCurrentGuess() - 1;
}

// return the midpoint between current high and low
int NumberGuesser::getCurrentGuess()
{
	return ((lowPoint + highPoint)/2);
}

// reset the object variables to initial construction states
void NumberGuesser::reset()
{
	lowPoint = startLow;
	highPoint = startHigh;
}
