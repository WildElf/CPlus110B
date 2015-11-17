// Week 13, Exercise B, overloaded operators
#include <iostream>
#include "Rectangle.h"

using namespace std;

int main()
{
	Rectangle::setYards(1000);
	
	Rectangle r1(10,12,"Two");
	Rectangle r2;
	r2 = r1;
	
	r1.setName("One");
	
	Rectangle r3(11,10,"Three");

	cout << "R1 is " << r1.getWidth() << " by " << r1.getLength() << " and called " << r1.getName() << endl;
	cout << "R2 is " << r2.getWidth() << " by " << r2.getLength() << " and called " << r2.getName() << endl;
	cout << "R3 is " << r3.getWidth() << " by " << r3.getLength() << " and called " << r3.getName() << endl;
	cout << endl;
	
	int counter = 0;
	do
	{
		if (counter > 0)
		{
			r1.setLength(9.9999);
			cout << "\nShrinking r1\n";
		}

		if (r1 == r2)
			cout << "r1 and r2 are the same\n";
		else if (r2 > r1)
			cout << "r2 is larger than r1\n";
				
		if (r1 > r3)
			cout << "r1 is larger than r3\n";
		else if (r1 < r3)
			cout << "r1 is smaller than r3\n";
			
		counter++;
		
	} while (r1 == r2);
	
	cout << "\nR1 is " << r1.getWidth() << " by " << r1.getLength() << " and called " << r1.getName() << endl;
	cout << "R2 is " << r2.getWidth() << " by " << r2.getLength() << " and called " << r2.getName() << endl;
	cout << "R3 is " << r3.getWidth() << " by " << r3.getLength() << " and called " << r3.getName() << endl;
	
}
