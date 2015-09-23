// Week 3, Exercise B - Eric Zimmerman
// Convert above freezing temperatures from F to C
#include <iostream>
using namespace std;

bool toCelsiusByReference(float&);

int main()
{
	// declaring temperature variables
	float temperature;

	cout << "What temperature, in F˚, to convert? :";
	cin >> temperature;

	if (toCelsiusByReference(temperature))
		cout << temperature << "˚ Celsius.\n";
	else
		cout << "I only convert temperatures freezing and warmer "
		<< "(that's 32˚F to you)\n";

}

bool toCelsiusByReference(float &temperature)
{
	if (temperature >= 32)
	{
		temperature = 5.0/9.0 * (temperature - 32);
		return true;
	}
	else
		return false;
}
