// header file for Population class
// Programming Challenge Chapter 13 #9 in C++ text book
#ifndef POPULATION_H
#define POPULATION_H

// Population class

class Population
{
	private:
		int population;
		int births;
		int deaths;
	public:
		Population(unsigned long p = 1, unsigned int b = 0, unsigned int d = 0);
		void setPopulation(unsigned long);
		void setBirths(unsigned int);
		void setDeaths(unsigned int);
		long getPopulation();
		int getBirths();
		int getDeaths();
		float getBirthRate();
		float getDeathRate();
};

#endif