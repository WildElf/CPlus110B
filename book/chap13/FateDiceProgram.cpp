// Fate dice on the command line?!
#include <iostream>
#include <cstring>
#include "FateDice.h"

using namespace std;

void usage();

int main(int argc, char* argv[])
{	
		
	FateDice pool;
	int mod;
		
	if (argc < 2)
		cout << pool.newRoll() << endl;
	else
		for (int i = 1; i < argc; i++)
		{
			mod = atoi(argv[i]);
			cout << pool.newRoll(mod) << endl;
		}

}

// check for proper arguments
void usage() 
{
	cout << "This probably will have some rules of usage.\n";
}
