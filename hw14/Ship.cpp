//
//  Ship.cpp
//  Battleship
//
//#include "PointCollection.h"
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
	// keeping origin unchanged, originPoint is available for utility
	if ( o == HORIZONTAL )
		for (int i=0; i<length; i++) {
			originPoint.setX(origin.getX() + i);
			points << originPoint;
		}
	else
		for (int i=0; i<length; i++) {
			originPoint.setY(origin.getY() + i);
			points << originPoint;
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
	if (points.contains(p))
		return true;
	else
		return false;
}

//*******************************************************************************************
// Collides With
//*******************************************************************************************

bool Ship::collidesWith(const Ship& s) const
{
	
	bool collision = false;
	
	for (int i=0; i<length; i++) 
	{
		if (s.containsPoint(points[i]))
		{
			collision = true;
		}
	}

	return collision;
}

//*******************************************************************************************
// Shot Fired At Point
//*******************************************************************************************

void Ship::shotFiredAtPoint(const point& p)
{
	if (points.contains(p))
	{
		hits << p;
	}
}

//*******************************************************************************************
// Is Hit At Point
//*******************************************************************************************

bool Ship::isHitAtPoint(const point& p)
{
	if (hits.contains(p))
		return true;
	else
		return false;
}

//*******************************************************************************************
// Hit Count
//*******************************************************************************************

int Ship::hitCount() const
{
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
	
	points = s.points;
	hits = s.hits;
	
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










