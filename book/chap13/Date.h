// Header file for a date class
#ifndef DATE_H
#define DATE_H

// Date class

class Date
{
	private:
		int month;
		int day;
		int year;
	public:
		void setMonth(int mon)
			{ month = mon; }
		void setDay(int d)
			{ day = d; }
		void setYear(int yr)
			{ year = yr; }
		int getYear()
			{ return year; }
		int getDay()
			{ return day; }
		int getMonth()
			{ return month; }

};

#endif