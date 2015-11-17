// Week 13, Exercise A class testing program
#include <iostream>
#include "Rectangle.h"
#include "TestRect.h"

using namespace std;

int main()
{
	Rectangle::setYards(0);
	
	Rectangle badR(30,40,"Perfect Yard");
	TestRect tr;
	
	Rectangle::setYards(80);

	Rectangle byHalf(10,10,"Halfy");
	
	if (tr.enoughYards(20,20))
		cout << "You could make another 20x20 rectangle.\n";
	else
		cout << "Not enough room.\n";
	
	Rectangle halfOfHalf(5,5,"Quartermain");
	
	if (tr.enoughYards(20,20))
		cout << "You could make another 20x20 rectangle.\n";
	else if (tr.enoughYards(10,10))
		cout << "You could make another 10x10 rectangle.\n";
	else if (tr.enoughYards(5,5))
		cout << "You could make another 5x5 rectangle.\n";

}
