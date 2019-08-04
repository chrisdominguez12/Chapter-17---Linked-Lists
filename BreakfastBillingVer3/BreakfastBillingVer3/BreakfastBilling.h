#pragma once
#ifndef BREAKFASTBILLING_H
#define BREAKFASTBILLING_H

#include <iostream>
#include <string>

using namespace std;

class BreakfastBilling {

protected: 

	struct listNode {

		double price;
		string itemName;
		listNode *next;

		listNode(double price, string itemName, listNode *next = NULL) {

			this->price = price;
			this->itemName = itemName;
			this->next = next;
		}

	}; //End of struct

	listNode *head = NULL;			//head of list pointer


public: 

	//Adds a new node to the list
	void add(double price, string itemName) {

		if (head == NULL) {

			head = new listNode(price, itemName);
		} //end of if

		else {

			//The list is not empty, nodePrt is used to move through the list
			listNode *nodePtr = head;
			while (nodePtr->next != NULL) {

				nodePtr = nodePtr->next;
			} //End of while

			//nodePtr->next is NULL, nodePtr points to the last node.
			//Create a new a node and put it after the last node
			nodePtr->next = new listNode(price, itemName);
		} //end of else
	}




	//Display the whole list
	void displayList() {

		listNode *nodePtr = head;			//Start at the head of the list

		int i = 1;

		while (nodePtr) {

			//Print the data in the current node
			cout << i << ".\t\t" << nodePtr->itemName << "\t\t\t\t$" << nodePtr->price << endl;

			//Move on to the next node in the list
			nodePtr = nodePtr->next;
			i++;
		}	//End of while
	}
};
#endif // !BREAKFASTBILLING_H
