#include<iostream>
using namespace std;

int main()
{
	// initialize variables
	int homeScore, awayScore;
	char repeat;	

	do {
		cout << "Enter home team score: ";
		cin >> homeScore;

		cout << "\nEnter away team's score: ";
		cin >> awayScore;
	
		cout << "Home team's score: " << homeScore << endl;
		cout << "Away team's score: " << awayScore << endl;

		if (homeScore > awayScore)
			cout << "The home team beat the away team.\n\n";
		else if (awayScore > homeScore)
			cout << "The away team was victorious.\n\n";
		else if (homeScore == awayScore)
			cout << "The game ended in a draw.\n\n";

		cout << "Do you want to enter scores for another game? (y/n): ";
		cin >> repeat;

	} while (repeat == 'y');
}
