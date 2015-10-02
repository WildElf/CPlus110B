// League with DMA - Eric Zimmerman
// week 6 homework, part 2
// takes input for a baseball league with 
// a variable array, using dynamic memory allocation
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

// function prototypes
void initializeData(string n[], int s[], int size);
void sort(string n[], int s[], int size);
void display(string n[], int s[], int size);

// **************************
// Main function
// **************************
int main()
{
	int league;
	string* teamsptr = NULL;
	int* winsptr = NULL;

	cout << "How many teams are in the league? ";
	cin >> league;

	teamsptr = new string[league];
	winsptr = new int[league];
	
	initializeData(teamsptr,winsptr,league);
	
	sort(teamsptr,winsptr,league);
	
	display(teamsptr,winsptr,league);
	
	delete [] teamsptr;
	delete [] winsptr;
	
}

// get teams and wins from user
// ****************************
void initializeData(string n[], int s[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Enter Team #" << i + 1 << "'s name: ";
		cin >> n[i];
		
		cout << "Enter Team #" << i + 1 << "'s number of wins: ";
		cin >> s[i];
				 
	}
	
}

// sort winners to the top
// **************************
void sort(string n[], int s[], int size)
{
	// variables for selection sort logic
	int highest, winHold;
	string teamHold;

	
	// check for the highest through array
	for (int i = 0; i < size - 1; i++)
	{
		// assume position i is highest
		highest = i;
		
		// compare to rest of array
		for (int j = i+1; j < size; j++)
		{
			// update highest position if a higher value found
			if (s[j] > s[highest])
				highest = j;
				
		}
				
		// move highest element to position i, if not there already
		if (i != highest)
		{
			
			// hold position i value
			teamHold = n[i];
			winHold = s[i];
			
			// move highest to position i
			n[i] = n[highest];
			s[i] = s[highest];
			
			// put held values back into array
			n[highest] = teamHold;
			s[highest] = winHold;		
		}

	}
	
}


// display the teams and wins
// **************************
void display(string n[], int s[], int size)
{
	cout << "League Standings\n";

	for (int i = 0; i < size; i++)
		cout << n[i] << " wins: " << s[i] << endl;
		
}
