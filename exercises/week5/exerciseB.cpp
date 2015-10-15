// Week 5, Exercise B - Eric Zimmerman
// Sorting and searching a list of names
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

// function prototypes
void arraySort(string[], int);
bool linearArraySearch(string[], string, int);
bool binaryArraySearch(string[], string, int);

int main()
{
	const int NAMES_LIST = 20;
	ifstream namesFile;
	string wantedPersons[NAMES_LIST], customerName;

	namesFile.open("names.txt");

	// read in data from file
	for (int i = 0; i < NAMES_LIST; i++)
		namesFile >> wantedPersons[i];

	// sort the array
	arraySort(wantedPersons, NAMES_LIST);

//	for (int i = 0; i < NAMES_LIST; i++)
//		cout << wantedPersons[i] << endl;

	cout << "Enter customer's last name: ";
	cin >> customerName;

/*	if (linearArraySearch(wantedPersons, customerName, NAMES_LIST))
		cout << customerName << " is on the wanted list! Security has been alerted.\n";
	else
		cout << "Proceed with the transaction...\n";
*/
	if (binaryArraySearch(wantedPersons, customerName, NAMES_LIST))
		cout << customerName << " is on the wanted list! Security has been alerted.\n";
	else
		cout << "Proceed with the transaction...\n";
	
}

void arraySort(string names[], int size)
{
	bool swapping;
	string hold;
	int count = 0;

	do
	{
		swapping = false;
	
		for (int i = 1; i < size; i++)
		{
			if (names[i-1] > names[i])
			{
				hold = names[i];
				names[i] = names[i-1];
				names[i-1] = hold;
				swapping = true;
			}
		}
	
	} while (swapping);

}

bool linearArraySearch(string names[], string customer, int size)
{
	bool wanted = false;

	for (int i = 0; i < size; i++)
	{
		if (names[i] == customer)
			wanted = true;
	}

	return wanted;
}

bool binaryArraySearch(string names[], string customer, int size)
{
	bool wanted = false;
	int min = 0, max = size, mid;

	while (!wanted && min <= max)
	{
		mid = (min+max) / 2;
		if (names[mid] == customer)
			wanted = true;
		else if (names[mid] > customer)
			max = mid -1;
		else
			min = mid +1;
	}

	return wanted;
}
