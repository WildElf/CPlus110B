// Assignment 5 - Eric Zimmerman
// sorting teams based on wins and two parallel arrays
#include <iostream>
#include <string>
using namespace std;

// function prototypes
void initializeArrays (string n[], int w[], int);
void sortData (string n[], int w[], int);
void displayData (string n[], int w[], int);

// **************************
// Main function
// **************************
int main()
{
	const int LEAGUE = 5;
	string teams[LEAGUE];
	int wins[LEAGUE];
	
	initializeArrays(teams,wins,LEAGUE);
	
	sortData(teams,wins,LEAGUE);
	
	displayData(teams,wins,LEAGUE);
	
}

// get teams and wins from user
// ****************************
void initializeArrays(string n[], int w[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Enter Team #" << i + 1 << ": ";
		cin >> n[i];
		
		cout << "Enter Team #" << i + 1 << "'s number of wins: ";
		cin >> w[i];
				 
	}
	
}

// sort winners to the top
// **************************
void sortData(string n[], int w[], int size)
{
	// variables for sorting logic
	bool sorted = false;
	int skipped, winHold;
	string teamHold;
	
	while (!sorted)
	{
		skipped = 0;
		for (int i = 1; i < size; i++)
		{
			if (w[i] > w[i-1])
			{
				// remember current elements
				winHold = w[i];
				teamHold = n[i];
				
				// copy earlier elements into current
				w[i] = w[i-1];
				n[i] = n[i-1];
				
				// place original elements in new positions
				w[i-1] = winHold;
				n[i-1] = teamHold;
				
			}
			else 
				skipped++;
		}
		
		if (skipped > size - 2)
			sorted = true;
	}
}

// display the teams and wins
// **************************
void displayData(string n[], int w[], int size)
{
	cout << "League Standings\n";

	for (int i = 0; i < size; i++)
	{
		cout << n[i] << " wins: " << w[i] << endl;
		
	}
}

/* Sample output
Enter Team #1: Waiters
Enter Team #1's number of wins: 32
Enter Team #2: Bellhops
Enter Team #2's number of wins: 35
Enter Team #3: Stewards
Enter Team #3's number of wins: 29
Enter Team #4: Maids
Enter Team #4's number of wins: 42
Enter Team #5: Footmen
Enter Team #5's number of wins: 30
League Standings
Maids wins: 42
Bellhops wins: 35
Waiters wins: 32
Footmen wins: 30
Stewards wins: 29
*/
