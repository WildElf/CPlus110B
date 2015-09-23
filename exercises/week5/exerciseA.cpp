// Week 5, Exercise A - Eric Zimmerman
// checks a file for stolen credit cards
#include <iostream>
#include <fstream>
#include <string>
#include<cstdlib>

using namespace std;

// function prototype
bool linearCreditCheck (const long cards[], long card, int size);
bool binaryCreditCheck (const long cards[], long card, int size);

int main()
{
	// declaring variables
	const int STOLEN_CARDS = 20;
	long int creditCards[STOLEN_CARDS], creditCheck;
	ifstream stolenList;
//	string fileName = "cards.txt";

	// preparing file data to fill the array
	stolenList.open("cards.txt");

	if (!stolenList)
	{
		cout << "ERROR: source file not found!\n";
		exit(1);
	}	

	// read in the file to the array
	for (int i = 0; i < STOLEN_CARDS; i++)
	{
		stolenList >> creditCards[i];
	}

	// ask the user for a credit card to use
	do
	{
		cout << "Enter Credit Card Number: ";
		cin >> creditCheck;

		if (creditCheck > 999999 || creditCheck < 100000)
			cout << "ERROR: Invalid credit card entered.\n";

	} while (creditCheck > 999999 || creditCheck < 100000);

//	bool stolen = linearCreditCheck(creditCards, creditCheck, STOLEN_CARDS);

	bool stolen = binaryCreditCheck(creditCards, creditCheck, STOLEN_CARDS);
	
	if (stolen)
		cout << "The credit card has been reported stolen!\n\n";
	else
		cout << "The credit card appears to be valid. Ready to process.\n\n";
}

// check compare credit card entered to stolen cards
bool linearCreditCheck (const long cards[], long card, int size)
{
	int index = 0;
	bool isStolen = false;

	while (!isStolen && index < size)
	{
		if (cards[index] == card)
			isStolen = true;
		index++;
	}
	
	return isStolen;
}

// using a binary check to search for stolen cards
bool binaryCreditCheck (const long cards[], long card, int size)
{
	int low = 0, high = size - 1, middle;
	bool isStolen = false;

	while (!isStolen && low <= high)
	{
		middle = (low + high) / 2;
		if (cards[middle] == card)
			isStolen = true;
		else if (cards[middle] > card)
			high = middle - 1;
		else
			low = middle + 1;
	}
	
	return isStolen;
}
