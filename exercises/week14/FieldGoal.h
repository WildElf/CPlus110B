// class declaration for exercise A, week 14
// stores field goals and attempts
#ifndef FIELD_GOAL_H
#define FIELD_GOAL_H

class FieldGoal
{
	private:
		int fieldGoals;
		int attempts;
	public:
		FieldGoal();
		FieldGoal(int, int);
		operator double();
};

#endif
