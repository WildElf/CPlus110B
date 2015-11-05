// playing with vectors
#include <iostream>
#include <vector>

using namespace std;

void sortVector(vector<int> &);

int main()
{
	vector<int> numbers { 10, 20, 50, 30, 60, 88, 90, 12, 45 };
	
	for (int i : numbers )
		cout << i << endl;
		
	cout << "Elements: " << numbers.size() << endl;

	sortVector(numbers);

	for (int i : numbers )
		cout << i << endl;
}

void sortVector(vector<int> &nums)
{
	int lowest, holder;
	int size = nums.size();

	for (int i = 0; i < size; i++)
	{
		lowest = i;

		for (int j = i; j < size; j++)
			if (nums[j] < nums[lowest])
				lowest = j;
		
		if (i != lowest)
		{
			holder = nums[i];
			nums[i] = nums[lowest];
			nums[lowest] = holder;
		}
		

	}
}
