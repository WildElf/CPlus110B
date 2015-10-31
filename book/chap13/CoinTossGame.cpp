// Coin toss dollar game
#include "Coin.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	Coin quarter, dime, nickle;
	int cents = 0;
	double dollar = (float)cents;
	string coin25, coin10, coin5;
		
	while (dollar < 1.00)
	{
		cout << "Flip!\n";
		
		quarter.toss();
		dime.toss();
		nickle.toss();
		
		coin25 = quarter.getSideUp();
		coin10 = dime.getSideUp();
		coin5 = nickle.getSideUp();
		
		cout << "Quarter: " << coin25 << "; Dime: " 
			<< coin10 << "; Nickle: " << coin5 << endl;
		
		if (coin25 == "heads")
			cents += 25;
		if (coin10 == "heads")
			cents += 10;
		if (coin5 == "heads")
			cents += 5;
		
		dollar = cents/100.0;
		
		cout.precision(2);
		
		cout << "Your total: $" << fixed << dollar << endl << endl;
		
	}
	
	if (cents == 100)
		cout << "Winner!\n";
	else
		cout << "Bust.\n";
}