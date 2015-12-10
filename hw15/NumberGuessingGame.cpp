// Assignment 10 - Eric Zimmerman
// Guesses a number the user is thinking of
// with (a) class!
#include <iostream>
#include "NumberGuesser.h"
#include "RandomNumberGuesser.h"
using namespace std;

// Prototyped functions
void playOneGame (NumberGuesser&);
bool shouldPlayAgain ();
char getUserResponseToGuess(NumberGuesser&);

/// Main program start, loop based on user choice
int main ()
{
	// Establish the starting number range
	const int LOW_RANGE = 1;
	const int HIGH_RANGE = 10;

	// build a guesser object with the range
	NumberGuesser *ng = new RandomNumberGuesser(LOW_RANGE, HIGH_RANGE);
	
// picks a random number between 1 and 10, let’s say it is 3, and outputs it.

cout << ng->getCurrentGuess() << endl;

// this line prints out 3 again, because it is still the current guess

cout << ng->getCurrentGuess() << endl;

// this line changes low to 4 because we now know the number is higher than 3.

// high remains unchanged at 10.

if (ng->getCurrentGuess() < 4)
	ng->higher();
else
	ng->lower();

// this line picks a random number between 4 and 10 and prints it out,

// let’s say it is 9

cout << ng->getCurrentGuess() << endl;

// this line prints out 9 again, because it is still the current guess

cout << ng->getCurrentGuess() << endl;

/*	do
	{
		// display the range being used for user
		cout << "Think of a number between " << LOW_RANGE 
			<< " and " << HIGH_RANGE << ".\n";

		playOneGame(ng);
		
		ng.reset();

	} while (shouldPlayAgain());
*/
	return 0;
}

/// *********************************
/// The number guessing game function
/// *********************************
void playOneGame (NumberGuesser &guessingGame)
{

	// variable for input
	char choice;

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
			cout << "Witness my psychic methods!\n";

	} while (choice != 'c'); // continue until 'c' for correct

}

/// Show user the guess and get input
/// *********************************
char getUserResponseToGuess(NumberGuesser &guess)
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

	// normalize input, tolower() seemed less efficient
	if (playAgain == 'y' || playAgain == 'Y')
		return true;
	else
		return false;
}