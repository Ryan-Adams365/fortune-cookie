/**************************************************************************
 ** Class Name:  LinkedMap
 ** Author:      Ryan Adams
 ** Date:        12/10/2019
 ** Description: Header file for the LinkedMap class. Includes declaration for
 **                the LinkedMapNode struct used by the LinkedMap.
 *************************************************************************/

#ifndef LINKED_MAP_HPP
#define LINKED_MAP_HPP

#include "Space.hpp"
#include "Person.hpp"
#include "Seat.hpp"
#include "Aisle.hpp"

class LinkedMap {
public:

/*************************************************************************
 ** Description: Constructor that creates a map of spaces and initializes
 **                the array of head pointers and the player pointer.
 ************************************************************************/
  LinkedMap();

/*************************************************************************
 ** Description: Destructor that frees memory and ensures no dangling
 **                pointers.
 ************************************************************************/
  ~LinkedMap();

/*************************************************************************
 ** Description: Function that creates a Node object and has the tail
 **                pointer point to it.
 ************************************************************************/
  void addTail(int, Space*);

/*************************************************************************
 ** Description: Function that returns the player pointer.
 ************************************************************************/
  Space* getPlayer();

/*************************************************************************
 ** Description: Function that takes in an int representing the column to
 **                work with. Changes the head pointer in that column to
 **                point to the bottom space it's linked to and deletes
 **                the current head space.
 ************************************************************************/
  void removeHead(int);

/*************************************************************************
 ** Description: Function that prints the map of spaces using the icons
 **                for each space.
 ************************************************************************/
  void printLinkedMap();

/*************************************************************************
 ** Description: Function that moves the player pointer based on the
 **              passed int value.
 ************************************************************************/
  int movePlayer(int);

protected:
  
  Space* headArray[8];
  Space* tailArray[8];
  Space* player;

};
#endif
