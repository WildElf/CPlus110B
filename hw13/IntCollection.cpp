// IntCollection class implementation
// from CS 110B Max Luttrell
// modified with copy constructor and overloaded operators
// Eric Zimmerman

#include "IntCollection.h"
#include <iostream>
using namespace std;

IntCollection::IntCollection()
{
	//initialize member data to reflect an empty IntCollection
	size = capacity = 0;
	data = NULL;
}

IntCollection::~IntCollection()
{
	delete [] data;
}

IntCollection::IntCollection(const IntCollection &c)
{
	*this = c;
}

void IntCollection::addCapacity()
{
	//create a new, bigger buffer, copy the current data to it, delete 
	//the old buffer, and point our data pointer to the new buffer

//	cout << "data at " << data << endl;

	int *newData;
	capacity += CHUNK_SIZE;
	newData = new int[capacity];
	for (int i=0; i<size; i++)
		newData[i] = data[i];
	delete [] data;
	data = newData;
	
//	cout << "newData at " << data << endl;
}

void IntCollection::add(int value)
{	
	//first, allocate more memory if we need to
	if (size == capacity)
		addCapacity();

	//now, add the data to our array and increment size
	data[size++] = value;
}

int IntCollection::get(int index)
{	
	if (index<0 || index>=size)
	{
		cout << "ERROR: get() trying to access index out of range.\n";
		exit(1);
	}

	return data[index];
}

int IntCollection::getSize()
{
	return size;
}


IntCollection& IntCollection::operator=(const IntCollection &c)
{
	size = capacity = c.size;
	data = new int[size];
	
	for (int i=0; i<size; i++)
		data[i] = c.data[i];

	return *this;
}

bool IntCollection::operator==(const IntCollection &c)
{	
	int counter = size;

	// make sure the sizes are the same
	// will also work if both are 0
	if (size == c.size)
	{		
		for (int i=0; i<size; i++)
			if (data[i] == c.data[i])
				counter--;
	}
	else
		counter = -1;
	
	if (counter==0)
		return true;
	else
		return false;
}

// we really just need the reverse of the == operator
bool IntCollection::operator!=(const IntCollection &c)
{	
	return !(*this == c);
}

IntCollection& IntCollection::operator<<(int value)
{
	add(value);
	
	return *this;
}