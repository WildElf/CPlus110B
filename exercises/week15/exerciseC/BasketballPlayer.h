// declaring class for exercise C, week 15
// derived class for basketball players
#ifndef BASKETBALLPLAYER_H
#define BASKETBALLPLAYER_H
#include "Player.h"
#include <iostream>
#include <string>

class BasketballPlayer : public Player
{ 
	private: 
		int fieldgoals;
		int attempts; 
	public: 
		BasketballPlayer(std::string n, double w, double h, int fg, int a) : Player(n, w, h) 
			{ fieldgoals = fg; attempts = a; } 
		void printStats() const 
		{	std::cout << name << std::endl; 
			std::cout << "Weight: " << weight; 
			std::cout << " Height: " << height << std::endl; 
			std::cout << "FG: " << fieldgoals; 
			std::cout << " attempts: " << attempts; 
			std::cout << " Pct: " << (double) fieldgoals / attempts << std::endl; } 
};

#endif