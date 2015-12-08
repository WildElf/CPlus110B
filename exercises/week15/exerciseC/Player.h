// declaring class for exercise C, week 15
// abstract player class for sporting players
#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player
{
	protected: 
		std::string name;
		double weight; 
		double height;
	public: 
		Player(std::string n, double w, double h) 
			{ name = n; weight = w; height = h; } 
		virtual void printStats() const = 0;

};

#endif
