// Number Guesser class definition
#ifndef NUMBER_GUESSER_H
#define NUMBER_GUESSER_H

class NumberGuesser
{
	private:
		int high;
		int low;
	public:
		NumberGuesser(int = 1, int = 100);
		void higher();
		void lower();
		int getCurrentGuess();
		void reset();
}