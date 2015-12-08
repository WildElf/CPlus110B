// week 15, exercise B
// derived class definition for polymorphism
#ifndef PASSFAILEXAM_H
#define PASSFAILEXAM_H
#include "GradedActivity.h"

class PassFailExam : public GradedActivity
{ 
	private: 
		int numQuestions; 
		int numMissed; 
		int numToPass; 
	public: 
		PassFailExam() 
			{ numQuestions = 0; 
				numMissed = 0; 
				numToPass = 0; } 
		void set(int, int, int); 
		char getLetterGrade() const; 

};

#endif