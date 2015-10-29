// Die class
#ifndef DIE_H
#define DIE_H

class Die
{
	private:
		int sides;
		int value;
		unsigned int seed;
	public:
		Die(int = 6);
		int getSides()
			{ return sides; }
		void roll();
		int getValue()
			{ return value; }
};

#endif