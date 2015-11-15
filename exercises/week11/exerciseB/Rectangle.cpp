// implementation class file for Rectangle.h
#include "Rectangle.h"
#include <iostream>
#include <cstring>

using namespace std;

// default constructor
Rectangle::Rectangle()
{
	width = 0;
	length = 0;
	initName("Empty");
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
	
	initName(n);
}

void Rectangle::initName(char *n)
{
	int charLen = strlen(n) + 1;
	name = new char[charLen];
	strcpy(name,n);
	
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

void Rectangle::setWidth(char* w)
{
	double wide = atof(w);
	if (wide > 0)
		width = wide;
	else
		width = -wide;
}

void Rectangle::setLength(char* l)
{	
	double leng = atof(l);
	if (leng > 0)
		length = leng;
	else
		length = -leng;
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