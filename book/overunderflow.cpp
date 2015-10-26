// Experiments with overflow and underflow.
#include<iostream>
using namespace std;

int main()
{
	cout << "Short: " << sizeof(short) << " bytes.\n";
	cout << "Int: " << sizeof(int) << " bytes.\n";
	cout << "Long: " << sizeof(long) << " bytes.\n";
	cout << "Float: " << sizeof(float) << " bytes.\n";
	cout << "Double Float: " << sizeof(double) << " bytes.\n";
	cout << "String: " << sizeof(string) << " bytes.\n";

	// testVar set to the max short value (hopefully)
	short testVar = 32767;

	// Confirm its value to terminal
	cout << testVar << endl;

	// Overflow
	testVar = testVar + 1;
	cout << testVar << endl;

	// Underflow
	testVar = testVar -1;
	cout << testVar << endl;
	
}
