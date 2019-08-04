#include "BreakfastBilling.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

	BreakfastBilling list; 

	list.add("Plain Egg", 1.45);
	list.add("Bacon and Egg", 2.45);
	list.add("Muffin", .99);
	list.add("French Toast", 1.99);
	list.add("Fruit Basket", 2.49);
	list.add("Cereal", .69);			
	list.add("Coffee", .50);
	list.add("Tea", .75);

	bool finished = false;				//Exit condition for while loop
	char userAns;

	const double TAX = .05;
	int userChoice = 0;					//User selection
	double priceTotal = 0.0;			//Running total of item prices

	while (!finished) {

		list.displayList();
		cout << "\nEnter your selection: ";
		cin >> userChoice;

		switch (userChoice) {

		case 1:

			priceTotal += 1.45;
			break;

		case 2:

			priceTotal += 2.45;
			break;

		case 3:

			priceTotal += .99;
			break;

		case 4:

			priceTotal += 1.99;
			break;

		case 5: 

			priceTotal += 2.49;
			break;

		case 6: 

			priceTotal += .69;			//NICE
			break;

		case 7:

			priceTotal += .50;
			break;

		case 8:

			priceTotal += .75;
			break;
		}

		cout << "\n\n\nAre you finished selecting menu items? (Y/N)";
		cin >> userAns;

		if (userAns == 'Y' || userAns == 'y') {

			finished = true;
		}

		else {

			finished = false;
		}

	}

	double finalCharge = priceTotal + (priceTotal * TAX);
	cout << "\n\n\n\nAmount Due: $" << finalCharge;

	system("pause");
	return 0;
}

