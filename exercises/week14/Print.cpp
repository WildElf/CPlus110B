// exercise A, week 14
// demonstrating values in FeetInches, FieldGoal, and Person classes
#include "FeetInches.h"
#include "FieldGoal.h"
#include "Person.h"
#include <string>
#include <iostream>

using namespace std;

int main ()
{
	FeetInches donny(5,7);
	FeetInches walter(6,4);
	
	FieldGoal don(7,345);
	FieldGoal walt(120, 278);
	
	Person player34("Theodore", "Kerabatsos", donny, 165, don);
	Person player50("Walter", "Sobchak", walter, 320, walt);
	
	cout << "********" << endl;
	player34.print();
	cout << "********" << endl;
	player50.print();
	cout << "********" << endl;
	
}