/****************************************************************************
 ** Class Name:  ItemBag
 ** Author:      Ryan Adams
 ** Date:        12/10/2019
 ** Description: The ItemBag class is an abstract class 
 ***************************************************************************/

#include "ItemBag.hpp"
#include <stdlib.h>

/*************************************************************************
 ** Description: Default constructor that initializes array of items.
 ************************************************************************/
ItemBag::ItemBag() {
	items[0] = luggage;
	numItems = 1;
}

/*************************************************************************
 ** Description: Function that displays items currently in the bag.
 ************************************************************************/
void ItemBag::displayItems() {

	// Display message if bag has no items.
	if (numItems == 0) {
		cout << "You are currently holding no items. You can pick up 5 more items." << endl;
		return;
	}

	cout << "You are currently holding:" << endl;

	// Loop that goes through each item in the array.
	for (int i = 0; i < numItems; i++) {
		// Switch to display correct item name depending on value in array.
		switch (items[i]) {
			case 1: {
				cout << (i + 1) << ". Luggage" << endl;
				break;
			}
			case 2: {
				cout << (i + 1) << ". Pillow" << endl;
				break;
			}
			case 3: {
				cout << (i + 1) << ". Blanket" << endl;
				break;
			}
			case 4: {
				cout << (i + 1) << ". Earphones" << endl;
				break;
			}
			case 5: {
				cout << (i + 1) << ". Drink Ticket" << endl;
				break;
			}
		}
	}

	cout << endl << "You can hold " << (5 - numItems) << " more items." << endl;

	return;
}

/*************************************************************************
 ** Description: Getter function for numItems variable.
 ************************************************************************/
int ItemBag::getNumItems() {
	return numItems;
}

/*************************************************************************
 ** Description: Getter function for ITEM_TYPES at array location
 **                specified in parameter.
 ************************************************************************/
int ItemBag::getItemAt(int pos) {
	return static_cast<int>(items[pos]);
}

/*************************************************************************
 ** Description: Removes item at array location specified in parameter.
 ************************************************************************/
void ItemBag::removeItemAt(int pos) {

	// Loop to go from position specified in parameter through rest of items.
	for (int i = pos; i < numItems; i++) {
		if (i == (numItems - 1)) {
			items[i] == 0;
		}
		else {
			items[i] = items[i + 1];
		}
	}
	numItems--;
	return;
}

/*************************************************************************
 ** Description: Adds an item specified by parameter to the end of the bag.
 ************************************************************************/
void ItemBag::addItem(int toAdd) {

	if (numItems == 5) {
		cout << "You can't carry any more items." << endl;
	}
	else {
		items[numItems] = static_cast<ITEM_TYPES>(toAdd);
		numItems++;
	}
	return;
}