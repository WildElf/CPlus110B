//
//  Board.h
//  Battleship
//

#ifndef BOARD_H
#define BOARD_H
#include "Ship.h"
#include "PointCollection.h"
#include <iostream>

// needs variables for board dimensions (could use one to force squares, but let's be flexible)
// a variable to store the number of ships, plus an array for the ships

class Board
{
	private:
		// The ship array for computer's ships. Four pointers to ships
		Ship *ships[4];
		// and player's ships
		Ship *playerShips[4];

		// A PointCollection to store shots missed
		PointCollection misses;
		PointCollection computerMisses;

		// A helper method that generates a ship object with
		// the given length, and a random origin and orientation.
		// The ship is placed such that it fits on the board,
		// i.e. a HORIZONTAL ship at origin (9,1) and length 4
		// cannot be placed on the board.  Additionally, the
		// ship is placed such that it does not collide with
		// any other ships on the board.
		Ship* generateShipWithLength(int);

	public:
		Board();
		~Board();
		bool fireShot(int, int);
		bool computerFireShot();
		int unsunkShipCount();
		int unsunkPlayerCount();
		void display();


};

#endif

/*
	private:
		int width;
		int height;
		int numShips;
		
		// storing the characters for making the board
		char ship;
		char water;
		char hit;
		char miss;

		Ship* ships;
		PointsCollection sea; // might be unnecessary
		PointsCollection shots; // might be useful to store all shots, to block repeat moves
		
		displayBoard(); // no need for functions to decide this, this will be called because of the results of class actions
		void shotFiredAtPoint(point&);
		bool isSea(point&) const;
		bool isShip(point&) const;
		
	public:
		Board();
		~Board();
		point playerTurn(int, int);
*/
