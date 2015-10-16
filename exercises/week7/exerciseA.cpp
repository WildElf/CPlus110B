#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int main()
{
	string names[] = {"Carnitas", "Pollo", "Veggie"};
	float prices[] = {6.95, 6.25, 5.95};

	string* stgr = names;
	float* fltr = prices;

	for (int i = 0; i < 3; i++)
	{
		*stgr += " Especial";
		*fltr += 1.00;

		stgr++;
		fltr++;
	}

//	stgr = names;
//	fltr = prices;

	cout << "**************************************\n";
	cout << "*Taqueria Programación BRAND NEW Menu*\n";
	cout << "**************************************\n";

	for (int i = 0; i < 3; i++)
	{
		string color = "";
/*		if (i = 0)
			color = "\x1b[31m";
		else if (i = 1)
			color = "\x1b[1;37m";
		else
			color = "\x1b[0;32m";
*/
		cout.fill(' ');
		cout << "  " << color << setw(17) << *(names + i);
		cout.fill('.');
		cout << setw(10) << *(prices + i) << endl;

	}

	cout << "\x1b[0m";
}
