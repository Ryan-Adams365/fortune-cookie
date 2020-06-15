/****************************************************************************
 ** Class Name:  Space
 ** Author:      Ryan Adams
 ** Date:        12/10/2019
 ** Description: The Space class is an abstract class that will be derived
 **              by other classes. It contains getter and setter functions
 **              for all member variables.
 ***************************************************************************/

#include "Space.hpp"
#include <stdlib.h>

/*************************************************************************
 ** Description: Default constructor that initializes pointers.
 ************************************************************************/
Space::Space() {
	top = nullptr;
	bottom = nullptr;
	left = nullptr;
	right = nullptr;
	playerSitting = false;
}

/*************************************************************************
 ** Description: Pure virtual destructor to ensure that the Space class is
 **                abstract and cannot be instantiated.
 ************************************************************************/
Space::~Space() {};

/*************************************************************************
 ** Description: Setter function for top variable.
 ************************************************************************/
void Space::setTop(Space* topIn) {
	top = topIn;
	return;
}

/*************************************************************************
 ** Description: Setter function for bottom variable.
 ************************************************************************/
void Space::setBottom(Space* bottomIn) {
	bottom = bottomIn;
	return;
}

/*************************************************************************
 ** Description: Setter function for left variable.
 ************************************************************************/
void Space::setLeft(Space* leftIn) {
	left = leftIn;
	return;
}

/*************************************************************************
 ** Description: Setter function for right variable.
 ************************************************************************/
void Space::setRight(Space* rightIn) {
	right = rightIn;
	return;
}

/*************************************************************************
 ** Description: Getter function for top variable.
 ************************************************************************/
Space* Space::getTop() {
	return top;
}

/*************************************************************************
 ** Description: Getter function for bottom variable.
 ************************************************************************/
Space* Space::getBottom() {
	return bottom;
}

/*************************************************************************
 ** Description: Getter function for left variable.
 ************************************************************************/
Space* Space::getLeft() {
	return left;
}

/*************************************************************************
 ** Description: Getter function for right variable.
 ************************************************************************/
Space* Space::getRight() {
	return right;
}

/*************************************************************************
 ** Description: Getter function for icon variable.
 ************************************************************************/
char Space::getIcon() {
	return icon;
}

/*************************************************************************
 ** Description: Getter function for interactOpt variable.
 ************************************************************************/
string Space::getInteractOpt() {
	return interactOpt;
}

/*************************************************************************
 ** Description: Getter function for playerSitting variable.
 ************************************************************************/
bool Space::getPlayerSitting() {
	return playerSitting;
}

/*************************************************************************
 ** Description: Setter function for available variable.
 ************************************************************************/
void Space::setAvailable(bool statusIn) {
	available = statusIn;
}