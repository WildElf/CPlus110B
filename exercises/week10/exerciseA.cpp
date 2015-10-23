// Eric Zimmerman
// Week 10, Exercise A
#include <iostream>

using namespace std;

// definition of Rectangle class
class Rectangle
{
	private:
		double width;
		double length;
	public:
		void setWidth(double);
		void setLength(double);
		double getWidth() const;
		double getLength() const;
		double getArea() const;
		double getPerimeter() const;
		bool isSquare() const;
} rect;

void Rectangle::setWidth(double w)
{
	width = 0;
	
	if (w > 0)
		width = w;
	else if (w == 0)
		cout << "We don't like vertical lines here.\n";
	else
		width = -w;
}

void Rectangle::setLength(double l)
{
	length = 0;
	
	if (l > 0)
		length = l;
	else if (l == 0)
		cout << "We don't like horizontal lines here.\n";
	else
		length = -l;
}

double Rectangle::getWidth() const
{
	return width;
}

double Rectangle::getLength() const
{
	return length;
}

double Rectangle::getArea() const
{
	return width * length;
}

double Rectangle::getPerimeter() const
{
	return (width * 2) + (length * 2);
}

bool Rectangle::isSquare() const
{
	if (width == length)
		return true;
	else
		return false;
}

// ***************************************
// Main function using the Rectangle class
// ***************************************
int main()
{
	// variable declaration for user input
	double width, length;
	char goAgain;
	
	do 
	{
		// get user input
		cout << "Make a rectangle!\nEnter the width: ";
		cin >> width;
		
		cout << "Enter the length: ";
		cin >> length;
		
		// create the rectangle
		Rectangle r;
		r.setWidth(width);
		r.setLength(length);
		
		cout << "The area of your rectangle is " << r.getArea() << endl;
		
		cout << "Your rectangle has a perimeter of " << r.getPerimeter() << endl;
		
		if (r.isSquare())
			cout << "Bonus, your rectangle is a square!\n";
		else
			cout << "This is a fine rectangle. It's no square, but it's fine.\n";
			
		cout << "Hey, wanna make another rectangle? (y/n): ";
		cin >> goAgain;
		
	} while (tolower(goAgain) == 'y');
	
}