// Week 11 Exercise B - Eric Zimmerman
#include <iostream>
#include "Rectangle.h"

using namespace std;

int main()
{
	Rectangle house[3];
	char input[128];
	
	// get user input
	for (int i = 0; i < 3; i++)
	{
		cout << "What is the name of room " << i+1 << "? ";
		cin.getline(input,128);
		house[i].setName(input);
		
		cout << "What is the width of " << house[i].getName() << "? ";
		cin.getline(input,128);
		house[i].setWidth(input);
		
		cout << "What is the length of " << house[i].getName() << "? ";
		cin.getline(input,128);
		house[i].setLength(input);
		
		
	}
	
	// output room areas and largest room
	int largest = 0;
	for (int i = 0; i<3; i++)
	{
		cout << house[i].getName() << " area: " << house[i].getArea() << endl;
		
		if (house[i].getArea() > house[largest].getArea())
			largest = i;

	}
	
	cout << "The largest room is " << house[largest].getName() << ".\n";	
}