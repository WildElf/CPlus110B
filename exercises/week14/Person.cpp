// class implementation for week 14, exercise A
// stores values in a basketball person
#include "Person.h"
//#include "FeetInches.h"
//#include "FieldGoal.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

Person::Person()
{
	firstName = lastName = "";
	weight = 0;
}

Person::Person(string first, string last, FeetInches h, int w, FieldGoal goals)
{
	firstName = first;
	lastName = last;
	height = h;
	weight = w;
	fieldGoals = goals;
}

void Person::print()
{
	double goals = fieldGoals * 100;
	cout << "Stats for " << firstName << " " << lastName << ": \n";
	cout << "Height: " << height.getFeet() << "' " << height.getInches() << "\"\n";
	cout << "Weight: " << weight << endl;
	cout << "Field Goal Percentage: " << goals << "%" << endl;
}
		
