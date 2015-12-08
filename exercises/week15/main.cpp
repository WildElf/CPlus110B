// exercise A & B, week 15
// Eric Zimmerman
// object inheritance

#include "GradedActivity.h"
#include "Assignment.h"
#include "PassFailExam.h"
#include <iostream>

using namespace std;

int main()
{
/*	exercise A
	int funct, effish, sty;
	
	cout << "Assignment grading:\n";
	cout << "Enter functionality score: ";
	cin >> funct;

	cout << "Enter efficiency score: ";
	cin >> effish;

	cout << "Enter style score: ";
	cin >> sty;

	Assignment homework;
	homework.set(funct, effish, sty);
	
	cout << "The grade is " << homework.getLetterGrade() << " from a score of " 
		<< homework.getScore() << endl;
	*/
	
	PassFailExam quiz1, quiz2;
	GradedActivity *gaPtr = NULL;

	quiz1.set(10,4,7);
	quiz2.set(15,3,10);
	
	gaPtr = &quiz1;
	cout << "Quiz 1 score is " << gaPtr->getScore() << " for a grade of " << gaPtr->getLetterGrade() << endl;
	gaPtr = &quiz2;	
	cout << "Quiz 2 score is " << gaPtr->getScore() << " for a grade of " << gaPtr->getLetterGrade() << endl;
	
}