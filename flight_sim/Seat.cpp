/****************************************************************************
 ** Class Name:  Seat
 ** Author:      Ryan Adams
 ** Date:        12/10/2019
 ** Description: The Seat class is a derived class from the base Space
 **                class. It has a default constructor that initializes the
 **                member variables according to this class's characteristics.
 ***************************************************************************/

#include "Seat.hpp"

/*************************************************************************
 ** Description: Default constructor that initializes all member variables
 **                according to the characteristics of this type of space.
 ************************************************************************/
Seat::Seat()
{
	icon = 'O';
	interactOpt = "Sit in the empty seat";
	available = false;
}

/*************************************************************************
 ** Description: Pure virtual function that causes the player to interact
 **                this space object. The type of interaction depends
 **                on the type of space. Will return an int representing
 **                the impact the interaction has on the player's patience
 **                gauge.
 ************************************************************************/
int Seat::interact(ItemBag &bag) {
	cout << "You attempt to sit down...";

	// Negative message if you still have your luggage.
	if (bag.getItemAt(0) == 1) {
		cout << "but you still have your luggage." << endl
			<< "The stewardess seems annoyed by your luggage in the aisle. [-1 patience]" << endl;
		return -1;
	}
	else if (available == false){
		cout << "but the passenger in the next seat said it is taken." << endl
			<< "The stewardess seems annoyed by you disturbing the seated passengers. [-1 patience]" << endl
			<< "Maybe you could convince the other passenger somehow..." << endl;
		return -1;
	}
	else {
		cout << "and the passenger in the next seat says \"Welcome!\"" << endl;
		playerSitting = true;
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
int Seat::stepOn() {
	cout << "You are standing next to an empty seat. The person sitting in the adjacent seat is eyeing you closely." << endl;
	return 0;
}