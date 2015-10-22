// Week 10 Homework - Eric Zimmerman
// Using a simple Circle class to create objects
#include <iostream>
#include "Circle.h"

using namespace std;

int main ()
{
	// declare variables to create the circle
	double circleX, circleY, circleRadius;
	
	// create a circle defined by the user
	cout << "\nFirst, create a circle.\n";
	cout << "Enter the X center coordinate: ";
	cin >> circleX;
	
	cout << "Enter the Y center coordinate: ";
	cin >> circleY;
	
	cout << "Enter the radius: ";
	cin >> circleRadius;
	
	cout << "The area of this circle should be " << circleRadius * circleRadius * 3.14 << endl;
	
	// build a circle object with entered values
	Circle circle1;
	
	circle1.setX(circleX);
	circle1.setY(circleY);
	circle1.setRadius(circleRadius);

	cout << "The circle is made at (" << circle1.getX() << ", " << circle1.getY() 
		<< "), and a radius of " << circle1.getRadius() << endl;
	cout << "The area of the circle is " << circle1.getArea() << endl;
	
	// set a circle pointer
	Circle* circlePtr = &circle1;
	
	// modify circle values using the pointer
	cout << "\nNow we'll change the circle values using pointers.\n";
	cout << "Enter the new X coordinates: ";
	cin >> circleX;	
	circlePtr->setX(circleX);

	cout << "Enter the new Y coordinate: ";
	cin >> circleY;
	circlePtr->setY(circleY);
	
	cout << "Enter the new radius: ";
	cin >> circleRadius;
	circlePtr->setRadius(circleRadius);

	cout << "Using pointers, the circle is now at (" << circlePtr->getX() << ", " << circlePtr->getY() 
		<< ") with a radius of " << circlePtr->getRadius() << endl;
	cout << "The area of the circle is now " << circlePtr->getArea() << endl;
			
	// declare variables for point testing
	double testX, testY;
	bool checkPoint = true;
	char testAgain;
	
	while (checkPoint)
	{
		cout << "\nEnter the X coordinate to test: ";
		cin >> testX;
	
		cout << "Enter the Y coordinate to test: ";
		cin >> testY;
	
		// check the point using the Circle class method
		bool insidePoint = circlePtr->containsPoint(testX, testY);
	
		if (insidePoint)
			cout << "The point is inside the circle.\n";
		else
			cout << "The point is outside the circle.\n";
			
		cout << "Test another point? (y/n) ";
		cin >> testAgain;
		
		if (tolower(testAgain) == 'n')
			checkPoint = false;
		else
			cout << "Checking another point...";
	}
}


