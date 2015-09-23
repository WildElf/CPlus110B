// Week 3, Exercise A - Eric Zimmerman
// Converting Fahrenheit to Celcius using functions
#include <iostream>
#include <iomanip>
using namespace std;
float toCelsius(float);

int main()
{
	float C, F;	
	cout.setf(ios::fixed, ios::floatfield);

	cout << "  F    C  \n";
	cout << "----------\n";
	for (F = 60; F <= 90; F++)
	{
//		F = (float)i;
		C = toCelsius(F);
		cout << setprecision(0) << " " << F << "   " 
			<< setprecision(1) << C << endl;
	}
}

float toCelsius(float f)
{
	return (5.0/9.0 * (f - 32));
}
