// Homework 02 - Eric Zimmerman
// Allows the user to play blackjack with an AI dealer
// and an infinite, perfectly shuffled deck

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
	// define input controls
	char hitMe, playAgain;

	//random number set up
	unsigned long seed = time(0);
	srand(seed);

	// initialize constants for game rules
	// randomizer goes 1-13 to include face cards
	// and MAX_VALUE normalizes card values, so nothing is higher than 10
	// aces are always 1
	const int LOW_CARD = 1;
	const int HIGH_CARD = 13;
	const int MAX_VALUE = 10;
	const int BLACKJACK = 21;
	const int DEALER_GO = 17;
		
	// do play at least one game
	do
	{
		// set up player variables, ensure reset from last game
		int card, score, cardsDrawn;
		card = score = cardsDrawn = 0;
		bool busted = false;

		//dealer variables, and ensure reset
		int dealerCard, dealerScore;
		dealerCard = dealerScore = 0;
	
		// game starts ...
		cout << "\n******************************\n"
			<< "Welcome to Blackjack Infinity, where card counting is impossible!\n"
			<< "******************************\n";

		// ... and the dealer draws one card
		card = (rand() % (HIGH_CARD - LOW_CARD + 1)) + LOW_CARD;
		if (card > MAX_VALUE)
			card = MAX_VALUE;
		cout << "The dealer's card is a " << card << ".\n";
		dealerScore += card;

		// draw the first two cards for player
		while (cardsDrawn < 2)
		{
			// pick a card, correct values, add to score tally
			card = (rand() % (HIGH_CARD - LOW_CARD + 1)) + LOW_CARD;
			if (card > MAX_VALUE)
				card = MAX_VALUE;
			score += card;
			cardsDrawn++;

			if (cardsDrawn == 1)
				{
					cout << "\nYour first cards: " << card << ", ";
				}

			if (cardsDrawn == 2)
				{
					cout << card << endl;
				}
		}

		// display score, check for bust before asking for next card
		cout << "Your score: " << score << endl;
		if (score < BLACKJACK)
			{
				cout << "Take another card? (y/n): ";
				cin >> hitMe;
			}
		else if (score == BLACKJACK)
		{
			cout << "You got Blackjack!\n";
			hitMe = 'n';
		}
		else
			busted = true;
			
		// begin hit me loop
		while (hitMe == 'y' && !busted)
		{
			card = (rand() % (HIGH_CARD - LOW_CARD + 1)) + LOW_CARD;
			if (card > MAX_VALUE)
				card = MAX_VALUE;

			cout << "Next card: " << card << endl;
			score += card;
		
			cout << "Your score: " << score << endl;

			if (score < BLACKJACK)
			{
				cout << "Take another card? (y/n): ";
				cin >> hitMe;
			}
			else if (score == BLACKJACK)
			{
				cout << "You got Blackjack!\n";
				hitMe = 'n';
			}
			else
				busted = true;
		}

		// if player busted, game over...
		if (busted)
		{	
			cout << "Bust! You lose.\n";				
		}
		// otherwise, if the player is done hitting, begin dealer's turn
		else if (hitMe == 'n')
		{
			cout << "Dealer's turn...\n";
			
			// dealer AI
			while (dealerScore < DEALER_GO)
			{
				char cont;
				
				// card logic is the same as player's	
				card = (rand() % (HIGH_CARD - LOW_CARD + 1)) + LOW_CARD;
				if (card > MAX_VALUE)
					card = MAX_VALUE;
			
				cout << "\nDealer draws: " << card << endl;
					
				dealerScore += card;
				cout << "The dealer's score is " << dealerScore << " to your score " << score << ". (enter c to continue) ";
				cin >> cont;
			}
			
			// display results
			if (dealerScore > BLACKJACK)
			{
				cout << "Dealer busts!\n";
				dealerScore = 0;
			}
			else
				cout << "Dealer holds.\n\n" 
					<< "You have " << score << " to the dealer's " 
								<< dealerScore << ".\n";
			
			// compare results to determine winner
			if (dealerScore < score)
				cout << "You win!\n";
			else if (dealerScore > score)
				cout << "Dealer wins.\n";
			else
				cout << "Push! No winner.\n";
		}

		cout << "Want to play again? (y/n): ";
		cin >> playAgain;

		
	} while (playAgain != 'n');


}
