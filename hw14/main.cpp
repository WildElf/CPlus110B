// week 16, Battleship Part II: Not the Movie
// execute a 1-player battleship game, with computer opponent
// using multiple classes
#include "PointCollection.h"
#include "Ship.h"
#include "Board.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

bool playGame();
bool validString(string);

int main() 
{
	// simple replay loop based on user choice
	while(playGame());
}

bool playGame()
{
	Board gameBoard;
	string target;
	
	// the main game loop, continues while both sides have ships
	while (gameBoard.unsunkShipCount() > 0 && gameBoard.unsunkPlayerCount() > 0)
	{
		// compare variable for changes in sunk ships
		int playerSunk = gameBoard.unsunkShipCount();
		int computerSunk = gameBoard.unsunkPlayerCount();
		
		// player target holding variables
		int x, y;
		
		// draw the board then ask for coordinates
		gameBoard.display();
		cout << "Enter coordinates to strike (X Y)\n";
		getline(cin, target);
		
		do
		{
			// validate the string entered
			if (validString(target))
			{
				x = atoi(&target[0]);
				y = atoi(&target[2]);

				if(gameBoard.fireShot(x, y))
				{
					cout << "Hit!\n";
				
					// check if the hit was also a sink
					if (playerSunk > gameBoard.unsunkShipCount())
						cout << "You sank the ship!\n";
				}
				else
					cout << "Better luck next time.\n";
			}
			else
				cout << "Invalid format. Enter X Y coordinates with a space in between, e.g.: 5 5\n";
				
			
		} while (!validString(target));
					
		cout << "********** Computer's Turn **********\n";
		cout << "Computer is taking a turn...\n";
			
		if (gameBoard.computerFireShot())
		{
			cout << "The computer hit!\n";
			
			if (computerSunk > gameBoard.unsunkPlayerCount())
				cout << "Your ship was sunk!\n";
		}
		else
			cout << "And missed. Your ships are safe, for now...\n";
	}
	
	if (gameBoard.unsunkShipCount() == 0)
		cout << "You win! You sunk the computer's last ship.";
	else if (gameBoard.unsunkPlayerCount() == 0)
		cout << "The computer has destroyed your fleet. You lost.";
	
	// asking for another game
	bool playAgain = false;
	string answer;
	
	cout << "Do you want to play again? (y/n)";
	getline(cin, answer);
	
	if (tolower(answer[0]) == 'y')
		playAgain = true;
	
	return playAgain;
}

bool validString(string s)
{	
	if (isdigit(s[0]) && isdigit(s[2]))
		return true;
	else
		return false;
}


