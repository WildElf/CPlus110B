// Number guesser class implementation
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "RandomNumberGuesser.h"

// sets the upper and lower bounds of a potential guess
// generate an initial guess based on the starting bounds
RandomNumberGuesser::RandomNumberGuesser(int lowerBound, int upperBound) : NumberGuesser(lowerBound, upperBound)
{
	seed = time(0);
	srand(seed);
	
	check = (rand() % (highPoint - lowPoint + 1)) + lowPoint;
	
}

// return the midpoint between current high and low
// gets a new random guess only if highPoint or lowPoint have changed
int RandomNumberGuesser::getCurrentGuess()
{
	if (check < lowPoint || check > highPoint)
		check = (rand() % (highPoint - lowPoint + 1)) + lowPoint;

	return check;
}

void RandomNumberGuesser::reset()
{
	lowPoint = startLow; 
	highPoint = startHigh;
	
	check = (rand() % (highPoint - lowPoint + 1)) + lowPoint;

}