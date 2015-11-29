// declaring class for exercise A, week 14
// stores person data
#ifndef PERSON_H
#define PERSON_H
#include "FeetInches.h"
#include "FieldGoal.h"
#include <string>

class Person
{
	private:
		std::string firstName;
		std::string lastName;
		FeetInches height;
		int weight;
		FieldGoal fieldGoals;
	public:
		Person();
		Person(std::string, std::string, FeetInches, int, FieldGoal);
		void print();		
};

#endif
