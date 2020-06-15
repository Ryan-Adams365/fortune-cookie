/****************************************************************************
 ** Class Name:  Aisle
 ** Author:      Ryan Adams
 ** Date:        12/10/2019
 ** Description: The Aisle class is a derived class from the base Space
 **                class. It has a default constructor that initializes the
 **                member variables according to this class's characteristics.
 ***************************************************************************/

#include "Aisle.hpp"

/*************************************************************************
 ** Description: Default constructor that initializes all member variables
 **                according to the characteristics of this type of space.
 ************************************************************************/
Aisle::Aisle()
{
	icon = ' ';
	interactOpt = "Look in the overhead bin";
	available = false;

	// Giving overhead bin a random status.
	int randomNum = ((rand() % 6) + 1);
	switch (randomNum) {
		case 1: {
			status = empty;
			break;
		}
		case 2: {
			status = contains_pillow;
			break;
		}
		case 3: {
			status = contains_blanket;
			break;
		}
		case 4: {
			status = contains_earphones;
			break;
		}
		case 5: {
			status = contains_drink_ticket;
			break;
		}
		case 6: {
			status = full;
			break;
		}
	}
}

/*************************************************************************
 ** Description: Pure virtual function that causes the player to interact
 **                this space object. The type of interaction depends
 **                on the type of space. Will return an int representing
 **                the impact the interaction has on the player's patience
 **                gauge.
 ************************************************************************/
int Aisle::interact(ItemBag& bag) {
	cout << "You looked in the overhead bin...";

	// Displayed message depends on the bin status.
	switch (status) {
		case 1: {
			cout << "it's empty!" << endl;

			// Checking to see if there is still luggage to put away.
			if (bag.getItemAt(0) != 1) {
				cout << "You've already put away your luggage." << endl;
			}
			else {
				cout << "You put your luggage in the overhead bin." << endl;
				bag.removeItemAt(0);
			}
			break;
		}
		case 2: {
			cout << "it's has a pillow!" << endl;
			bag.addItem(2);
			break;
		}
		case 3: {
			cout << "it's has a blanket!" << endl;
			bag.addItem(3);
			break;
		}
		case 4: {
			cout << "it's has some earphones!" << endl;
			bag.addItem(4);
			break;
		}
		case 5: {
			cout << "it's has a drink ticket!" << endl;
			bag.addItem(5);
			break;
		}
		case 6: {
			cout << "it's full of luggage." << endl;
			break;
		}
	}
	return 0;
}

/*************************************************************************
 ** Description: Pure virtual function that triggers a consequence when
 **                moving to this space object. The consequence depends
 **                on the type of space. Will return an int representing
 **                the impact the consequence has on the player's patience
 **                gauge.
 ************************************************************************/
int Aisle::stepOn() {
	cout << "You are in an aisle. The stewardess is eyeing you closely." << endl;
	return 0;
}

/*************************************************************************
 ** Description: Setter function for status variable.
 ************************************************************************/
void Aisle::setStatus(BIN_STATUS statusIn) {
	status = statusIn;
	return;
}