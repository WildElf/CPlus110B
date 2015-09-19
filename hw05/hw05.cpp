// Assignment 5 - Eric Zimmerman
// sorting teams based on wins and two parallel arrays
#include <iostream>
#include <string>
using namespace std;

// function prototypes
void initializeArrays (string n[], int s[], int);
void sortData (string n[], int s[], int);
void displayData (string n[], int s[], int);

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
void initializeArrays(string n[], int s[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Enter Team #" << i + 1 << ": ";
		cin >> n[i];
		
		cout << "Enter Team #" << i + 1 << "'s number of wins: ";
		cin >> s[i];
				 
	}
	
}

// sort winners to the top
// **************************
void sortData(string n[], int s[], int size)
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
			if (s[i-1] < s[i])
			{
				// remember current elements
				winHold = s[i];
				teamHold = n[i];
				
				// copy earlier elements into current
				s[i] = s[i-1];
				n[1] = n[i-1];
				
				// place original elements in new positions
				s[i-1] = winHold;
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
void displayData(string n[], int s[], int size)
{
	cout << "League Standings\n";

	for (int i = 0; i < size; i++)
	{
		cout << n[i] << " wins: " << s[i] << endl;
		
	}
}

/*
Silica:desktop ez$ a.out 
Enter Team #1: Bats
Enter Team #1's number of wins: 79
Enter Team #2: Gravies
Enter Team #2's number of wins: 88
Enter Team #3: Skunks
Enter Team #3's number of wins: 67 
Enter Team #4: Turkeys
Enter Team #4's number of wins: 99
Enter Team #5: Cranberries
Enter Team #5's number of wins: 120
League Standings
Cranberries wins: 120
Turkeys wins: 99
Cranberries wins: 88
Cranberries wins: 79
Cranberries wins: 67
Silica:desktop ez$ a.out 
Enter Team #1: Waiters
Enter Team #1's number of wins: 34
Enter Team #2: Stewards
Enter Team #2's number of wins: 32
Enter Team #3: Bellhops
Enter Team #3's number of wins: 65
Enter Team #4: Chauffers
Enter Team #4's number of wins: 45
Enter Team #5: Maids
Enter Team #5's number of wins: 62
League Standings
Chauffers wins: 65
Maids wins: 62
Maids wins: 45
Maids wins: 34
Maids wins: 32
Silica:desktop ez$ 
*/
