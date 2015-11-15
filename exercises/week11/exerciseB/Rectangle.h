// Week 11, Exercise B
// Rectangle class header file with private function
// and overloaded functions
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
	private:
		double width;
		double length;
		char* name;
		void initName(char*);
	public:
		Rectangle();
		Rectangle(double, double, char*);
		~Rectangle()
			{ delete [] name; }
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
};

#endif