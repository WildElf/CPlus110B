// week 15, exercise C
// working with abstract classes
// and pure virtual functions
#include "Player.h"
#include "BasketballPlayer.h"
#include "BaseballPlayer.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Player* thatGuy = NULL;
	BaseballPlayer countBasey("Gary Busey", 190, 6.1, 138, 315);
	BasketballPlayer basketWeaver("Bugs Bunny", 14, 2.4, 999, 1000);
	
	thatGuy = &countBasey;
	thatGuy->printStats();
	
	thatGuy = &basketWeaver;
	thatGuy->printStats();	
	
}