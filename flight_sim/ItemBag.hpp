/**************************************************************************
 ** Class Name:  ItemBag
 ** Author:      Ryan Adams
 ** Date:        12/10/2019
 ** Description: Header file for the ItemBag class.
 *************************************************************************/

#ifndef ITEM_BAG_HPP
#define ITEM_BAG_HPP

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

enum ITEM_TYPES { empt = 0, luggage, pillow, blanket, earphones, drink_ticket };

class ItemBag {
public:

/*************************************************************************
 ** Description: Default constructor that initializes member variables.
 ************************************************************************/
	ItemBag();

/*************************************************************************
 ** Description: Function that displays items currently in the bag.
 ************************************************************************/
	void displayItems();

/*************************************************************************
 ** Description: Removes item at array location specified in parameter.
 ************************************************************************/
	void removeItemAt(int);

/*************************************************************************
 ** Description: Adds an item specified by parameter to the end of the bag.
 ************************************************************************/
	void addItem(int);

/*************************************************************************
 ** Description: Getter function for numItems variable.
 ************************************************************************/
	int getNumItems();

/*************************************************************************
 ** Description: Getter function for ITEM_TYPES at array location
 **                specified in parameter.
 ************************************************************************/
	int getItemAt(int);

protected:

	// Variables to store information about the ItemBag.
	ITEM_TYPES items[5] = {empt, empt, empt, empt, empt};
	int numItems;

};
#endif
