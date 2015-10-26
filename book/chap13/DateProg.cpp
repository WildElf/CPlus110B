// A program using the Date class
#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
	int month, day, year;
	
	cout << "Enter the month: ";
	cin >> month;
	
	cout << "Enter the day: ";
	cin >> day;
	
	cout << "Enter the year: ";
	cin >> year;
	
	Date newDay;
	
	newDay.setMonth(month);
	newDay.setDay(day);
	newDay.setYear(year);
	
	cout << "The date is:\n";
	cout << newDay.getMonth() << "/" << newDay.getDay() << "/" << newDay.getYear() << endl;
}
