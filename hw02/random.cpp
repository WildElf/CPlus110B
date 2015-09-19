#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	cout << "Seed: " << time(0) << ", " << endl;

	unsigned seed = time(0);

	cout << "Normal rand: " << rand() << ", " << rand() << endl;
	cout << rand() << ", ";
	cout << rand() << endl;

	srand(seed);

	cout << "\nSeeded rand: " << rand() << ", " << rand() << endl;
	cout << rand() << ", ";
	cout << rand() << endl;

}
