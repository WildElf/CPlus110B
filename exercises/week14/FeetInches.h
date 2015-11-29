// class declaration for exercise A, week 14
// stores feet & inches measurement
#ifndef FEET_INCHES_H
#define FEET_INCHES_H

class FeetInches
{
	private:
		int feet;
		int inches;
	public:
		FeetInches();
		FeetInches(int, int);
		FeetInches(double);
		FeetInches(int);
		int getFeet();
		int getInches();
		operator double();

};

#endif
