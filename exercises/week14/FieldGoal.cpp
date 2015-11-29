// class implementation for week 14, exercise A
// stores field goals and attempts
#include "FieldGoal.h"

FieldGoal::FieldGoal()
{
	fieldGoals = attempts = 0;
}

FieldGoal::FieldGoal(int g, int a)
{
	fieldGoals = g;
	attempts = a;
}

FieldGoal::operator double()
{
	if (attempts == 0)
		return 0;
	else
		return fieldGoals / (double)attempts;
}

