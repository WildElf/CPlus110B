// Assignment 4, Poker Hands - Eric Zimmerman
// Determines the poker hand from user input of card values
#include<iostream>
using namespace std;

// function prototypes
void pokerCheck();
bool playAgain();
void orderCards(int []);
bool containsPair(int []);
bool containsTwoPair(int []);
bool containsThreeOfaKind(int []);
bool containsStraight(int []);
bool containsFullHouse(int []);
bool containsFourOfaKind(int []);
bool containsFiveOfaKind(int []);

// Poker only has one hand size currently
const int HAND_SIZE = 5;

// MAIN function for easy replay
int main()
{
	do
	{
		pokerCheck();

	} while (playAgain());
}

// check multiple hands per run
// ****************************
bool playAgain()
{
	char again;
	
	cout << "Check another hand? (y/n) ";
	cin >> again; 
	
	if (again == 'y' || again == 'Y')
		return true;
	else
		return false;
}

// **************************************
// the primary function, called by main()
// **************************************
void pokerCheck()
{
	// initialize user's card hand array
	int cards[HAND_SIZE];
		
	// get new card values from the user
	for (int i = 0; i < HAND_SIZE; i++)
	{	

		do
		{	// validating each entry
			cout << "Enter the value for card " << i + 1 << " (2-9): ";
			cin >> cards[i];
			
			if (cards[i] < 2 || cards[i] > 9)
				cout << "Only values 2-9 are acceptable!\n";
		} while (cards[i] < 2 || cards[i] > 9);

	}
/*	
	// sorting the cards into order makes all the 'contain' functions easier to code
	orderCards(cards);
*/
	
	// test from "best" to worst
	if (containsFiveOfaKind(cards))
	{
		cout << "Looks like you might be cheating.\n";
	}
	else if (containsFourOfaKind(cards))
	{	
		cout << "Four of a kind!\n";
	}
	else if (containsFullHouse(cards))
	{
		cout << "Full house!\n";	
	}
	else if (containsStraight(cards))
	{
		cout << "Straight!\n";	
	}
	else if (containsThreeOfaKind(cards))
	{
		cout << "Three of a kind!\n";
	}
	else if (containsTwoPair(cards))
	{
		cout << "Two pair!\n";	
	}
	else if (containsPair(cards))
	{
		cout << "A pair!\n";	
	}
	else
	{
		cout << "High card.\n";
	}
	
}

// Put the cards in ascending order of value
// this makes card evaluation much easier
// *****************************************
void orderCards(int hand[])
{
	bool sorted = false;
	while (!sorted)
	{

		int hold, pass = 0;
		for (int i = 1; i < HAND_SIZE; i++)
		{
			// if this card is smaller, move it up an index
			if (hand[i] < hand[i-1])
			{
				// 1st card is set down
				hold = hand[i];
				// 2nd card moved to 1st
				hand[i] = hand[i-1];
				// Held card placed 2nd
				hand[i-1] = hold;
			}
			else 
				pass++;
	
		}

		// the pass counter only reaches 1 less of HAND_SIZE if all cards are sorted
		if (pass >= HAND_SIZE - 1)
			sorted = true;
	}
}

// checks to see if there is a matching pair
// *****************************************
bool containsPair (int hand[])
{
	bool match = false;
	int count = 0;
	
	while (!match && count < HAND_SIZE - 1)
	{
	
		for (int i = count+1; i < HAND_SIZE; i++)
		{
			if (hand[count] == hand[i])
				match = true;
		}
		
		count++;	
	}
			
	return match;
}

// checks for two matching pair
// *****************************************
bool containsTwoPair (int hand[])
{
	bool match = false;
	bool onePair = false;
	int holdSpot = 0;
	
	int count = 0;
	
	while (!onePair && count < HAND_SIZE - 1)
	{
	
		for (int i = count+1; i < HAND_SIZE; i++)
		{
			if (hand[count] == hand[i])
			{
				onePair = true;
				holdSpot = count;
			}
		}
		
		count++;	
	}
	
	count = holdSpot + 1;
	
	while (onePair && !match && count < HAND_SIZE - 1)
	{
		for (int i = count+1; i < HAND_SIZE; i++)
		{
			if (hand[count] == hand[i] && hand[count] != hand[holdSpot])
			{
				match = true;
			}
		}
		
		count++;	
	}

	return match;
}

// checks for three of a kind
// *****************************************
bool containsThreeOfaKind (int hand[])
{
	bool match = false;
	int pair = -1, count = 0;
	
	while (!match && count < HAND_SIZE -1)
	{
		
		for (int i = count + 1; i < HAND_SIZE; i++)
		{
			// checks for 3 cards of equal value
			if (hand[i] == hand[count] && pair < 0)
				pair = hand[count];
			else if (hand[i] == hand[count] && hand[i] == pair)
				match = true;
		}
		
		count++;
	}
	
	return match;
}

