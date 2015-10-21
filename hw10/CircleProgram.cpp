// Week 10 Homework - Eric Zimmerman
// Using a simple Circle class to create objects
#include <iostream>
#include "Circle.h"

using namespace std;

int main ()
{
	// declare variables to create the circle
	double circleX, circleY, circleRadius;
	
	cout << "First, create a circle.\n";
	cout << "Enter the X center coordinate: ";
	cin >> circleX;
	
	cout << "Enter the Y center coordinate: ";
	cin >> circleY;
	
	cout << "Enter the radius: ";
	cin >> circleRadius;
	
	// build a circle object with entered values
	Circle circle1;
	
	circle1.setX(circleX);
	circle1.setY(circleY);
	circle1.setRadius(circleRadius);
	
	cout << "The circle is made at " << circle1.getX() << " by " << circle1.getY() 
		<< ", and a radius of " << circle1.getRadius() << endl;
	cout << "The area of the circle is " << circle1.getArea() << endl;
	
	// compare area to calculated area
	double localArea = circle1.getRadius() * circle1.getRadius() * 3.14;
	cout << "The area should be " << localArea << endl;
	
	// declare variables to get a point to test
	double testX, testY;
	
	cout << "\nEnter the X coordinate to test: ";
	cin >> testX;
	
	cout << "Enter the Y coordinate to test: ";
	cin >> testY;
	
	// check the point using the Circle class method
	bool insidePoint = circle1.containsPoint(testX, testY);
	
	if (insidePoint)
		cout << "The point is inside the circle.\n";
	else
		cout << "The point is outside the circle.\n";
}