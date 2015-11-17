// Week 11, Exercise B
// Rectangle class header file with private function
// and overloaded functions
// Week 13, friend class and overloaded operators
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
	private:
		double width;
		double length;
		char* name;
		void initName(char*);
		static double yardsAvail;
	public:
		Rectangle();
		Rectangle(double, double, char*);
		~Rectangle();
		friend class TestRect;
		void setWidth(double);
		void setLength(double);
		void setWidth(char*); // overloading
		void setLength(char*); // overloading
		void setName(char*);
		char* getName() const;
		double getWidth() const;
		double getLength() const;
		double getArea() const;
		double getPerimeter() const;
		bool isSquare() const;
		static void setYards(double);
		Rectangle& operator=(Rectangle&);
		bool operator<(const Rectangle&);
		bool operator>(const Rectangle&);
		bool operator==(const Rectangle&);
};

#endif