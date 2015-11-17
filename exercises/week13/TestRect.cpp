#include "Rectangle.h"
#include "TestRect.h"

bool TestRect::tester(Rectangle &r)
{
	if (r.getWidth() > 0 && r.getLength() > 0)
		return true;
	else
		return false;
}

bool TestRect::enoughYards(double w, double l)
{
	double perim = w*2 + l*2;
	
	if ( Rectangle::yardsAvail - perim < 0)
		return false;
	else
		return true;
}
