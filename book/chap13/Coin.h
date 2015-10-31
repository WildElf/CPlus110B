// Coin class header file
#ifndef COIN_H
#define COIN_H
#include <string>

using namespace std;

class Coin
{
	private:
		string sideUp;
		long seed;
	public:
		Coin();
		void toss();
		string getSideUp()
			{ return sideUp; }
};

#endif