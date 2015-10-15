// C-Strings - Eric Zimmerman
// manipulating c-strings on the go
#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

// function prototypes
void progMenu();
bool testAgain();
int lastIndexOf(char *s, char target);
void reverse(char *s);
int replace(char *s, char target, char replacementChar);
int findSubstring(char *s, char substring[]);
bool isPalindrome(char *s);
void reverseWords(char *s);
int findArrayLength(char *s);

// main function for easy function selection and repeat performance
int main()
{
	do
	{
		progMenu();
		
	} while (testAgain());
	
	cout << endl;
}

void progMenu()
{
	int menuChoice;
	const int TWEET = 141;
	char cString[TWEET];
	
	do
	{
		cout << "\nC-String Menu\n\n";
		cout << "1. Find the last index of a character.\n";
		cout << "2. Reverse your string.\n";
		cout << "3. Replace one character for another.\n";
		cout << "4. Find the first occurrence of a string of characters in a larger string.\n";
		cout << "5. Check to see if a string is a strict palindrome.\n";
		cout << "6. Reverse a sentence.\n";
		cout << "\n** Enter your number selection: ";
		cin >> menuChoice;
		cin.ignore(256, '\n');
					

	} while (menuChoice < 1 || menuChoice > 6);
	
	cout << "Enter a string of characters (up to 140 characters) for your choice: \n: ";
	cin.getline(cString, TWEET);

	if (menuChoice == 1)
	{
		char search;
		cout << "What character do you want to look for? ";
		cin >> search;
		cin.ignore(256, '\n');
		
		int location = lastIndexOf(cString,search);
		
		if (location >= 0)
			cout << "Your character last appears at index " << location << ".\n";
		else
			cout << "The character '" << search << "' was not found.";
	}
	else if (menuChoice == 2)
	{
		reverse(cString);
		
		cout << "Reversed: " << cString << endl;
	}
	else if (menuChoice == 3)
	{
		char toReplace, replacement;
		
		cout << "Character to replace: ";
		cin >> toReplace;

		cin.ignore(256, '\n');
		
		cout << "Replace '" << toReplace << "' with: ";
		cin >> replacement;
		
		replace(cString,toReplace,replacement);
		
		cout << "\nYour string is now:\n" << cString << endl;
		
		cin.ignore(256, '\n');
		
		
	}
	else if (menuChoice == 4)
	{
		char subString[TWEET];
		
		cout << "Enter the substring to search for: ";
		cin.getline(subString,TWEET);
		
		int index = findSubstring(cString,subString);
		
		if (index == -1)
			cout << "The substring was not found.\n";
		else
			cout << "The substring was first seen at index: " << index << endl;
	}
	else if (menuChoice == 5)
	{
		if (isPalindrome(cString))
			cout << "This is a palindrome.\n";
		else
			cout << "This is not a palindrome.\n";
	}
	else
	{
		reverseWords(cString);
		
		cout << "Reversed sentence: " << cString << endl;
	}
	
}

bool testAgain()
{
	char again[64];
	cout << "Check another string? (y/n) ";
	cin.getline(again, 64);
	
	if (tolower(again[0]) == 'y')
		return true;
	else
		return false;
}


int lastIndexOf(char *s, char target)
{
	int index = 0, found = -1;
	
	while (s[index] != '\0')
	{
		if (s[index] == target)
			found = index;
		
		index++;
	}
	
	return found;
}

void reverse(char *s)
{
	int length = strlen(s);
	char flipper[length];

	// feed the flipper with reverse s[]	
	for (int i = 0; i < length; i++)
		flipper[i] = s[length-1-i];

	// replace s[] with reversed data
	for (int i = 0; i < length; i++)
		s[i] = flipper[i];

}

int replace(char *s, char target, char replacementChar)
{
	int replaced = 0, index = 0;
	
	while (s[index] != '\0')
	{
		if (s[index] == target)
		{
			s[index] = replacementChar;
			replaced++;
		}
		
		index++;
	}
	
	return replaced;
}

