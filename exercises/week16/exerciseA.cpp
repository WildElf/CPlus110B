// week 16, exercise A
// playing with vectors
#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

int main()
{
	int numPlaying;
	vector<string> players;
	
	cout << "How many people are playing? ";
	cin >> numPlaying;
	cin.ignore();
	
	for (int i = 0; i < numPlaying; i++)
	{
		players.push_back("");
		
		cout << "What is the name of Player #" << i + 1 << "? ";
		getline(cin, players[i]);
	}
	
	if (players.empty())
	{
		cout << "Did we run out of players?\n";
	}
	else
	{
		sort(players.begin(),players.end());
		
		cout << "The player roster today: \n";
		for (string name : players)
			cout << "*" << name << "*";
		
		cout << endl << endl;
				
		
		cout << "Today's seating arrangement is: \n";
		
		srand(time(0));
		random_shuffle(players.begin(),players.end());
		for (int i = 0; i < players.size(); i++)
		{
			cout << players[i] << " is in Chair #" << i + 1 << "!\n";
		}
		
		cout << "\nGood luck to our players, let Life and Death Poker begin!\n";
	}
}