// Program using the population class
#include <iostream>
#include "Population.h"

using namespace std;

int main()
{
	Population sacramento(370000,10000,7000);
	Population oakland, alameda;
	
	oakland.setPopulation(413000);
	oakland.setBirths(12000);
	oakland.setDeaths(23000);
	
	alameda.setPopulation(76419);
	alameda.setBirths(1440);
	alameda.setDeaths(640);
	
	cout << "\nSacramento: " << sacramento.getPopulation() << endl;
	cout << "Births: " << sacramento.getBirths() << " Deaths: " << sacramento.getDeaths() << endl;
	cout << "Birthrate: " << sacramento.getBirthRate() << " Death Rate: " << sacramento.getDeathRate() << endl;
	
	cout << "\nOakland: " << oakland.getPopulation() << endl;
	cout << "Births: " << oakland.getBirths() << " Deaths: " << oakland.getDeaths() << endl;
	cout << "Birthrate: " << oakland.getBirthRate() << " Death Rate: " << oakland.getDeathRate() << endl;

	cout << "\nAlameda: " << alameda.getPopulation() << endl;
	cout << "Births: " << alameda.getBirths() << " Deaths: " << alameda.getDeaths() << endl;
	cout << "Birthrate: " << alameda.getBirthRate() << " Death Rate: " << alameda.getDeathRate() << endl;
	
}