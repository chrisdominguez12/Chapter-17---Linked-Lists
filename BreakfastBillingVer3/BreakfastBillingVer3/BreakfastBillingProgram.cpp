//This program demonstrates a linked list using the BreakBilling Header file

#include "BreakfastBilling.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

	BreakfastBilling menu;

	menu.add(1.45, "Plain Egg"); 
	menu.add(2.45, "Bacon and Egg");
	menu.add(.99, "Muffin");
	menu.add(1.99, "French Toast");
	menu.add(2.49, "Fruit Basket");
	menu.add(.69, "Cereal");			//NICE
	menu.add(.50, "Coffee");
	menu.add(.75, "Tea");

	double TAX = .05;				//Sales tax
	int userChoice = 0;				//User choice for menu
	double priceTotal = 0.0;
	
	bool finished = false;
	char yORn;

	while (!finished) {

		menu.displayList();
		cout << "\n\nEnter your selection: ";
		cin >> userChoice;

		switch (userChoice) {

		case 1:

			priceTotal += 1.45;

		case 2:

			priceTotal += 2.45;

		case 3:

			priceTotal += .99;

		case 4:

			priceTotal += 1.99;

		case 5:

			priceTotal += 2.49;

		case 6:

			priceTotal += .69;			//NICE

		case 7:

			priceTotal += .50;

		case 8:

			priceTotal += .75;
		}

		cout << "\n\n\nAre you finished selecting menu items? (Y/N)";
		cin >> yORn;

		if (yORn == 'Y' || yORn == 'y') {

			finished = true;
		}

		else {

			finished = false;
		}

	}


	cout << "\n\n\n\nAmount Due: $" << (priceTotal * TAX) + priceTotal;

	system("pause");
	return 0;
}