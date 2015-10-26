#include<iostream>
using namespace std;

int main()
{
	float spin = 2.0e38, test, spun = 2.0e-38;

	// Trigger an overflow
	test = spin * 1000;
	cout << "An overflow gives: " << test << endl;

	//Trigger an underflow
	test = spun / spin;
	cout << "An underflow shows: " << test << endl;

	// Is it really zero?
	test = test * spin * 2;
	cout << "Zero means lost data: " << test << endl;

	// Can inf be manipulated?
	float infunity = spin;
	cout << infunity << endl;

	infunity *= 1000;
	cout << infunity << endl;

	infunity *= 0.0000001;
	cout << "Is " << infunity << " less than " << spin 
	<< "? It should be\n";

	infunity *= 0;
	cout << "This should be zero: " << infunity << endl;
}

