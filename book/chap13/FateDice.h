// Face dice header file
#ifndef FATEDICE_H
#define FATEDICE_H

const int DIE_POOL = 4;
const int SIDES = 3;

class FateDice
{
	private:
		int sides;
		int dice[DIE_POOL];
		long seed;
		short result;
		void roll();
	public:
		FateDice();
		int newRoll();
		int newRoll(int);
		int getResult();
};

#endif