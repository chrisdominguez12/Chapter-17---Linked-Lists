#pragma once
#ifndef BREAKFASTBILLING_H
#define BREAKFASTBILLING_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class BreakfastBilling {

protected: 

	//Struct for the list node
	struct listNode {

		double price;
		string itemName;
		listNode *next;

		listNode(string itemName, double price, listNode *next = NULL) {

			this->price = price;
			this->itemName = itemName;
			this->next = next;
		}
	};

	listNode *head;					//List head pointer



public: 


	//Constructor
	BreakfastBilling() {

		head = NULL;
	}


	//Destructor
	~BreakfastBilling() {

		listNode *nodePtr = head;		//Start at head of list
		while (nodePtr != NULL) {

			//'garbage' variable keeps track of node to be deleted
			listNode *garbage = nodePtr;

			//Move on to the next node if any
			nodePtr = nodePtr->next;

			//delete the 'garbage' node
			delete garbage;
		}
	}


	void add(string itemName, double price) {

		if (head == NULL) {

			head = new listNode(itemName, price);
		}

		else {

			//The list is not empty, use nodePtr to move through the list
			listNode *nodePtr = head;
			while (nodePtr->next != NULL) {

				nodePtr = nodePtr->next;

				//nodePtr->next is NULL, nodePtr points to the last node
				//create a new node and put it after the last node
				nodePtr->next = new listNode(itemName, price);
			}
		}

	}


	void displayList() {

		listNode *nodePtr = head;			//Start at the head of the list

		//Counter variable is only here for the current use case of displaying a menu for user.
		//Otherwise, displaying a linked list does not require this variable present
		int i = 1;							
		while (nodePtr != NULL) {

			//print the data in the current node
			cout << i << ".  " << nodePtr->itemName << "\t\t\t\t$" << nodePtr->price << endl;
			

			//Move on to the next node
			nodePtr = nodePtr->next;
			i++;
		}
	}


};
#endif // !BREAKFASTBILLING_H

