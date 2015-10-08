// Exercise A, Week 7 - Eric Zimmerman
// Check password for hills format
#include<iostream>

using namespace std;

int main()
{
	const int LENGTH = 64;
	char password[LENGTH];
	bool validPassword = false;
	char reason[LENGTH] = "Password approved.";
	
	cout << "Enter password to check: ";
	cin.getline(password, LENGTH);
	
	if (islower(password[0]) && islower(password[1]) && islower(password[2]))
		if (isdigit(password[3]) && isdigit(password[4])
			&& isdigit(password[5]) && isdigit(password[6]))
			if (password[7] == '.')
				if (islower(password[8]) && islower(password[9]))
					if (password[10] == '\0')
						validPassword = true;
					else
						strcpy(reason, "Password too long.");
				else
					strcpy(reason, "First and Last initials are incorrect.");
			else
				strcpy(reason, "Password missing period separator between birthdate and name."); // 63 chars here
		else
			strcpy(reason, "Birth day and year need to be numbers: DDYY");
	else
		strcpy(reason, "Birth month needs to be lowercase letters: mmm");
	
	if (validPassword)
		cout << "No problems detected.\n";
	else
		cout << "Invalid password.\n";
			
	cout << reason << endl;

}
