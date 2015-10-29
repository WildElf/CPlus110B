// Eric Zimmerman
// Week 11, Exercise A
// using the Rectangle class
#include <iostream>
#include "Rectangle.h"

using namespace std;

// ***************************************
// Main function using the Rectangle class
// ***************************************
int main()
{

	Rectangle kitchen;
	Rectangle bedroom(9, 8.5, "\"Master\" Bedroom");
	Rectangle livingroom(6.25, 12, "Living Room");
	
	kitchen.setWidth(7);
	kitchen.setLength(9.5);
	kitchen.setName("Kitchen");
	
	cout << "The area of the " << kitchen.getName() << " is " 
		<< kitchen.getArea() << " sq ft.\n";

	cout << "The area of the " << bedroom.getName() << " is " 
		<< bedroom.getArea() << " sq ft.\n";

	cout << "The area of the " << livingroom.getName() << " is " 
		<< livingroom.getArea() << " sq ft.\n";
		
	cout << "The area of the house is " 
		<< kitchen.getArea() +  bedroom.getArea() + livingroom.getArea()
		<< " sq ft.\n";
	
}