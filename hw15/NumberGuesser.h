// Number Guesser class definition
#ifndef NUMBER_GUESSER_H
#define NUMBER_GUESSER_H

class NumberGuesser
{
	protected:
		int highPoint;
		int lowPoint;
		int startHigh;
		int startLow;
	public:
		NumberGuesser(int, int);
		void higher()
			{ lowPoint = getCurrentGuess() + 1; }
		void lower()
			{ highPoint = getCurrentGuess() - 1; }
		virtual int getCurrentGuess()
			{ return ((lowPoint + highPoint)/2); }
		virtual void reset()
			{ lowPoint = startLow; highPoint = startHigh; }

};

#endif