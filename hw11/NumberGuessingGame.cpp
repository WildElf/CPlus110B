// Assignment 10 - Eric Zimmerman
// Guesses a number the user is thinking of
// with (a) class!
#include <iostream>
#include "NumberGuesser.h"
using namespace std;

// Prototyped functions
void playOneGame ();
bool shouldPlayAgain ();
char getUserResponseToGuess(NumberGuesser);

/// Main program start, loop based on user choice
int main ()
{
	do
	{
		playOneGame();
	} while (shouldPlayAgain());

	return 0;
}

/// *********************************
/// The number guessing game function
/// *********************************
void playOneGame ()
{
	// variables for input
	int midpoint, lowpoint, highpoint;
	char choice;

	// Establish the starting number range
	const int LOW_RANGE = 1;
	const int HIGH_RANGE = 100;
	
	cout << "Think of a number between " << LOW_RANGE 
		<< " and " << HIGH_RANGE << ".\n";

	// build a guesser object
	NumberGuesser guessingGame(LOW_RANGE, HIGH_RANGE);

	// number guessing loop, runs at least once
	do
	{
		// get user response to the guess
		choice = getUserResponseToGuess(guessingGame);

		// adjust guessing range based on user response
		if (choice == 'h')
			guessingGame.higher();
		else if (choice == 'l')
			guessingGame.lower();
		else if (choice == 'c')
			cout << "Witness my psychic powers!\n";

	} while (choice != 'c'); // continue until 'c' for correct
	
	guessingGame.reset();
}

/// Show user the guess and get input
/// *********************************
char getUserResponseToGuess(NumberGuesser guess)
{
	char choice = 0;

	// ensure user enters appropriate response
	while (choice != 'h' && choice !='l' && choice !='c')
	{
		cout << "Is your number " << guess.getCurrentGuess() << "? ((h)igher/(l)ower/(c)orrect): ";
		cin >> choice;
		
		choice = tolower(choice);
		
		// validate user input
		if (choice != 'h' && choice != 'l' && choice != 'c' )
			cout << "I don't understand what you mean.\n"
				<< "Enter H if your number is higher than my guess,\n"
				<< "input L if your number is lower, and\n"
				<< "C if I got your number.\n";
	}

	return choice;
}

/// Checks to see if the user wants to repeat the game
/// **************************************************
bool shouldPlayAgain ()
{
	char playAgain;	

	cout << "Do you want to play again? (y/n): ";
	cin >> playAgain;

	if (playAgain == 'y' || playAgain == 'Y')
		return true;
	else
		return false;
}