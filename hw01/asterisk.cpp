// Assignment 1: Eric Zimmerman
// This program prints out a number of asterisks based on user input.

#include<iostream>
using namespace std;

int main()
{

	// prep variables needed for output and looping
	int asterisks;
	char repeat = 'y';

	// Loop support to allow user to go again.
	// anything other than 'y' will end exit.
	while (repeat == 'y')
	{
		cout << "\nNumber of asterisks to print: ";
		cin >> asterisks;

		for (int i = asterisks; i > 0; i--)
		{
			cout << "*";
		}

		cout << "\nRun again? (y/n): ";
		cin >> repeat;
	}

}
