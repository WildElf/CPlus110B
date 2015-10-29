// implementation class file for Rectangle.h
#include "Rectangle.h"
#include <iostream>
#include <cstring>

using namespace std;

// default constructor
Rectangle::Rectangle()
{
	width = 1.0;
	length = 1.0;
	name = new char[17];
	strcpy(name, "Cupboard Bedroom");
}

// parameter constructor
Rectangle::Rectangle(double w, double l, char *n)
{
	if (w > 0)
		width = w;
	else
		width = -w;
	
	if (l > 0)
		length = l;
	else
		length = -l;
	
	name = new char[strlen(n) + 1];
	strcpy(name, n);
}

// Deconstructor called in header

void Rectangle::setWidth(double w)
{
	if (w > 0)
		width = w;
	else
		width = -w;
}

void Rectangle::setLength(double l)
{	
	if (l > 0)
		length = l;
	else
		length = -l;
}

void Rectangle::setName(char *n)
{
	delete [] name;
	name = new char[strlen(n) + 1];
	strcpy(name,n);
}

char* Rectangle::getName() const
{
	return name;
}


double Rectangle::getWidth() const
{
	return width;
}

double Rectangle::getLength() const
{
	return length;
}

double Rectangle::getArea() const
{
	return width * length;
}

double Rectangle::getPerimeter() const
{
	return (width * 2) + (length * 2);
}

bool Rectangle::isSquare() const
{
	if (width == length)
		return true;
	else
		return false;
}