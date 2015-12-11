//
//  Board.cpp
//  Battleship
//

#include "Board.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

//*******************************************************************************************
//  Ship making helper function
//*******************************************************************************************
Ship* Board::generateShipWithLength(int l)
{
	int originX, originY;
	int facing = rand() % 2;
	
	direction orientation;
	
	// determine valid ship origin based on direction
	if (facing == 0) // horizontal facing
	{
		orientation = HORIZONTAL;
	
		do
		{
			originX = rand() % 10;			

		} while (originX + l > 9);
	
		originY = rand() % 10;

	}
	else // vertical facing
	{
		orientation = VERTICAL;
	
		do
		{
			originY = rand() % 10;

		} while (originY + l > 9);

		originX = rand() % 10;

	}
	
//	cout << "Ship good at " << originX << ", " << originY << " facing " << facing << " Length: " << l << "!\n";
	
	point originPoint(originX, originY);
	
	return new Ship(originPoint, orientation, l);
}

//*******************************************************************************************
//  Constructor: mainly clean up ships
//*******************************************************************************************
Board::~Board()
{
	for (int i = 3; i >= 0; i--)
		delete ships[i];
}

//*******************************************************************************************
//  Constructor: mainly create ships
//*******************************************************************************************
Board::Board()
{
	bool collision = true;
	
	srand(time(0));
	
	// generate computer ships
	ships[0] = generateShipWithLength(5);
	
	while (collision)
	{
		ships[1] = generateShipWithLength(4);
			
		if (!ships[1]->collidesWith(*ships[0]))
			collision = false;
		else
			delete ships[1];
	}
	// reset for next loop
	collision = true;
	
	while (collision)
	{
		ships[2] = generateShipWithLength(3);

		if (!ships[2]->collidesWith(*ships[0]) && !ships[2]->collidesWith(*ships[1]))
			collision = false;
		else
			delete ships[2];
	} 
	// reset for next loop
	collision = true;
	
	while (collision)
	{
		ships[3] = generateShipWithLength(2);

		if (!ships[3]->collidesWith(*ships[0]) && !ships[3]->collidesWith(*ships[1]) &&
		!ships[3]->collidesWith(*ships[2]))
			collision = false;
		else
			delete ships[3];

	} 
	// while loops make sure subsequent ships don't collide with previous
	
	// repeat for player ships	
	playerShips[0] = generateShipWithLength(5);
	
	do
	{
		playerShips[1] = generateShipWithLength(4);
			
	} while (playerShips[1]->collidesWith(*playerShips[0]));
	
	do
	{
		playerShips[2] = generateShipWithLength(3);
	} while (playerShips[2]->collidesWith(*playerShips[0]) || playerShips[2]->collidesWith(*playerShips[1]));

	do
	{
		playerShips[3] = generateShipWithLength(2);
	} while (playerShips[3]->collidesWith(*playerShips[0]) || playerShips[3]->collidesWith(*playerShips[1]) ||
		playerShips[3]->collidesWith(*playerShips[2]));
	

}

//*******************************************************************************************
//  Fire Shot for player's turn
//*******************************************************************************************
bool Board::fireShot(int x, int y)
{
	point shot(x,y);
	bool hit = false;
	bool ship = false;
		
	for (int i = 0; i < 4; i++)
	{
		if (ships[i]->containsPoint(shot))
		{
			ship = true;
			
			if (!ships[i]->isHitAtPoint(shot))
			{
				ships[i]->shotFiredAtPoint(shot);
				hit = true;
				
			}
			else // context sensitive failed shot report
				cout << "The ship has already been hit there!\n";
		}

	}
	
	if (misses.contains(shot)) // context sensitive failed shot report
		cout << "You've already fired at that location. ";
	else if (!ship)
	{
		misses << shot;
		cout << "Missed!\n"; // context sensitive failed shot report
	}

	
	return hit;
}

