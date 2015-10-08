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

/* Sample Output

[ezimmer2@hills hw06]$ a.out 
How many teams are in the league? 3
Enter Team #1's name: Bears
Enter Team #1's number of wins: 1
Enter Team #2's name: Lions
Enter Team #2's number of wins: 13
Enter Team #3's name: Tigers
Enter Team #3's number of wins: 8
League Standings
Lions wins: 13
Tigers wins: 8
Bears wins: 1

[ezimmer2@hills hw06]$ a.out 
How many teams are in the league? 12
Enter Team #1's name: Gumps
Enter Team #1's number of wins: 18
Enter Team #2's name: Zombies
Enter Team #2's number of wins: 27
Enter Team #3's name: Gravies
Enter Team #3's number of wins: 31
Enter Team #4's name: Strawberries
Enter Team #4's number of wins: 15
Enter Team #5's name: Peppers
Enter Team #5's number of wins: 23
Enter Team #6's name: Bowies
Enter Team #6's number of wins: 72
Enter Team #7's name: Mars
Enter Team #7's number of wins: 50
Enter Team #8's name: Salts
Enter Team #8's number of wins: 23
Enter Team #9's name: Lifers
Enter Team #9's number of wins: 64
Enter Team #10's name: Landlords
Enter Team #10's number of wins: 3
Enter Team #11's name: Cranes
Enter Team #11's number of wins: 12
Enter Team #12's name: Hacksaws
Enter Team #12's number of wins: 44
League Standings
Bowies wins: 72
Lifers wins: 64
Mars wins: 50
Hacksaws wins: 44
Gravies wins: 31
Zombies wins: 27
Peppers wins: 23
Salts wins: 23
Gumps wins: 18
Strawberries wins: 15
Cranes wins: 12
Landlords wins: 3
[ezimmer2@hills hw06]$
*/