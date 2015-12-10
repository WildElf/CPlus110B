// Random Number Guesser derived class
#ifndef RANDOM_NUMBER_GUESSER_H
#define RANDOM_NUMBER_GUESSER_H
#include "NumberGuesser.h"

class RandomNumberGuesser : public NumberGuesser
{
	private:
		unsigned long seed;
	protected:
		int check;
	public:
		RandomNumberGuesser(int, int);
		virtual int getCurrentGuess();
		virtual void reset();
};

#endif
