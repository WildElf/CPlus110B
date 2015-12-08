// week 15, exercise B
// derived class implementation
#include "GradedActivity.h"
#include "PassFailExam.h"

void PassFailExam::set(int q, int m, int p)
{
	numQuestions = q;
	numMissed = m;
	numToPass = p;
	
	double pointsEach = 100.0 / numQuestions; 
	double numericScore = 100.0 - (numMissed * pointsEach); 
	
	setScore(numericScore);
} 

char PassFailExam::getLetterGrade() const
{
	if ((numQuestions - numMissed) >= numToPass) 
		return 'P'; 
	else 
		return 'F'; 
}
