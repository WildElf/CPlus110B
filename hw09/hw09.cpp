// League with Structs - Eric Zimmerman
// week 9 homework
// takes input for a baseball league with 
// structs for a single complex array
#include<iostream>
#include<cstring>
using namespace std;

// global input c-string limit
const int INPUT_SIZE = 128;

// stores a name of a team along with # of wins
struct winRecord
{
	int wins;
	char *name;
};

// function prototypes
void initializeData(winRecord *standings, int size);
void sortData(winRecord *standings, int size);
void displayData(winRecord *standings, int size);
char* teamName();

// **************************
// Main function
// **************************
int main()
{
	// initialize variables
	int league;
	winRecord* teamsptr;

	cout << "How many teams are in the league? ";
	cin >> league;
	
	// dynamic array for the league size
	teamsptr = new winRecord[league];
		
	// gets team name and wins from user
	initializeData(teamsptr, league);
		
	// sorts teams by most wins to least
	sortData(teamsptr, league);
	
	// displays the sorted league
	displayData(teamsptr, league);

	// clean up
	for (int i=0; i<league; i++)
		delete [] teamsptr[i].name;
	delete [] teamsptr;
	teamsptr = NULL;

	return 0;
}

// get teams and wins from user
// ****************************
void initializeData(winRecord* standings, int size)
{
	// clear input from getting the league size
	cin.ignore(INPUT_SIZE, '\n');
	
	for (int i = 0; i < size; i++)
	{
		// get the team name
		cout << "Enter Team #" << i + 1 << "'s name: ";
		standings[i].name = teamName();

		// get the number of wins
		cout << "Enter Team #" << i + 1 << "'s number of wins: ";
		cin >> standings[i].wins;

		// clear input for the next loop
		cin.ignore(INPUT_SIZE, '\n');
	}
	
}

// sort winners to the top
// **************************
void sortData(winRecord* standings, int size)
{
	// variables for selection sort logic
	int highest;
	winRecord holder;

	// check for the highest through array
	for (int i = 0; i < size - 1; i++)
	{
		// assume position i is highest
		highest = i;
		
		// compare to rest of array
		for (int j = i+1; j < size; j++)
		{
			// update highest position if a higher value found
			if (standings[j].wins > standings[highest].wins)
				highest = j;
				
		}
				
		// move highest element to position i, if not there already
		if (i != highest)
		{
			
			// hold position i value
			holder = standings[i];
			
			// move highest to position i
			standings[i] = standings[highest];
			
			// put held values back into array
			standings[highest] = holder;
		}

	}
	
}


// display the teams and wins
// **************************
void displayData(winRecord* standings, int size)
{
	cout << "League Standings\n";

	for (int i = 0; i < size; i++)
		cout << standings[i].name << " wins: " << standings[i].wins << endl;
		
}

// get a team name from user input
// *******************************
char* teamName()
{
	// use the global input limit
	char input[INPUT_SIZE];
	char* thisTeam;

	cin.getline(input, INPUT_SIZE);
	
	// create an efficient c-string
	int teamChar = strlen(input) + 1;		
	thisTeam = new char[teamChar];
	strncpy(thisTeam, input, teamChar);
		
	return thisTeam;
	
}

// attempted clean up function
// NULL point did not carry over
/*
void cleanData(winRecord* standings, int size)
{
	for (int i=0; i<size; i++)
		delete [] standings[i].name;
	delete [] standings;
	standings = NULL;

}

/* sample output

*/
