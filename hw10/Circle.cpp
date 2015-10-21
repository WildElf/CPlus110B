// Circle class file
#include "Circle.h"
#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14;

void Circle::setX(double value)
{
	x = value;
}

void Circle::setY(double value)
{
	y = value;
}

void Circle::setRadius(double r)
{
	if (r >= 0)
		radius = r;
	else 
		radius = -1 * r;
}

double Circle::getRadius()
{
	return radius;
}

double Circle::getX()
{
	return x;
}

double Circle::getY()
{
	return y;
}

double Circle::getArea()
{
	return (radius * radius * PI);
}

bool Circle::containsPoint(double xValue, double yValue)
{
	double side1 = x - xValue;
	double side2 = y - yValue;
	double distance = sqrt ( (pow (side1, 2.0)) + (pow (side2, 2.0)) );
	
	if (distance < radius)
		return true;
	else
		return false;
}