//*******************************************************************************************
//  Fire Shot for the computer's turn
//*******************************************************************************************
bool Board::computerFireShot()
{
	bool hit = false;
	bool hitAlready = false;
	int x, y;
	point shot;
	
	do
	{
		x = rand() % 10;
		y = rand() % 10;
		
		shot.setX(x);
		shot.setY(y);
		
		for (int i = 0; i < 4; i++)
		{
			if (playerShips[i]->isHitAtPoint(shot))
				hitAlready = true;
		}
		
	} while (computerMisses.contains(shot) && !hitAlready);
	
	for (int i = 0; i < 4; i++)
	{
		if (playerShips[i]->containsPoint(shot))
		{
			
			if (!playerShips[i]->isHitAtPoint(shot))
			{
				playerShips[i]->shotFiredAtPoint(shot);
				hit = true;
				
			}
		}
	}
	
	if (!hit && !computerMisses.contains(shot))
	{
		computerMisses << shot;
		
	}
	
	return hit;

}

//*******************************************************************************************
// Returns the number of computer ships that have not yet been sunk
//*******************************************************************************************
int Board::unsunkShipCount()
{
	int count = 4;
	
	for (int i = 0; i < 4; i++)
		if (ships[i]->isSunk())
			count--;
			
	return count;
}

//*******************************************************************************************
// Returns the number of player ships that have not yet been sunk
//*******************************************************************************************
int Board::unsunkPlayerCount()
{
	int count = 4;
	
	for (int i = 0; i < 4; i++)
		if (playerShips[i]->isSunk())
			count--;
			
	return count;
}

//*******************************************************************************************
// Draws a grid display showing hits, misses and empty squares
//*******************************************************************************************
void Board::display()
{
	cout << "-************- NEW TURN -************-\n";
	
	char sea = '~';
	char ship = 'O';
	char hit = '@';
	char miss = '.';
	
	// start at the top of Y axis
	for (int y = 9; y >= 0; y--)
	{
		// start with Y coordinate for player
		cout << y << " ";
		
		// write x coordinates @ y for player
		for (int x = 0; x < 10; x++)
		{
			point thisPoint(x,y);

			// check for ships @ x,y
			if (ships[0]->containsPoint(thisPoint) || ships[1]->containsPoint(thisPoint) || 
				ships[2]->containsPoint(thisPoint) || ships[3]->containsPoint(thisPoint))
			{
				// check for hit ships
				if (ships[0]->isHitAtPoint(thisPoint) || ships[1]->isHitAtPoint(thisPoint) || 
				ships[2]->isHitAtPoint(thisPoint) || ships[3]->isHitAtPoint(thisPoint))
					cout << hit;
				else // keep ship hidden
					cout << sea;
			}
			else if (misses.contains(thisPoint))
				cout << miss;
			else
				cout << sea;
			
			// for squareness of the board
			cout << " ";
		}
		
		// y coordinate for computer board
		cout << "    " << y << " ";
		
		// write x coordinates @ y for computer
		for (int x = 0; x < 10; x++)
		{
			point thisPoint(x,y);

			// check for ships @ x,y
			if (playerShips[0]->containsPoint(thisPoint) || playerShips[1]->containsPoint(thisPoint) || 
				playerShips[2]->containsPoint(thisPoint) || playerShips[3]->containsPoint(thisPoint))
			{
				// check for hit ships
				if (playerShips[0]->isHitAtPoint(thisPoint) || playerShips[1]->isHitAtPoint(thisPoint) || 
				playerShips[2]->isHitAtPoint(thisPoint) || playerShips[3]->isHitAtPoint(thisPoint))
					cout << hit;
				else // show player their ships
					cout << ship;
			}
			else if (computerMisses.contains(thisPoint))
				cout << miss;
			else
				cout << sea;
			
			// for squareness of the board
			cout << " ";
		}

		
		// prepare for new Y line
		cout << endl;
	}
	
	// write X numerical coordinates
	
	cout << "  ";
	for (int x = 0; x <= 9; x++) // for player's side
		cout << x << " ";

	cout << "    ";
		
	for (int x = 0; x <= 9; x++) // for computer's side
		cout << x << " ";

	cout << endl;
}