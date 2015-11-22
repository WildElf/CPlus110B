//
//  Ship.cpp
//  Battleship
//

#include "Ship.h"
#include <iostream>

/*
  private:
	int length;
	direction orientation;
	point origin;
	
	PointCollection points;
	PointCollection hits;

*/

//*******************************************************************************************
// Ship constructor
//*******************************************************************************************

Ship::Ship(point originPoint, direction o, int l) 
{
	// assign class variables
	origin = originPoint;
	orientation = o;
	length = l;
				
	// then translate the direction, advance direction and store
	// keeping origin as constant, originPoint is available for utility
	if ( o == HORIZONTAL )
		for (int i=0; i<l; i++) {
			originPoint.setX(origin.getX() + i);
			points[i] = originPoint;
		}
	else
		for (int i=1; i<l; i++) {
			originPoint.setY(origin.getY() + i);
			points[i] = originPoint;
		}


}

//*******************************************************************************************
//
//*******************************************************************************************

Ship::Ship(const Ship& s) 
{
	*this = s;
}

//*******************************************************************************************
// Contains Point
//*******************************************************************************************

bool Ship::containsPoint(const point& p) const
{   
	std::cout << "P contains: " << points.contains(p) << "\n";
	if (points.contains(p))
		std::cout << "Method search found p\n";
	else
		std::cout << "Method search did not find p\n";				
		
	for (int i=0; i<length; i++) {
		if (points[i] == p)
		{
			std::cout << "Manual search found p\n";
			return true;
		}

	}
	std::cout << "Manual search did not find p\n";			

	return false;
}

//*******************************************************************************************
// Collides With
//*******************************************************************************************

bool Ship::collidesWith(const Ship& s) const
{
	for (int i=0; i<length; i++) {
		for (int j=0; j<s.length; j++) {
			if (points[i] == s.points[j])
				return true;
			}
	}

	return false;
}

//*******************************************************************************************
// Shot Fired At Point
//*******************************************************************************************

void Ship::shotFiredAtPoint(const point& p)
{
	if (points.contains(p))
	{
		hits << p;
		std::cout << "Hit!\n";
	}
}

//*******************************************************************************************
// Is Hit At Point
//*******************************************************************************************

bool Ship::isHitAtPoint(const point& p)
{
	for (int i=0; i<length; i++)
		if (hits[i] == p)
			return true;

	return false;
}

//*******************************************************************************************
// Hit Count
//*******************************************************************************************

int Ship::hitCount() const
{
	std::cout << "Hits size: " << hits.getSize() << "\n";
	// why aren't method calls working for PointCollection?
	return hits.getSize();
}

//*******************************************************************************************
// Operator =
//*******************************************************************************************

const Ship& Ship::operator=(const Ship& s)
{
	length = s.length;
	orientation = s.orientation;
	origin = s.origin;
	
	for (int i=0; i<length; i++) {
		points[i] = s.points[i];
		hits[i] = s.hits[i];
	}
	
	return *this;
}


//*******************************************************************************************
//  Is Sunk
//*******************************************************************************************

bool Ship::isSunk() 
{
	if (hits.getSize() == length)
		return true;
	else
		return false;	
}











