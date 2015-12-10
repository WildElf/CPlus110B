// Number guesser class implementation
#include "NumberGuesser.h"
#include <iostream>

// sets the upper and lower bounds of a potential guess
NumberGuesser::NumberGuesser(int low, int up)
{
	// we'll let users go ahead with the error of setting upper and lower as equal
	if (low <= up)
	{
		lowPoint = startLow = low;
		highPoint = startHigh = up;
	}
	else // ...but fix things if upper and lower are obviously reversed
	{
		lowPoint = startHigh = up;
		highPoint = startLow = low;
	}
	
	std::cout << "Number guesser constructed!\n";
}
