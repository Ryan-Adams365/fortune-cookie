/****************************************************************************
 ** Class Name:  LinkedMap
 ** Author:      Ryan Adams
 ** Date:        12/10/2019
 ** Description: Class creates a map of spaces that are linked by four pointers.
 **              It creates the game board through the constructor and addTail
 **              functions. It controls the flow of the game through the
 **              movePlayer and display functions. It has a destructor that
 **              frees all memory.
 ***************************************************************************/

#include "LinkedMap.hpp"
#include <iostream>
using std::cout;
using std::endl;

/*************************************************************************
 ** Description: Constructor that creates a map of spaces and initializes
 **                the array of head pointers and the player pointer.
 ************************************************************************/
LinkedMap::LinkedMap() {

	// Loop for each row.
	for (int i = 0; i < 8; i++) {

		// Loop for each column.
		for (int j = 0; j < 8; j++) {

			// Switch to determine type of Space to create based on column.
			Space* newSpace = nullptr;
			switch (j) {
				case 0: {
					newSpace = new Person();
					break;
				}
				case 1: {
					newSpace = new Seat();
					break;
				}
				case 2: {
					newSpace = new Aisle();
					break;
				}
				case 3: {
					newSpace = new Person();
					break;
				}
				case 4: {
					newSpace = new Seat();
					break;
				}
				case 5: {
					newSpace = new Aisle();
					break;
				}
				case 6: {
					newSpace = new Person();
					break;
				}
				case 7: {
					newSpace = new Seat();
					break;
				}
			}

			// Add new space to tail of current column.
			addTail(j, newSpace);

			// Linking each space after the first column to the space object in the previous column.
			if (j != 0) {

				// Space in previous column will point to space in this column with right.
				tailArray[j - 1]->setRight(tailArray[j]);

				// Space in this column will point to space in previous column with left.
				tailArray[j]->setLeft(tailArray[j - 1]);
			}
		}
	}

	// Initializing player pointer to player's starting space.
	player = tailArray[2];
}

/*************************************************************************
 ** Description: Destructor that frees memory and ensures no dangling
 **                pointers.
 ************************************************************************/
LinkedMap::~LinkedMap() {
	// Freeing memory of all spaces in each column.
	for (int i = 0; i < 3; i++) {
		while (headArray[i] != nullptr) {
			removeHead(i);
		}
	}
}

/*************************************************************************
 ** Description: Function that takes in an int representing the column
 **                to work on and a pointer to a space object. Will add
 **                the pointer to the tail of the column.
 ************************************************************************/
void LinkedMap::addTail(int column, Space* newSpace)
{

	if (tailArray[column] == nullptr) {

		// Setting head and tail to now point to the new node.
		headArray[column] = newSpace;
		tailArray[column] = newSpace;
	}
	else {
		// New space will be at tail, so will point to previous tail with top.
		newSpace->setTop(tailArray[column]);

		// Previous tail space will now point to the new space with bottom.
		tailArray[column]->setBottom(newSpace);

		// Setting tail to now point to the new node.
		tailArray[column] = newSpace;
	}

	return;
}

/*************************************************************************
 ** Description: Function that returns the player pointer.
 ************************************************************************/
Space* LinkedMap::getPlayer() {
	return player;
}

/*************************************************************************
 ** Description: Function that takes in an int representing the column to
 **                work with. Changes the head pointer in that column to
 **                point to the bottom space it's linked to and deletes
 **                the current head space.
 ************************************************************************/
void LinkedMap::removeHead(int column) {
	
	// Case for only 1 space in the column.
	if (headArray[column]->getBottom() == nullptr){
		// Freeing memory from head.
		delete headArray[column];
		headArray[column] = nullptr;
		tailArray[column] = nullptr;
	}
	// Case for 2+ spaces in the column.
	else {
		// Creating temp pointer to head.
		Space* tempHead = headArray[column];

		// Setting current head's bottom space as the new head.
		headArray[column] = headArray[column]->getBottom();

		// New head space will now point to null with top.
		headArray[column]->setTop(nullptr);

		// Deleting previous head to free memory.
		delete tempHead;
	}

	return;
}