// BROKEN
// checks for a continuous sequence
// *****************************************
bool containsStraight (int hand[])
{
	bool straight1 = false, straight2 = false, 
		straight3 = false, straight4 = false;
	int lowest = hand[0];
	
	for (int i = 1; i < HAND_SIZE; i++)
	{
		if (lowest > hand[i])
			lowest = hand[i];
	}
	
	for (int i = 0; i < HAND_SIZE; i++)
	{

		if (lowest == hand[i] - 1)
			straight1 = true;
		else if (lowest == hand[i] - 2)
			straight2 = true;
		else if (lowest == hand[i] - 3)
			straight3 = true;
		else if (lowest == hand[i] - 4)
			straight4 = true;
										
	}
	
	if (straight1 && straight2 && straight3 && straight4)
		return true;
	else
		return false;
}

// BROKEN
// checks for a pair and three of a kind
// *****************************************
bool containsFullHouse (int hand[])
{
	bool match = false;
	bool full = false;
	bool house = false;

	// three of a kind check
	int pair = -1, triple = -1, count = 0;
	
	while (!match && count < HAND_SIZE - 1)
	{
		// determine if there's a pair
		for (int i = count + 1; i < HAND_SIZE; i++)
		{
			if (hand[count] == hand[i] && hand[count] == hand[pair])
			{
				house = true;
				cout << "Full house found 3 of a kind\n";
				triple = count;
			}
			else if ( hand[count] == hand[i] )
			{
				pair = count;
				cout << "Full house found a pair\n";
			}

		}
		
		cout << hand[pair] << " <- pair | triple -> " << hand[triple] << endl;
		// ensure the pair and 3oK don't match
		if (hand[pair] != hand[triple])
			full = true;
		
		count++;
	}
	
	if (full && house)
		match = true;
			
	return match;
}

// checks for a four of a kind
// *****************************************
bool containsFourOfaKind (int hand[])
{
	bool match = false;
	int pair = -1, triple = -1, count = 0;
	
	while (!match && count < HAND_SIZE -1)
	{
		
		for (int i = count + 1; i < HAND_SIZE; i++)
		{
			// checks for 3 cards of equal value
			if (hand[i] == hand[count] && pair < 0)
				pair = hand[count];
			else if (hand[i] == hand[count] && hand[i] == pair && triple < 0)
				triple = hand[count];
			else if (hand [i] == hand[count] && hand[i] == triple)
				match = true;
		}
		
		count++;
	}
	
	return match;
}

// checks for the user not entering a real hand
// ********************************************
bool containsFiveOfaKind (int hand[])
{
	bool match = false;
	
	for (int i = 0; i < (HAND_SIZE - 4); i++)
	{
		if (hand[i] == hand[i+1] && hand[i+1] == hand[i+2] 
		&& hand[i+2] == hand[i+3] && hand[i+3] == hand[i+4])
			match = true;
	}		
	return match;
}

/* Sample Output

Enter the value for card 1 (2-9): 4
Enter the value for card 2 (2-9): 8
Enter the value for card 3 (2-9): 2
Enter the value for card 4 (2-9): 6
Enter the value for card 5 (2-9): 7
High card.
Check another hand? (y/n) y
Enter the value for card 1 (2-9): 2
Enter the value for card 2 (2-9): 5
Enter the value for card 3 (2-9): 7
Enter the value for card 4 (2-9): 3
Enter the value for card 5 (2-9): 5
A pair!
Check another hand? (y/n) y
Enter the value for card 1 (2-9): 3
Enter the value for card 2 (2-9): 7
Enter the value for card 3 (2-9): 3
Enter the value for card 4 (2-9): 4
Enter the value for card 5 (2-9): 3
Three of a kind!
Check another hand? (y/n) y
Enter the value for card 1 (2-9): 7
Enter the value for card 2 (2-9): 4
Enter the value for card 3 (2-9): 4
Enter the value for card 4 (2-9): 8
Enter the value for card 5 (2-9): 7
Two pair!
Check another hand? (y/n) y
Enter the value for card 1 (2-9): 6
Enter the value for card 2 (2-9): 3
Enter the value for card 3 (2-9): 7
Enter the value for card 4 (2-9): 5
Enter the value for card 5 (2-9): 4
Straight!
Check another hand? (y/n) y
Enter the value for card 1 (2-9): 5
Enter the value for card 2 (2-9): 8
Enter the value for card 3 (2-9): 5
Enter the value for card 4 (2-9): 8
Enter the value for card 5 (2-9): 8
Full house!
Check another hand? (y/n) y
Enter the value for card 1 (2-9): 4
Enter the value for card 2 (2-9): 6
Enter the value for card 3 (2-9): 4
Enter the value for card 4 (2-9): 6
Enter the value for card 5 (2-9): 4
Full house!
Check another hand? (y/n) y
Enter the value for card 1 (2-9): 4
Enter the value for card 2 (2-9): 6
Enter the value for card 3 (2-9): 4
Enter the value for card 4 (2-9): 4
Enter the value for card 5 (2-9): 4
Four of a kind!
Check another hand? (y/n) y
Enter the value for card 1 (2-9): 8
Enter the value for card 2 (2-9): 8
Enter the value for card 3 (2-9): 8
Enter the value for card 4 (2-9): 8
Enter the value for card 5 (2-9): 8
Looks like you might be cheating.
Check another hand? (y/n) n

*/