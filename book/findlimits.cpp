#include<iostream>
using namespace std;

// Finds the flowover point for variables

int main()
{
	int thisInt = 2000000, oldInt = 0;
	
//	long thisInt = 9000000000000000000, oldInt = 0;

	while (thisInt > oldInt)
	{
		oldInt = thisInt;
		thisInt++;
	}

	cout << oldInt << " tripped and became " << thisInt << endl;
}
