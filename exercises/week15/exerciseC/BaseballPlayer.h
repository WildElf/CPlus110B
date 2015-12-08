// declaring class for exercise C, week 15
// derived class for baseball players
#ifndef BASEBALLPLAYER_H
#define BASEBALLPLAYER_H
#include "Player.h"
#include <iostream>
#include <string>

class BaseballPlayer : public Player
{ 
	private: 
		int atBats;
		int hits; 
	public:
		BaseballPlayer(std::string n, double w, double h, int hit, int aB) : Player(n, w, h) 
			{ hits = hit; atBats = aB; } 
		void printStats() const 
		{	std::cout << name << std::endl; 
			std::cout << "Weight: " << weight; 
			std::cout << " Height: " << height << std::endl; 
			std::cout << "At Bats: " << atBats; 
			std::cout << " Hits: " << hits; 
			std::cout << " Hit Average: " << (double) hits / atBats << std::endl; }
};

#endif