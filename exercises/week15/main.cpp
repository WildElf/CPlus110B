// exercise A, week 15
// Eric Zimmerman
// object inheritance

#include "GradedActivity.h"
#include "Assignment.h"
#include <iostream>

using namespace std;

int main()
{
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

}