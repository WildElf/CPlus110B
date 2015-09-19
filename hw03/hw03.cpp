// Assignment 3 - Eric Zimmerman
// guesses the number user is thinking of

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Prototyped functions
void playOneGame ();
bool shouldPlayAgain ();
char getUserResponseToGuess(int);
int getMidpoint(int, int);
int getRandomMidpoint (int, int);
char guessMethodChoice();

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
	// variables for number guessing
	int midpoint, lowpoint, highpoint;
	char choice;

	// Establish starting number range
	const int LOW_RANGE = 1;
	const int HIGH_RANGE = 100;
	lowpoint = LOW_RANGE;
	highpoint = HIGH_RANGE;
	
	cout << "Think of a number between " << lowpoint 
		<< " and " << highpoint << ".\n";

	char guessMethod = guessMethodChoice();

	// number guessing loop, runs at least once
	do
	{
		// because guessMethod ensures only two choices,
		// we only need one if statement to determine which is which
		if (guessMethod == 's')			// get a number to guess
			midpoint = getMidpoint(lowpoint, highpoint);
		else							// guess a random number
			midpoint = getRandomMidpoint(lowpoint, highpoint);

		// get user response to the guess
		choice = getUserResponseToGuess(midpoint);

		// adjust guessing range based on user response
		if (choice == 'h')
			lowpoint = midpoint + 1;
		else if (choice == 'l')
			highpoint = midpoint - 1;
		else if (choice == 'c')
			cout << "Witness my psychic powers!\n";

	} while (choice != 'c'); // continue until 'c' for correct
}

/// Use known highest and lowest numbers
/// to get the midpoint for next guess
/// **********************************
int getMidpoint(int low, int high)
{
	int mid = (low + high) / 2;

	return mid;
}

/// Alternative to getMidpoint,
/// gets a random midpoint for next guess
/// ************************************
int getRandomMidpoint (int low, int high)
{
	// random number setup
	unsigned long seed = time(0);
	srand(seed);

	int mid = (rand() % (high - low + 1)) + low;

	return mid;
}

/// Show user the guess and get input
/// *********************************
char getUserResponseToGuess(int guess)
{
	char choice = 0;

	// ensure user enters appropriate response
	while (choice != 'h' && choice !='l' && choice !='c')
	{
		cout << "Is it " << guess << "? ((h)igher/(l)ower/(c)orrect): ";
		cin >> choice;
	
		// normalize user input
		if (choice == 'h' || choice == 'H')
			choice = 'h';
		else if (choice == 'l' || choice == 'L')
			choice = 'l';
		else if (choice == 'c' || choice == 'C')
			choice = 'c';
		else
			cout << "I don't understand what you want from me.\n"
			<< "Enter H if your number is higher than my guess,\n"
			<< "input L if your number is lower, and\n"
			<< "C if I got your number.\n";
	}

	return choice;
}

/// let the user pick 'default' or random guessing for extra credit
/// *****************************************************
char guessMethodChoice()
{
	char method = 'x';

	
	while (method != 's' && method != 'r')
	{
		cout << "Would you like me to guess (s)ystematically "
			<< "or (r)andomly? (s/r):";
		cin >> method;

		// normalize input and set return value if valid
		if (method == 's' || method == 'S')
			method = 's';
		else if (method == 'r' || method == 'R')
			method = 'r';
		else 
			cout << "I'm not familiar with that guessing technique.\n";
	}
	
	return method;

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

/*
Silica:desktop ez$ ./a.out 
Think of a number between 1 and 100.
Would you like me to guess (s)ystematically or (r)andomly? (s/r):s
Is it 50? ((h)igher/(l)ower/(c)orrect): h
Is it 75? ((h)igher/(l)ower/(c)orrect): l
Is it 62? ((h)igher/(l)ower/(c)orrect): h
Is it 68? ((h)igher/(l)ower/(c)orrect): l
Is it 65? ((h)igher/(l)ower/(c)orrect): h
Is it 66? ((h)igher/(l)ower/(c)orrect): h
Is it 67? ((h)igher/(l)ower/(c)orrect): c
Witness my psychic powers!
Do you want to play again? (y/n): y
Think of a number between 1 and 100.
Would you like me to guess (s)ystematically or (r)andomly? (s/r):s
Is it 50? ((h)igher/(l)ower/(c)orrect): l
Is it 25? ((h)igher/(l)ower/(c)orrect): l
Is it 12? ((h)igher/(l)ower/(c)orrect): h
Is it 18? ((h)igher/(l)ower/(c)orrect): l
Is it 15? ((h)igher/(l)ower/(c)orrect): l
Is it 13? ((h)igher/(l)ower/(c)orrect): c
Witness my psychic powers!
Do you want to play again? (y/n): y
Think of a number between 1 and 100.
Would you like me to guess (s)ystematically or (r)andomly? (s/r):r
Is it 4? ((h)igher/(l)ower/(c)orrect): h
Is it 45? ((h)igher/(l)ower/(c)orrect): h
Is it 52? ((h)igher/(l)ower/(c)orrect): h
Is it 100? ((h)igher/(l)ower/(c)orrect): l
Is it 82? ((h)igher/(l)ower/(c)orrect): l
Is it 72? ((h)igher/(l)ower/(c)orrect): l
Is it 59? ((h)igher/(l)ower/(c)orrect): h
Is it 63? ((h)igher/(l)ower/(c)orrect): h
Is it 66? ((h)igher/(l)ower/(c)orrect): h
Is it 70? ((h)igher/(l)ower/(c)orrect): l
Is it 69? ((h)igher/(l)ower/(c)orrect): l
Is it 67? ((h)igher/(l)ower/(c)orrect): c
Witness my psychic powers!
Do you want to play again? (y/n): y
Think of a number between 1 and 100.
Would you like me to guess (s)ystematically or (r)andomly? (s/r):r
Is it 16? ((h)igher/(l)ower/(c)orrect): l
Is it 13? ((h)igher/(l)ower/(c)orrect): c
Witness my psychic powers!
Do you want to play again? (y/n): n
Silica:desktop ez$ 

*/