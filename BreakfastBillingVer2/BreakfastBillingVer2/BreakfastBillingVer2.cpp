#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct listNode {

	double price;
	string itemName;
	listNode *next;
	
	listNode() {

		itemName = " ";
		price = 0.0;
		next = NULL;
	}

	listNode(string itemName, double price, listNode *next = NULL) {

		this->itemName = itemName;
		this->price = price;
		this->next = next;

	}
};

listNode *head = NULL;			//list head pointer


//Functions
void add(string itemName, double price) {

	if (head == NULL) {

		head = new listNode(itemName, price);
	}

	else {

		//The list is not empty, use nodePtr to more through the list
		listNode *nodePtr = head;
		while (nodePtr->next != NULL) {

			nodePtr = nodePtr->next;

			//nodePtr->next is NULL, nodePtr points to the last node
			//Create a new node and put it after the last node
			nodePtr->next = new listNode(itemName, price);
		}
	}
}


void displayList() {

	listNode *nodePtr = head;			//Start at the head of the list

	//Counter variable is only present for the current use case
	//Otherwise, displaying a linked list does not require this variable

	int i = 1;
	while (nodePtr) {

		//Print the data in the current node
		cout << i << ".\t\t" << nodePtr->itemName << "\t\t\t\t$" << nodePtr->price << endl;

		//Move on the next node
		nodePtr = nodePtr->next;
		i++;
	}
}


int main() {


	add("Plain Egg", 1.45);
	add("Bacon and Egg", 2.45);
	add("Muffin", .99);
	add("French Toast", 1.99);
	add("Fruit Basket", 2.49);
	add("Cereal", .69);
	add("Coffee", .50);
	add("Tea", .75);

	bool finished = true;				//Exit condition for while loop
	char userAns;

	double TAX = .05;
	int userChoice = 0;					//User selection
	double priceTotal = 0.0;			//Running total of item prices

	while (finished) {

		displayList();
		cout << "\nEnter your selection: ";
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
		cin >> userAns;

		if (userAns == 'Y' || userAns == 'y') {

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



