// Assignment 13 - Eric Zimmerman
// Class copy constructors and overloaded operators
#include <iostream>
#include "IntCollection.h"

using namespace std;

int main()
{
	IntCollection c;
	
	// use the class << operator
	c << 42 << 10 << -360 << 77 << -5 << 21 << 420 << 99;

	// prove the operator worked properly
	for (int i = 0; i < c.getSize(); i++)
		cout << "C: " << c.get(i) << ", ";
	cout << "end of C.\n";
	
	// create two new objects
	IntCollection d, e;
	
	// give one some data
	e << 37 << 100 << -13;
	
	// prove again the << operator works
	for (int i = 0; i < e.getSize(); i++)
		cout << "E: " << e.get(i) << ", ";
	cout << "end of E.\n";
	
	// demonstrate the == operator
	if (c == e)
		cout << "C equals E!\n";
	else
		cout << "C does not equal E.\n";
	
	// demonstrate the = operator, copying our first object into the new ones
	e = d = c;
	
	// demonstrate the == operator's success
	if (c == e)
		cout << "Now C equals E!\n";
	else
		cout << "C still does not equal E!\n";

	// prove the data has been copied
	for (int i = 0; i < e.getSize(); i++)
	{
		cout << "C: " << c.get(i) << ", ";
		cout << "D: " << d.get(i) << ", ";
		cout << "E: " << e.get(i) << endl;
	}

	// try it all again, with a new object that has new data
	IntCollection x;
	
	x << 10 << 20 << 30 << 40 << 50 << 60 << 75 << 100 << 150 << 200;
	
	d = c = x;
	
	// c has just changed
	if (c == e)
		cout << "C still equals E!\n";
	else
		cout << "C no longer equals E!\n";
		
	if (x == e)
		cout << "X equals E.\n";
	else if (x == d)
		cout << "X equals D.\n";

	// E hold's C's original values
	for (int i=0; i<e.getSize(); i++)
		cout << "E: " << e.get(i) << ", ";
	cout << "end of E.\n";
	
	// show the trio's same data
	for (int i = 0; i < d.getSize(); i++)
	{
		cout << "C: " << c.get(i) << ", ";
		cout << "D: " << d.get(i) << ", ";
		cout << "X: " << x.get(i) << endl;
	}
	
	// break things up a bit
	d << 67;

	// show the bonus != operator working
	if (x != d)
	{
		cout << "X does not equal D.\n";
		cout << "Last of X: " << x.get(x.getSize()-1) << endl;		
		cout << "Last of D: " << d.get(d.getSize()-1) << endl;
	}
	else
		cout << "X equals D somehow!\n";
}

