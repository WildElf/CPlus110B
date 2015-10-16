#include<iostream>
#include<string>
using namespace std;

int main()
{
	// initialize variables
	string homeTeam, visitTeam;

	bool homeLow = false, visitLow = false;

	int homeScore, visitScore;

	const int LOW_SCORE = 3;

	// User inputs home team and score
	// Flags for low score, if necessary
	cout << "Enter the home team name: ";
	cin >> homeTeam;

	cout << "Enter the home team\'s score: ";
	cin >> homeScore;
	if (homeScore < LOW_SCORE)
		homeLow = true;

	// User inputs visiting team and score
	// Flags for low score, if necessary
	cout << endl << "Enter the visiting team name: ";
	cin >> visitTeam;

	cout << "Enter the visiting teams\'s score: ";
	cin >> visitScore;
	if (visitScore < LOW_SCORE)
		visitLow = true;

	// check to see who won
	if (homeScore > visitScore)
		cout << endl << homeTeam << " won";
	else if (visitScore > homeScore)
		cout << endl << visitTeam << " won";
	else
		cout << endl << "It was a tie between " 
		<< homeTeam << " & " << visitTeam;

	// telling the user if the teams got low scores
	if (homeLow && !visitLow)
		cout << ", plus " << homeTeam << " had a low score!" << endl;
	else if (visitLow && !homeLow)
		cout << ", plus " << visitTeam << " had a low score!" << endl;
	else if (homeLow && visitLow)
		cout << ", plus both " << homeTeam << " & " << visitTeam 
		<< " had low scores. Ouch!" << endl;
	else
		cout << "." << endl;
}
