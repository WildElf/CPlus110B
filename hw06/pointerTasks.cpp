// Pointer Tasks - Eric Zimmerman
// performing simple tasks with pointers
#include<iostream>

using namespace std;

void noNegatives(int*);
void swap(int* first, int* second);

int main()
{
	// Step 1
	int x, y;
	
	// Step 2
	int* p1 = NULL;

	// Step 3
	p1 = &x;

	// Step 4
	*p1 = 99;
	
	// Step 5
	cout << "X is " << x << " at address " << p1 << endl;

	// Step 6
	cout << "P1 is storing " << *p1 << " at " << p1 << endl;
	
	// Step 7
	p1 = &y;

	// Step 8
	*p1 = -300;

	// Step 9
	int temp;
	int* p2 = &x;

	// Step 10
	// using pointers to swap x and y values
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;

	// step 11 GOTO noNegatives function.
	// step 12
	noNegatives(p1);
	noNegatives(p2);

	// step 13
	cout << "\nP2 is holding x with " << *p2 << " and ";	

	p2 = &y;
	
	cout << "now it's holding y with " << *p2 << endl;

	// Step 14 - int array
	int a[2];

	// Step 15
	p2 = &x;
	a[0] = *p2;

	// Step 16
	p2 = &y;
	a[1] = *p2;
	
	// Step 17
	p2 = a;
	cout << "\na[0]'s address: " << p2 << " with Value: " << *p2 << endl;

	// Step 18
	cout << "a[1]'s address: " << p2 + 1 << " with Value: " << *(p2+1) << endl;

	// Step 19
	p1 = &a[0];
	p2 = &a[1];

	temp = *p1;
	*p1 = *p2;
	*p2 = temp;

	// Step 20
	cout << "\na[0]: " << a[0] << endl 
		<< "a[1]: " << a[1] << endl;

	// Step 21 GOTO swap function
	// Step 22
	swap(&x,&y);
	
	cout << "X is now " << x << ", and Y is " << y << ".\n";

	// Step 23
	swap(a[0],a[1]);

	cout << "a[0] is now " << a[0] << ", and a[1] is " << a[1] << ".\n";
	
}

// Step 11
void noNegatives(int* x)
{
	if (*x < 0)
		*x = 0;

}

// Step 21
void swap(int* first, int* second)
{
	int temp;
	temp = *first;
	*first = *second;
	*second = temp;
}

/* Sample Output
[ezimmer2@hills hw06]$ a.out 
X is 99 at address 0x7ffcad61d968
P1 is storing 99 at 0x7ffcad61d968

P2 is holding x with 0 and now it's holding y with 99

a[0]'s address: 0x7ffcad61d950 with Value: 0
a[1]'s address: 0x7ffcad61d954 with Value: 99

a[0]: 99
a[1]: 0
X is now 99, and Y is 0.
a[0] is now 0, and a[1] is 99.
[ezimmer2@hills hw06]$ 
*/
