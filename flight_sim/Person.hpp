/**************************************************************************
 ** Class Name:  Person
 ** Author:      Ryan Adams
 ** Date:        12/10/2019
 ** Description: Header file for the Person class.
 *************************************************************************/

#ifndef PERSON_HPP
#define PERSON_HPP

#include "Space.hpp"
#include "ItemBag.hpp"

enum PROBLEM_TYPES { neck_pain = 2, cold, mute_phone, stressed };

class Person : public Space {
public:

/*************************************************************************
 ** Description: Default constructor that initializes all member variables
 **                according to the characteristics of this type of space.
 ************************************************************************/
	Person();

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

protected:

	// Variables unique to this derived class.
	PROBLEM_TYPES problem;
	bool charmed;
};
#endif