/*************************************************************************
 ** Description: Function that prints the map of spaces using the icons
 **                for each space.
 ************************************************************************/
void LinkedMap::printLinkedMap() {

	// Creating temp pointers that initially point to head pointer of first column.
	Space* tempRow = headArray[0];
	Space* tempCol = headArray[0];

	// Loop that will iterate through rows until bottom pointer is nullptr.
	while (tempRow != nullptr) {

		// If this is the first row, print border.
		if (tempRow->getTop() == nullptr) {
			cout << "\t=";
			while (tempCol != nullptr) {
				cout << '=';
				tempCol = tempCol->getRight();
			}
			cout << '=' << endl;
		}

		// Setting tempCol to be the start of the current row.
		tempCol = tempRow;

		// Loop that will iterate through the spaces in each column for the current row.
		cout << '\t';
		while (tempCol != nullptr) {

			// If this is the first column, print border.
			if (tempCol->getLeft() == nullptr) {
				cout << '|';
			}

			// Checking to see if this is where the player is.
			if (tempCol == player) {
				// Printing player icon.
				cout << '@';
			}
			else {
				// Printing icon for current space.
				cout << tempCol->getIcon();
			}

			// Iterating to next column.
			tempCol = tempCol->getRight();

			// If this was the last column, print border.
			if (tempCol == nullptr) {
				cout << '|';
			}
		}
		cout << endl;

		// Iterating to next row.
		tempCol = tempRow;
		tempRow = tempRow->getBottom();

		// If this is the last row, print border.
		if (tempRow == nullptr) {
			cout << "\t=";
			while (tempCol != nullptr) {
				cout << '=';
				tempCol = tempCol->getRight();
			}
			cout << '=' << endl << endl;
		}

	}

	return;
}

/*************************************************************************
 ** Description: Function that moves the player pointer based on the
 **                passed int value. Returns int value representing the
 **                move's impact on player's patience gauge.
 ************************************************************************/
int LinkedMap::movePlayer(int direction) {

	// Switch to move player in direction specified by passesd int. Will
	//   print error if player cannot move that direction.
	switch (direction) {
		case 0: {
			if (player->getTop() == nullptr) {
				system("clear");
				this->printLinkedMap();
				cout << "You run into the wall of the plane." << endl
					<< "The stewardess shakes her head and sighs. [-1 patience]" << endl;
				return -1;
			}
			else {
				player = player->getTop();
				system("clear");
				this->printLinkedMap();
				return player->stepOn();
			}
			break;
		}
		case 1: {
			if (player->getRight() == nullptr) {
				system("clear");
				this->printLinkedMap();
				cout << "You run into the wall of the plane." << endl
					<< "The stewardess shakes her head and sighs. [-1 patience]" << endl;
				return -1;
			}
			else {
				player = player->getRight();
				system("clear");
				this->printLinkedMap();
				return player->stepOn();
			}
			break;
		}
		case 2: {
			if (player->getBottom() == nullptr) {
				system("clear");
				this->printLinkedMap();
				cout << "You run into the wall of the plane." << endl
					<< "The stewardess shakes her head and sighs. [-1 patience]" << endl;
				return -1;
			}
			else {
				player = player->getBottom();
				system("clear");
				this->printLinkedMap();
				return player->stepOn();
			}
			break;
		}
		case 3: {
			if (player->getLeft() == nullptr) {
				system("clear");
				this->printLinkedMap();
				cout << "You run into the wall of the plane." << endl
					<< "The stewardess shakes her head and sighs. [-1 patience]" << endl;
				return -1;
			}
			else {
				player = player->getLeft();
				system("clear");
				this->printLinkedMap();
				return player->stepOn();
			}
			break;
		}
	}
}