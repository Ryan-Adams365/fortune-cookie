/**************************************************************************
 ** Class Name:  Menu
 ** Author:      Ryan Adams
 ** Date:        11/24/2019
 ** Description: Header file for the Menu class.
 *************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <string>
using std::string;

class Menu{

  // Private member variables and functions.
  private:

    string prompt;
    int optCount;
    string* optArray;

  // Public member functions.
  public:

  /*************************************************************************
   ** Description: Default constructor that initializes a generic prompt
   **                with only yes and no options.
   ************************************************************************/
    Menu();

/*************************************************************************
 ** Description: Constructor that takes in a string and uses it to
 **                initialize the prompt and first two options.
 ************************************************************************/
    Menu(string, string, string);

/*************************************************************************
 ** Description: Destructor the frees memory from the dynamic array.
 ************************************************************************/
    ~Menu();

/*************************************************************************
 ** Description: Function to add an option to optArray. Will create
 **                a new dynamic array of size optionCount + 1 called
 **                tempArray. Then uses tempArray as a placeholder
 **                to create a new options array with the added option.
 ************************************************************************/
    void add(string);

/*************************************************************************
 ** Description: Function to remove an option to optArray. Will create
 **                a new dynamic array of size optionCount - 1 called
 **                tempArray. Then uses tempArray as a placeholder
 **                to create a new options array without the last option.
 **                optCount cannot go below 2 and if this method is called
 **                when optCount is 2, then it will return an error.
 ************************************************************************/
    void remove();
    
/*************************************************************************
 ** Description: Function to change the prompt. Takes a string parameter
 **                and uses it to change the menu's initial prompt.
 ************************************************************************/
    void change(string);

/*************************************************************************
 ** Description: Function to change an option. Takes a string parameter
 **                and uses it to change the option on the menu whose
 **                matches the int parameter (so if optNum = 1, then
 **                option 1 on the menu will change). If optNum does not
 **                correspond to a menu option, then it will return an
 **                error.
 ************************************************************************/
    void change(string, int);

/*************************************************************************
 ** Description: Function to display the prompt and options and elicit
 **                a user input. After user input is obtained, will
 **                validate that it was a valid input (which is an int
 **                that corresponds to a menu option). If it is not valid
 **                will continue to loop until a valid input is obtained.
 **                Floats and ints followed by other inputs will be
 **                truncated down. Returns the validated int.
 ************************************************************************/
    int ask();

};
#endif
