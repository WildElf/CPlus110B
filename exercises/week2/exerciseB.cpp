#include<iostream>
using namespace std;

// Excercise B - EZ
// Ask user for number of assignments, and display grade average.

int main()
{
	// initialize variables
	int number, grade, totalGrades;
	float gPA;

	// define for future logic
	number = 200;
	totalGrades = 0;

	// get the number of assignments
	while (number < 1 || number > 25)
	{
		cout << "Enter the total number of assignments: ";
		cin >> number;
		
		if (number < 0 || number > 25)
		{
			cout << "\nThe class is not that long. (Enter 1-25).\n\n";
		}
	}
	
	// get grades for each assignment
	for (int i = 0; i < number; i++)
	{
		cout << "Grade for Assignment " << i+1 << ": ";
		cin >> grade;

		while (grade < 0 || grade > 100)
		{
			cout << "\nInvalid grade. Must be 0-100: ";
			cin >> grade;
		}
		
		totalGrades += grade;
	}

	// determine average
	gPA = (float)totalGrades / number;
	
	if (gPA < 60)
		cout << "The grade is F, with a grade average of " 
			<< gPA << ".\n";
	else if (gPA < 70)
		cout << "The grade is D, with a grade average of "
			<< gPA << ".\n";
	else if (gPA < 80)
		cout << "The grade is C, with a grade average of "
			<< gPA << ".\n";
	else if (gPA < 90)
		cout << "This grade is B, with a grade average of "
			<< gPA << ".\n";
	else
		cout << "The grade is A, with a grade average of "
			<< gPA << ".\n";
}
