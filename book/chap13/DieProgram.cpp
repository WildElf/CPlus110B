// A die rolling program using the Die class
#include<iostream>
#include "Die.h"

using namespace std;

int main()
{
	int dieKinds;
	Die *diceBag;
	int *diceCollector;
	
	cout << "How many kinds of dice do you want (up to 10)? ";
	cin >> dieKinds;
	
	diceBag = new Die[dieKinds];	
	
	for (int i = 0; i < dieKinds; i++)
	{
		int faces; 

		cout << "How many faces does die #" << i + 1 << " have? ";
		cin >> faces;	
		
		Die thisDie(faces);
		diceBag[i] = thisDie;
	}
	
	for (int i = 0; i < dieKinds; i++)
	{
		cout << "Die #" << i+1 << ": " << diceBag[i].getValue() << endl;
		diceBag[i].roll();
	}
	
	for (int i = 0; i < dieKinds; i++)
	{
		cout << "Die #" << i+1 << ": " << diceBag[i].getValue() << endl;
		diceBag[i].roll();
	}
	
}