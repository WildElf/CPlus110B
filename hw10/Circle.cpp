// Circle class file
#include "Circle.h"
#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14;

// public set function X
void Circle::setX(double value)
{
	x = value;
}

// public set function Y
void Circle::setY(double value)
{
	y = value;
}

// public set function Radius
void Circle::setRadius(double r)
{
	if (r >= 0)
		radius = r;
	else 
		radius = -1 * r;
}

// get public value for X
double Circle::getX()
{
	return x;
}

// get public value for X
double Circle::getY()
{
	return y;
}

// get public value for Radius
double Circle::getRadius()
{
	return radius;
}

// get the circle's area
double Circle::getArea()
{
	return (radius * radius * PI);
}

// check the X, Y coordinates and return true if they are inside the circle
// a point on the edge of the circle is considered inside
// also display the distance from the point to the center (for validation and fun)
bool Circle::containsPoint(double xValue, double yValue)
{
	double side1 = x - xValue;
	double side2 = y - yValue;
	double distance = sqrt ( (side1 * side1) + (side2 * side2) );
	
	cout << "The point is " << distance << " from the circle center.\n";
	
	if (distance <= radius)
		return true;
	else
		return false;
}
