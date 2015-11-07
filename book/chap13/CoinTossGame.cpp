// Coin toss dollar game
#include "Coin.h"
#include <iostream>
#include <iomanip>

using namespace std;

int flip(string&, string&, string&);

int main()
{
	int cents = 0;
	double dollar = (float)cents;
	string coin1, coin2, coin3;
	
	cents = flip(coin1, coin2, coin3);
		
	if (cents == 100)
		cout << "Winner!\n";
	else
		cout << "Bust.\n";
}

int flip(string &coin25, string &coin10, string &coin5)
{
	Coin quarter, dime, nickle;
	int cents = 0;
	double dollar = (float)cents;

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
	
	return cents;
	
}