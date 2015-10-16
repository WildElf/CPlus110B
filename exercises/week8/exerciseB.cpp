#include<iostream>

using namespace std;

int stringCompare(char *s1, char *s2); 

int main()
{
	char input1[128], input2[128];
	int compare;
	
	cout << "Give me the first string: ";
	cin.getline(input1, 128);
	
	cout << "Give me the second string: ";
	cin.getline(input2, 128);
	
//	cout << "String 1: " << input1 << endl << "String 2: " << input2 << endl;
	
	compare = stringCompare(input1,input2);
	
	if (compare == 0)
		cout << "\nThese strings are the same.\n";
	else
		cout << "\nThese strings are different.\n";
		
}

int stringCompare(char *s1, char *s2)
{
	int compareDiff, count = 0;
	
	compareDiff = strlen(s1) - strlen(s2);
	
	while (compareDiff == 0 && (s1[count] != '\0' && s2[count] != '\0'))
	{
		if (s1[count] != s2[count] && (s1[count] != '\0' &&  s2[count] != '\0'))
			compareDiff++;
		
		count++;	
	}
	
	return compareDiff;
}
