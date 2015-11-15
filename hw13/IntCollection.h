// IntCollection class header
// CS 110B Max Luttrell
// modified with copy constructor and overloaded operators
// Eric Zimmerman

#ifndef INTCOLLECTION_H
#define INTCOLLECTION_H

const int CHUNK_SIZE=5;	// allocate memory in chunks of ints of this size

class IntCollection
{
	private:
		int size;					 // the number of ints currently stored in the int collection
		int capacity;			 // the total number of elements available for stoarge in the data array 
		int* data;					// a pointer to the dynamically allocated data array
		void addCapacity(); // a private member function to allocate more memory if necessary
	public:
	IntCollection();									// constructor
	~IntCollection();									// destructor
	IntCollection(const IntCollection &c);				// copy constructor
	void add(int value);
	int get(int index);
	int getSize();
	IntCollection& operator=(const IntCollection &c);
	bool operator==(const IntCollection &c);
	bool operator!=(const IntCollection &c);
	IntCollection& operator<<(int value);
};

#endif