int findSubstring(char *s, char substring[])
{
	int index = 0, found = -1;
	int sub = strlen(substring);

	while (s[index] != '\0' && found == -1)
	{
		if (s[index] == substring[0])
		{
			for (int i = 0; i < strlen(substring); i++)
			{
				if (s[index + i] != '\0' && s[index + i] == substring[i])
					sub--;
				else if (s[index + i] == '\0')
					sub++;
			}
			
			if (sub == 0)
				found = index;
		}
		
		index++;
	}
	
	return found;

}

bool isPalindrome(char *s)
{
	bool palin = false;
	char *drome = NULL;

	// find the length of s, and build a new array
	int size = strlen(s);
	drome = new char[size];
			
	// populate drome array with reversed s array
	for (int i = 0; i < size; i++)
		drome[i] = s[size-1-i];

	// makes drome[] a proper c-string		
	drome[size] = '\0';
	
	// look for any differences
	if (!strcmp(drome,s))
		palin = true;	// a rare event

	return palin;
	
	// pointer clean up 
	delete [] drome;
	drome = NULL;

	
}

// Finds the last word, puts it into a holding array
// moves onto the next word, puts it next into the holding array
// continues until the beginning of the array is reached.
void reverseWords(char *s)
{

	const int SIZE = strlen(s);
	int wordSize = 0, index = SIZE;
	char reverseHolder[SIZE + 1];
	int reverseIndex = 0;
	
	// start at the end of the s-array
	while ( index > 0 )
	{
		index--;
		
		if (s[index] != ' ')
			wordSize++;
		else // a word has been completed
		{
			// index + 1 starts us at the last letter
			// index + wordSize tells us how far to go
			for (int i = index + 1; i <= index + wordSize; i++)
			{
				// get the letter and put it into reverseHolder
				reverseHolder[reverseIndex++] = s[i];
			}
			
			// add a space to the end of the word
			reverseHolder[reverseIndex++] = ' ';
			
			// reset wordSize, prep for next word
			wordSize = 0;
		}
				
		// the first index will always be the end of a word
		if (index == 0)
		{
			// word size has already been incremented		
			for (int i = index; i <= index + wordSize; i++)
			{
				// get the letter and put it into reverseHolder
				reverseHolder[reverseIndex++] = s[i];
			}
			
			// add a null character for the final word
			reverseHolder[reverseIndex++] = '\0';
			
			// reset wordSize, prep for next word
			wordSize = 0;
		}
		
		
	}

	// copy over the final result
	strcpy(s,reverseHolder);

}

