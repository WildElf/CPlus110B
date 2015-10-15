// Week4 Exercise A - Taqueria Totals
// Eric Zimmerman
#include <iostream>
using namespace std;

int main ()
{
	// initialize arrays
	string burritoType[4] = {"carintas", "beef", "shrimp", "vegetarian"};
	int burritoSold[4];

	// utility variable for totals and best seller
	int totalSales = 0;
	int bestSeller = 0;
	int highestSales = 0;

	
	// user input loop
	for (int i = 0; i < 4; i++)
	{
		// getting user input
		cout << "How many " << burritoType[i] << " burritos were sold? ";
		cin >> burritoSold[i];

		totalSales += burritoSold[i];
		
		if (burritoSold[i] > highestSales)
		{
			bestSeller = i;
			highestSales = burritoSold[i];
		}
	}

	cout << "Total sales today: " << totalSales << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "The " << burritoType[i] << " burrito sold: " 
			<< burritoSold[i] << endl;
		
	}
	cout << "The best selling burrito was the " << burritoType[bestSeller] << endl;


}
