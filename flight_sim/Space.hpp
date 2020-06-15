/**************************************************************************
 ** Class Name:  Space
 ** Author:      Ryan Adams
 ** Date:        12/10/2019
 ** Description: Header file for the Space class.
 *************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include "ItemBag.hpp"
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

class Space {
public:

/*************************************************************************
 ** Description: Default constructor that initializes pointers.
 ************************************************************************/
	Space();

/*************************************************************************
 ** Description: Pure virtual destructor to ensure that the Space class is
 **                abstract and cannot be instantiated.
 ************************************************************************/
	virtual ~Space() = 0;

/*************************************************************************
 ** Description: Setter function for top variable.
 ************************************************************************/
	void setTop(Space*);

/*************************************************************************
 ** Description: Setter function for bottom variable.
 ************************************************************************/
	void setBottom(Space*);

/*************************************************************************
 ** Description: Setter function for left variable.
 ************************************************************************/
	void setLeft(Space*);

/*************************************************************************
 ** Description: Setter function for right variable.
 ************************************************************************/
	void setRight(Space*);

/*************************************************************************
 ** Description: Setter function for available variable.
 ************************************************************************/
	void setAvailable(bool);

/*************************************************************************
 ** Description: Getter function for top variable.
 ************************************************************************/
	Space* getTop();

/*************************************************************************
 ** Description: Getter function for bottom variable.
 ************************************************************************/
	Space* getBottom();

/*************************************************************************
 ** Description: Getter function for left variable.
 ************************************************************************/
	Space* getLeft();

/*************************************************************************
 ** Description: Getter function for right variable.
 ************************************************************************/
	Space* getRight();

/*************************************************************************
 ** Description: Getter function for icon variable.
 ************************************************************************/
	char getIcon();

/*************************************************************************
 ** Description: Getter function for playerSitting variable.
 ************************************************************************/
	virtual bool getPlayerSitting();

/*************************************************************************
 ** Description: Pure virtual function that causes the player to interact
 **                this space object. The type of interaction depends
 **                on the type of space. Will return an int representing
 **                the impact the interaction has on the player's patience
 **                gauge.
 ************************************************************************/
	virtual int interact(ItemBag&) = 0;

/*************************************************************************
 ** Description: Pure virtual function that triggers a consequence when
 **                moving to this space object. The consequence depends
 **                on the type of space. Will return an int representing
 **                the impact the consequence has on the player's patience
 **                gauge.
 ************************************************************************/
	virtual int stepOn() = 0;

/*************************************************************************
 ** Description: Getter function for interactOpt variable.
 ************************************************************************/
	string getInteractOpt();

protected:

	// Pointers to connect spaces.
	Space* top;
	Space* bottom;
	Space* left;
	Space* right;

	// Variables to store information about the Space.
	char icon;
	string interactOpt;
	bool available;
	bool playerSitting;
};
#endif
