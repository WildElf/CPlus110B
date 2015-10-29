// Week 11, Exercise A
// Rectangle class header file with destructor
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
	private:
		double width;
		double length;
		char* name;
	public:
		Rectangle();
		Rectangle(double, double, char*);
		~Rectangle()
			{ delete [] name; }
		void setWidth(double);
		void setLength(double);
		void setName(char*);
		char* getName() const;
		double getWidth() const;
		double getLength() const;
		double getArea() const;
		double getPerimeter() const;
		bool isSquare() const;
};

#endif