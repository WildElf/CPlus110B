// Coin class implementation file
#include "Coin.h"
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

Coin::Coin()
{
	seed = time(0);
	srand(seed);
	
	toss();
	sideUp = getSideUp();
}

void Coin::toss()
{
	int coinToss = (rand() % 2);
	
	if (coinToss == 0)
		sideUp = "heads";
	else
		sideUp = "tails";
}
