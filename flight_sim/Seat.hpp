/**************************************************************************
 ** Class Name:  Seat
 ** Author:      Ryan Adams
 ** Date:        12/10/2019
 ** Description: Header file for the Seat class.
 *************************************************************************/

#ifndef SEAT_HPP
#define SEAT_HPP

#include "Space.hpp"
#include <string>
using std::string;

class Seat : public Space {
public:

/*************************************************************************
 ** Description: Default constructor that initializes all member variables
 **                according to the characteristics of this type of space.
 ************************************************************************/
	Seat();

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
};
#endif