/*  sample output
Silica:hw08 ez$ a.out 

C-String Menu

1. Find the last index of a character.
2. Reverse your string.
3. Replace one character for another.
4. Find the first occurrence of a string of characters in a larger string.
5. Check to see if a string is a strict palindrome.
6. Reverse a sentence.

** Enter your number selection: 4
Enter a string of characters (up to 140 characters) for your choice: 
: monkeys don't like keys
Enter the substring to search for: key
The substring was first seen at index: 3
Check another string? (y/n) y

C-String Menu

1. Find the last index of a character.
2. Reverse your string.
3. Replace one character for another.
4. Find the first occurrence of a string of characters in a larger string.
5. Check to see if a string is a strict palindrome.
6. Reverse a sentence.

** Enter your number selection: 5
Enter a string of characters (up to 140 characters) for your choice: 
: Hi ma'am, I'm Adam.
This is not a palindrome.
Check another string? (y/n) y

C-String Menu

1. Find the last index of a character.
2. Reverse your string.
3. Replace one character for another.
4. Find the first occurrence of a string of characters in a larger string.
5. Check to see if a string is a strict palindrome.
6. Reverse a sentence.

** Enter your number selection: 5
Enter a string of characters (up to 140 characters) for your choice: 
: bob
This is a palindrome.
Check another string? (y/n) y

C-String Menu

1. Find the last index of a character.
2. Reverse your string.
3. Replace one character for another.
4. Find the first occurrence of a string of characters in a larger string.
5. Check to see if a string is a strict palindrome.
6. Reverse a sentence.

** Enter your number selection: 6
Enter a string of characters (up to 140 characters) for your choice: 
: This part was really hard, but it works.
Reversed sentence: works. it but hard, really was part This 
Check another string? (y/n) n
Silica:hw08 ez$ a.out 

C-String Menu

1. Find the last index of a character.
2. Reverse your string.
3. Replace one character for another.
4. Find the first occurrence of a string of characters in a larger string.
5. Check to see if a string is a strict palindrome.
6. Reverse a sentence.

** Enter your number selection: 1
Enter a string of characters (up to 140 characters) for your choice: 
: Pandas eat bamboo
What character do you want to look for? b
Your character last appears at index 14.
Check another string? (y/n) y

C-String Menu

1. Find the last index of a character.
2. Reverse your string.
3. Replace one character for another.
4. Find the first occurrence of a string of characters in a larger string.
5. Check to see if a string is a strict palindrome.
6. Reverse a sentence.

** Enter your number selection: 2
Enter a string of characters (up to 140 characters) for your choice: 
: A panda eats, shoots, and leaves 
Reversed: sevael dna ,stoohs ,stae adnap A
Check another string? (y/n) y

C-String Menu

1. Find the last index of a character.
2. Reverse your string.
3. Replace one character for another.
4. Find the first occurrence of a string of characters in a larger string.
5. Check to see if a string is a strict palindrome.
6. Reverse a sentence.

** Enter your number selection: 3
Enter a string of characters (up to 140 characters) for your choice: 
: Sally sells sea shells so simply to snakes.
Character to replace: s
Replace 's' with: Q

Your string is now:
Sally QellQ Qea QhellQ Qo Qimply to QnakeQ.
Check another string? (y/n) y

C-String Menu

1. Find the last index of a character.
2. Reverse your string.
3. Replace one character for another.
4. Find the first occurrence of a string of characters in a larger string.
5. Check to see if a string is a strict palindrome.
6. Reverse a sentence.

** Enter your number selection: 4
Enter a string of characters (up to 140 characters) for your choice: 
: lolly gaggers
Enter the substring to search for: ag
The substring was first seen at index: 7
Check another string? (y/n) y

C-String Menu

1. Find the last index of a character.
2. Reverse your string.
3. Replace one character for another.
4. Find the first occurrence of a string of characters in a larger string.
5. Check to see if a string is a strict palindrome.
6. Reverse a sentence.

** Enter your number selection: 4
Enter a string of characters (up to 140 characters) for your choice: 
: A longist story about a man and his faithful xylophone.                       
Enter the substring to search for: xyl
The substring was first seen at index: 45
Check another string? (y/n) y

C-String Menu

1. Find the last index of a character.
2. Reverse your string.
3. Replace one character for another.
4. Find the first occurrence of a string of characters in a larger string.
5. Check to see if a string is a strict palindrome.
6. Reverse a sentence.

** Enter your number selection: 4
Enter a string of characters (up to 140 characters) for your choice: 
: monkeys don't like keys
Enter the substring to search for: key
The substring was first seen at index: 3
Check another string? (y/n) y

C-String Menu

1. Find the last index of a character.
2. Reverse your string.
3. Replace one character for another.
4. Find the first occurrence of a string of characters in a larger string.
5. Check to see if a string is a strict palindrome.
6. Reverse a sentence.

** Enter your number selection: 5
Enter a string of characters (up to 140 characters) for your choice: 
: Hi ma'am, I'm Adam.
This is not a palindrome.
Check another string? (y/n) y

C-String Menu

1. Find the last index of a character.
2. Reverse your string.
3. Replace one character for another.
4. Find the first occurrence of a string of characters in a larger string.
5. Check to see if a string is a strict palindrome.
6. Reverse a sentence.

** Enter your number selection: 5
Enter a string of characters (up to 140 characters) for your choice: 
: bob
This is a palindrome.
Check another string? (y/n) y

C-String Menu

1. Find the last index of a character.
2. Reverse your string.
3. Replace one character for another.
4. Find the first occurrence of a string of characters in a larger string.
5. Check to see if a string is a strict palindrome.
6. Reverse a sentence.

** Enter your number selection: 6
Enter a string of characters (up to 140 characters) for your choice: 
: This part was really hard, but it works.
Reversed sentence: works. it but hard, really was part This 
Check another string? (y/n) n

*/
