// Fate Dice implementation class
#include "FateDice.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

FateDice::FateDice()
{
	seed = time(0);
	srand(seed);
	result = 0;
	
	roll();
}

void FateDice::roll()
{
	result = 0;
	
	for (int i = 0; i < DIE_POOL; i++)
	{
		dice[i] = (rand() % 3) - 1;
		result += dice[i];
	}
	
}

// rolls and returns the dice result
int FateDice::newRoll()
{
	roll();
	return result;
}

// returns a modified roll value
int FateDice::newRoll(int mod)
{
	roll();
	return result + mod;
}

int FateDice::getResult()
{
	return result;
}
