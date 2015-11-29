// week 15, exerciseA
// class inheritance, derived class definition
#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include "GradedActivity.h"

class Assignment : public GradedActivity
{
	private:
		int functionality;
		int efficiency;
		int style;
	public:
		void set(int,int,int);
};

#endif