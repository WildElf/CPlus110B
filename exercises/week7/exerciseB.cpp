#include<iostream>
#include<string>

using namespace std;

// function prototype
void printReport(string*, int*, int);

int main()
{
	int numTypes;
	string* burritoNames = NULL;
	int* burritoSales = NULL;

	cout << "How many kinds of burrito today: ";
	cin >> numTypes;

	burritoNames = new string[numTypes];

	for (int i = 0; i < numTypes; i++)
	{
		cout << "What's the name of burrito " << i+1 << "? ";
		cin >> burritoNames[i];
	}

	cout << "\nReturn at end of day to\n";
	cout << "Enter the number of sales for each burrito:\n";

	burritoSales = new int[numTypes];

	for (int i = 0; i < numTypes; i++)
	{
		cout << burritoNames[i] << " sales: ";
		cin >> burritoSales[i];
	}

	printReport(burritoNames, burritoSales, numTypes);

	delete [] burritoNames;
	delete [] burritoSales;

	burritoNames = NULL;
	burritoSales = NULL;

}

void printReport(string *burritosPtr, int *salesPtr, int numTypes)
{
	cout << "\n\nSales Report\n";
	int total = 0;

	for (int i = 0; i < numTypes; i++)
	{
		cout << burritosPtr[i] << " sold " << salesPtr[i] << endl;

		total += salesPtr[i];
	}

	cout << "\n\nTotal Sales: " << total << endl;
}
