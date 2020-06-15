/****************************************************************************
 ** Class Name:  Person
 ** Author:      Ryan Adams
 ** Date:        12/10/2019
 ** Description: The Person class is a derived class from the base Space
 **                class. It has a default constructor that initializes the
 **                member variables according to this class's characteristics.
 ***************************************************************************/

#include "Person.hpp"
#include "Menu.hpp"
#include "askForInt.hpp"
#include <string>
using std::string;

/*************************************************************************
 ** Description: Default constructor that initializes all member variables
 **                according to the characteristics of this type of space.
 ************************************************************************/
Person::Person()
{
	icon = '#';
	interactOpt = "Give the seated passenger an item";
	charmed = false;

	// Giving person a random problem that is solved by a specific item.
	int randomNum = ((rand() % 4) + 2);
	switch (randomNum) {
		case 2: {
			problem = neck_pain;
			break;
		}
		case 3: {
			problem = cold;
			break;
		}
		case 4: {
			problem = mute_phone;
			break;
		}
		case 5: {
			problem = stressed;
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
int Person::interact(ItemBag &bag) {

	// Checking if player has items to give.
	if (bag.getNumItems() == 0) {
		cout << "You have no items to give.";
		return 0;
	}

	cout << "Which item do you want to give?" << endl;
	bag.displayItems();
	int itemChoice = askForInt(1, bag.getNumItems());
	cout << endl;

	PROBLEM_TYPES itemToGive = static_cast<PROBLEM_TYPES>(bag.getItemAt(itemChoice - 1));

	// Displaying positive message if item is the solution to their problem.
	if (itemToGive == problem) {
		cout << "Passenger: \"Wow, thanks. Thanks very kind of you!\"" << endl
			<< "The stewardess sees your act of kindness and smiles. [+2 patience]" << endl;
		right->setAvailable(true);
		return 2;
	}
	// Else displaying negative message.
	else {
		cout << "Passenger: \"Why would I want this?...\"" << endl
			<< "The stewardess sees you annoying the passenger. [-2 patience]" << endl;
		return -2;
	}
}

/*************************************************************************
 ** Description: Pure virtual function that triggers a consequence when
 **                moving to this space object. The consequence depends
 **                on the type of space. Will return an int representing
 **                the impact the consequence has on the player's patience
 **                gauge.
 ************************************************************************/
int Person::stepOn() {
	cout << "You are standing next to a person sitting in a seat." << endl
		<< "They are visibly uncomfortable and the stewardess notices this. [-1 patience]" << endl;

	// Displaying special message depending on person's random problem.
	switch (problem) {
		case 2: {
			cout << "They keep moving their head around. Looks like they're uncomfortable..." << endl;
			break;
		}
		case 3: {
			cout << "They keep shivering. Looks like they're a bit chilly..." << endl;
			break;
		}
		case 4: {
			cout << "They are watching a video on mute. It'd probably be more enjoyable with sound..." << endl;
			break;
		}
		case 5: {
			cout << "They seem super stressed. I know what I would do if I was that stressed..." << endl;
			break;
		}
	}
	return -1;
}
