// Implementation for the Population class file
#include <iostream>
#include "Population.h"

using namespace std;

// default constructor
Population::Population(unsigned long p, unsigned int b, unsigned int d)
{
	if (p < 1)
		population = 1;
	else
		population = p;
	births = b;
	deaths = d;
}

void Population::setPopulation(unsigned long p)
{
	if (p < 1)
		population = 1;
	else
		population = p;
}

void Population::setBirths(unsigned b)
{
	births = b;
}

void Population::setDeaths(unsigned d)
{
	deaths = d;
}

long Population::getPopulation()
{
	return population;
}

int Population::getBirths()
{
	return births;
}

int Population::getDeaths()
{
	return deaths;
}

float Population::getBirthRate()
{
	return ((float)births/population);
}

float Population::getDeathRate()
{
	return ((float)deaths/population);
}
