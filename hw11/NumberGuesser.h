// Number Guesser class definition
#ifndef NUMBER_GUESSER_H
#define NUMBER_GUESSER_H

class NumberGuesser
{
	private:
		int highPoint;
		int lowPoint;
		int startHigh;
		int startLow;
	public:
		NumberGuesser(int, int);
		void higher();
		void lower();
		int getCurrentGuess() const;
		void reset();
};

#endif