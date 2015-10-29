// Implementation for Die class
#include<ctime>
#include<cstdlib>
#include "Die.h"

Die::Die(int faces)
{
	seed = time(0);
	srand(seed);
	
	sides = faces;
	
	roll();
}

void Die::roll()
{
	value = (rand() % sides) + 1;
}
