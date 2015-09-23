// Week 4, Execise B - Eric Zimmerman
// taking burrito orders, with shrimp alert
#include<iostream>
#include<string>
using namespace std;

// function prototypes
void orderBurrito(string [], string [], int);
void shrimpAlert(string);

// number of types of burritos in stock
const int BURRITO_KINDS = 4;

int main()
{
	const int MAX_ORDER = 25;
	string burritos[BURRITO_KINDS] = {"carnitas", "beef", "shrimp", "vegetarian"};
/*	
	// tells user burritos[] needs to be updated
	if (burritos[BURRITO_KINDS-1] == "")
		cout << "WARNING: Burritos are missing from the code. "
			<< "Hire that programmer again, he was awesome.";
*/
	// set up and order taking
	int orderSize = 0;
	string partyOrder[MAX_ORDER];
	
	while (orderSize <= 0 || orderSize >= MAX_ORDER)
	{
		cout << "How many burritos for this party? ";
		cin >> orderSize;

		if (orderSize >= MAX_ORDER)
			cout << "We're sorry. Catering orders must be made "
				<< "before 11am or after 1pm.\n\n\n";
		else if (orderSize <= 0)
		{
			orderSize = 0;
			cout << "Please come back again when you are "
				<< "ready to order.\n\n";
		}
	}

	orderBurrito(partyOrder,burritos,orderSize);
	
	cout << "Order of " << orderSize << " burritos.\n";

	// total the orders
	int orders[BURRITO_KINDS] = {0};
	for (int i = 0; i < BURRITO_KINDS; i++)
		{
			for (int j = 0; j < orderSize; j++)
				{
					if (partyOrder[j] == burritos[i])
						orders[i]++;
				}
			cout << burritos[i] << ": " << orders[i] << endl;
		}
	cout << "That completes the order.\n\n";	

}

void orderBurrito(string party[],string burritos[],int size)
{
	for (int i = 0; i < size; i++)
	{
		bool validBurrito = false;		
		while (!validBurrito)
		{
			string burrito;
			cout << "Burrito #" << i+1 << ": ";
			cin >> burrito;
			
			for (int j = 0; j < BURRITO_KINDS; j++)
			{
				if (burrito == burritos[j])
					validBurrito = true;
			}

			if (validBurrito)
			{
				party[i] = burrito;
				shrimpAlert(burrito);
			}
			else
				cout << "Sorry, we're out of those today.\n";
		}
	}

}

void shrimpAlert(string burrito)
{
	if (burrito == "shrimp")
		cout << "BRING OUT THE SHRIMP!\n";
}
