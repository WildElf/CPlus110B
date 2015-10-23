// Week 10 Homework - Eric Zimmerman
// Using a simple Circle class to create objects
#include <iostream>
#include "Circle.h"

using namespace std;

int menu();
void changeCircleValues(Circle,int);

int main ()
{
	// variables for user controlled number of circles
	int numCircles;
	Circle *circleCollection = NULL;
		
	// declare variables to create circles
	double circleX, circleY, circleRadius;

	cout << "How many circles do you want to make? ";
	cin >> numCircles;
	
	if (numCircles < 1)
	{
		cout << "Let's make one anyway.\n";
		numCircles = 1;
	}
	
	// create an array to allow a user defined number of circles
	circleCollection = new Circle[numCircles];
	
	cout << "Now to make " << numCircles << " circles.\n";

	// loop for all circles in the array
	for (int i = 0; i < numCircles; i++)
	{
		cout << "Enter the X coordinate for Circle #" << i + 1 << ": ";
		cin >> circleX;
	
		cout << "Enter the Y coordinate for Circle #" << i + 1 << ": ";
		cin >> circleY;
		
		cout << "Enter the radius for Circle #" << i + 1 << ": ";
		cin >> circleRadius;

		cout << "The area of this circle should be " << circleRadius * circleRadius * 3.14 << endl;
		
		if (i == 12)
			cout << "This sure is a lot of circles.\n";
		
		// build a circle object with entered values
		// Circle circleCollection[i];
	
		circleCollection[i].setX(circleX);
		circleCollection[i].setY(circleY);
		circleCollection[i].setRadius(circleRadius);

	}
	
	// display all circles created
	cout << "Now there are " << numCircles << " circles.\n";
	for (int i = 0; i < numCircles; i++)
	{
		cout << "Circle #" << i + 1 << " is at (" << circleCollection[i].getX() << ", " << circleCollection[i].getY()
			<< ") with a radius of " << circleCollection[i].getRadius() 
			<< " and an area of " << circleCollection[i].getArea() << endl;
	}
	
		
	// set up do-while logic for repeatable portion
	bool loop = true;

	do
	{
		// run the menu function
		int choice = menu();
		
		if (choice == 1)
		{
			// let's user select one or many circles to change
			int changeNum;

			// modify circle values using the pointer
			cout << "\nNow we'll change circle values using pointers.\n";
			cout << "Which circle(s) would you like to change? (enter 0 to change all): ";
			cin >> changeNum;

			// TODO update to use pointer
			if (changeNum < 0 || changeNum > numCircles) // basic bounds checking
			{
				cout << "That's confusing me, so we'll change them all!";
				changeNum = 0;
			}
			else if (changeNum == 0)
				for (int i = 0; i < numCircles; i++) // loop for each circle
				{
					cout << "Enter the X coordinate for Circle #" << i + 1 << ": ";
					cin >> circleX;

					cout << "Enter the Y coordinate for Circle #" << i + 1 << ": ";
					cin >> circleY;

					cout << "Enter the radius for Circle #" << i + 1 << ": ";
					cin >> circleRadius;

					// update circle
					(circleCollection+i)->setX(circleX);
					(circleCollection+i)->setY(circleY);
					(circleCollection+i)->setRadius(circleRadius);

				}
			else // use changeNum to change only selected circle
			{
				cout << "Enter the X coordinate for Circle #" << changeNum << ": ";
				cin >> circleX;
	
				cout << "Enter the Y coordinate for Circle #" << changeNum << ": ";
				cin >> circleY;
		
				cout << "Enter the radius for Circle #" << changeNum << ": ";
				cin >> circleRadius;
				
				// update the circle, accounting for index shift
				(circleCollection+(changeNum-1))->setX(circleX);
				(circleCollection+(changeNum-1))->setY(circleY);
				(circleCollection+(changeNum-1))->setRadius(circleRadius);
			}
			
			// redisplay circles		
			for (int i = 0; i < numCircles; i++)
			{
				cout << "Circle #" << i + 1 << " is at (" << circleCollection[i].getX() << ", " << circleCollection[i].getY()
					<< ") with a radius of " << circleCollection[i].getRadius() 
					<< " and an area of " << circleCollection[i].getArea() << endl;
			}

		}
		else if (choice == 2)
		{
			double testX, testY;
			bool insidePoint = false;

			// get points to test
			cout << "\nEnter the X coordinate to test: ";
			cin >> testX;
			
			cout << "Enter the Y coordinate to test: ";
			cin >> testY;

			for (int i = 0; i < numCircles; i++)
			{
				// check the point using the Circle class method
				insidePoint = circleCollection[i].containsPoint(testX, testY);
			
				if (insidePoint)
					cout << "The point is inside circle #" << i + 1 << ".\n";
				else
					cout << "The point is outside circle #" << i + 1 << ".\n";

			}
		}	
		else  // terminate the loop
		{
			cout << "The circle is broken. Goodbye!\n";
			loop = false;
		}
		
	} while (loop);
}

int menu()
{
	int menuChoice;
	do
	{
		cout << "What now?\n";
		cout << "1. Change circle values (with pointers)\n";
		cout << "2. Find out if a point exists in any circles\n";
		cout << "3. Quit\n";
		cout << "Select 1-3: ";
		cin >> menuChoice;
		
		if (menuChoice < 1 || menuChoice > 3)
			cout << "Invalid selection.\n\n";

	} while (menuChoice < 1 || menuChoice > 3);
	
	return menuChoice;
}
