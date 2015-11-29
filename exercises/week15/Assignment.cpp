// week 15, exercise A
// derived class implementation
#include "Assignment.h"
#include <iostream>

void Assignment::set(int f,int e,int s)
{
	int error = 0;
	
	if (f >= 0 && f <=50)
		functionality = f;
	else
	{
		error++;
		std::cout << "Error: functionality must be between 0 and 50.\n";
	}
		
	if (e >= 0 && e <= 25)
		efficiency = e;
	else
	{
		error++;
		std::cout << "Error: efficiency must be between 0 and 25.\n";
	}
	
	if (s >= 0 && s <= 25)
		style = s;
	else
	{
		error++;
		std::cout << "Error: style must be between 0 and 25.\n";
	}
	
	if (error == 0)
		setScore(functionality + efficiency + style);
	else
		std::cout << "Cannot determine score due to errors.\n";
		
}