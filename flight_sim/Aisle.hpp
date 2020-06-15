/**************************************************************************
 ** Class Name:  Aisle
 ** Author:      Ryan Adams
 ** Date:        12/10/2019
 ** Description: Header file for the Aisle class.
 *************************************************************************/

#ifndef AISLE_HPP
#define AISLE_HPP

#include "Space.hpp"
#include <string>
using std::string;

enum BIN_STATUS { empty = 1, contains_pillow, contains_blanket, contains_earphones, contains_drink_ticket, full };

class Aisle : public Space {
public:

/*************************************************************************
 ** Description: Default constructor that initializes all member variables
 **                according to the characteristics of this type of space.
 ************************************************************************/
	Aisle();

/*************************************************************************
 ** Description: Pure virtual function that causes the player to interact
 **                this space object. The type of interaction depends
 **                on the type of space. Will return an int representing
 **                the impact the interaction has on the player's patience
 **                gauge.
 ************************************************************************/
	int interact(ItemBag&);

/*************************************************************************
 ** Description: Pure virtual function that triggers a consequence when
 **                moving to this space object. The consequence depends
 **                on the type of space. Will return an int representing
 **                the impact the consequence has on the player's patience
 **                gauge.
 ************************************************************************/
	int stepOn();

/*************************************************************************
 ** Description: Setter function for status variable.
 ************************************************************************/
	void setStatus(BIN_STATUS);

protected:

	// Variables unique to this derived class.
	BIN_STATUS status;

};
#endif
