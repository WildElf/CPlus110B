// implementation class file for Rectangle.h
#include "Rectangle.h"
#include "TestRect.h"
#include <iostream>
#include <cstring>

using namespace std;

double Rectangle::yardsAvail = 0;

// static member function
void Rectangle::setYards(double y)
{
	if (y > 0)
		yardsAvail = y;
	else
		cout << "Invalid yards: must be greater than Zero";

}

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
	else if (w == 0)
		cout << "Warning: zero width set";
	else
		width = -w;
	
	if (l > 0)
		length = l;
	else if (l == 0)
		cout << "Warning: zero length set";
	else
		length = -l;
			
	initName(n);
	
	double perim = getPerimeter();
	
	if (yardsAvail > perim)
		yardsAvail -= perim;
	else
	{
		cout << "Error: " << getName() << " is too large for initialized yards!\n";
		initName("Invalid Rectangle");
		width = 0;
		length = 0;
	}

}

// Deconstructor
Rectangle::~Rectangle()
{ 
	yardsAvail += width*2 + length*2;
	delete [] name; 
}

void Rectangle::initName(char *n)
{
	int charLen = strlen(n) + 1;
	name = new char[charLen];
	strcpy(name,n);
	
}

void Rectangle::setWidth(double w)
{
	yardsAvail += width*2 + length*2;
	
	if (w > 0)
		width = w;
	else
		width = -w;
	
	yardsAvail += width*2 + length*2;
}

void Rectangle::setLength(double l)
{	
	yardsAvail += width*2 + length*2;
	
	if (l > 0)
		length = l;
	else
		length = -l;

	yardsAvail -= width*2 + length*2;
}

void Rectangle::setWidth(char* w)
{
	yardsAvail += width*2 + length*2;

	double wide = atof(w);
	if (wide > 0)
		width = wide;
	else
		width = -wide;

	yardsAvail -= width*2 + length*2;
}

void Rectangle::setLength(char* l)
{	
	yardsAvail += width*2 + length*2;

	double leng = atof(l);
	if (leng > 0)
		length = leng;
	else
		length = -leng;

	yardsAvail -= width*2 + length*2;
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

Rectangle& Rectangle::operator=(Rectangle& obj)
{
	width = obj.width;
	length = obj.length;
	setName(obj.name);
	
	return obj;
}

bool Rectangle::operator<(const Rectangle& obj)
{
	if (getArea() < obj.getArea())
		return true;
	else
		return false;
}

bool Rectangle::operator>(const Rectangle& obj)
{
	if (getArea() > obj.getArea())
		return true;
	else
		return false;
}

bool Rectangle::operator==(const Rectangle& obj)
{
	if (getArea() == obj.getArea())
		return true;
	else
		return false;
}
