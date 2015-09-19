// Assignment 1: Eric Zimmerman
// This program prints out a number of asterisks based on user input.

#include<iostream>
using namespace std;

int main()
{

	int asterisks;
	char repeat = 'y';

	while (repeat != 'n')
	{
		cout << "Number of asterisks to print: ";
		cin >> asterisks;

		for (int i = asterisks; i > 0; i--)
		{
			cout << "*";
		}

		cout << "\nRun again? (y/n): ";
		cin >> repeat;
	}

}
