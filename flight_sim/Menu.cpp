/****************************************************************************
 ** Class Name:  Menu
 ** Author:      Ryan Adams
 ** Date:        11/24/2019
 ** Description: Class creates a menu consisting of a prompt and options
 **                selected through a user-inputted integer. The default
 **                constructor initializes a generic prompt and 2 options
 **                and another constructor takes in 3 string parameters to
 **                initialize the prompt and first two options. The list
 **                of options is stored in a dynamic array. The add and
 **                remove public functions are used to add and remove options
 **                from the end of the array. The change public function is
 **                used to change an already added option or to change the
 **                prompt if no integer is passed through. The ask public
 **                function prints the prompt and numerically listed options,
 **                validates the user input, and returns the input. It has a
 **                destructor that frees the memory used by the dynamically
 **                allocated array.
 ***************************************************************************/

#include "Menu.hpp"
#include <limits>
using std::numeric_limits;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::streamsize;

#include <string>
using std::string;

/*************************************************************************
 ** Description: Default constructor that initializes a generic prompt
 **                with only yes and no options.
 ************************************************************************/
Menu::Menu(){

  prompt = "Please choose:";
  optCount = 2;
  optArray = new string[2];
  optArray[0] = "Yes";
  optArray[1] = "No";
}

/*************************************************************************
 ** Description: Constructor that takes in a string and uses it to
 **                initialize the prompt and first two options.
 ************************************************************************/
Menu::Menu(string promptIn, string optIn1, string optIn2){

  prompt = promptIn;
  optCount = 2;
  optArray = new string[2];
  optArray[0] = optIn1;
  optArray[1] = optIn2;
}

/*************************************************************************
 ** Description: Destructor the frees memory from the dynamic array.
 ************************************************************************/
Menu::~Menu(){

  delete [] optArray;
}

/*************************************************************************
 ** Description: Function to add an option to optArray. Will create
 **                a new dynamic array of size optionCount + 1 called
 **                tempArray. Then uses tempArray as a placeholder
 **                to create a new options array with the added option.
 ************************************************************************/
void Menu::add(string optIn){

  // Dynamically allocating a new array.
  string* tempArray = new string[optCount + 1];

  // Filling the tempArray with the values from optArray and the new option.
  for(int i=0; i<optCount; i++){
    tempArray[i] = optArray[i];
  }
  tempArray[optCount] = optIn;

  // Freeing memory.
  delete [] optArray;

  // Setting optArray to point to tempArray and tempArray to point to NULL.
  optArray = tempArray;
  tempArray = nullptr;

  optCount++;
  return;
}

/*************************************************************************
 ** Description: Function to remove an option to optArray. Will create
 **                a new dynamic array of size optionCount - 1 called
 **                tempArray. Then uses tempArray as a placeholder
 **                to create a new options array without the last option.
 **                optCount cannot go below 2 and if this method is called
 **                when optCount is 2, then it will return an error.
 ************************************************************************/
void Menu::remove(){

  // Checking that optCount > 2.
  if(optCount == 2){
    cout << "Error: You must have at least 2 options in your menu." << endl;
    return;
  }

  // Dynamically allocating a new array.
  string* tempArray = new string[optCount - 1];

  // Filling the tempArray with the values from optArray w/o the last option.
  for(int i=0; i<optCount-1; i++){
    tempArray[i] = optArray[i];
  }

  // Freeing memory.
  delete [] optArray;

  // Setting optArray to point to tempArray and tempArray to point to NULL.
  optArray = tempArray;
  tempArray = nullptr;

  optCount--;
  return;
}

/*************************************************************************
 ** Description: Function to change the prompt. Takes a string parameter
 **                and uses it to change the menu's initial prompt.
 ************************************************************************/
void Menu::change(string promptIn){

  // Changing prompt string.
  prompt = promptIn;
  return;
}

/*************************************************************************
 ** Description: Function to change an option. Takes a string parameter
 **                and uses it to change the option on the menu whose
 **                matches the int parameter (so if optNum = 1, then
 **                option 1 on the menu will change). If optNum does not
 **                correspond to a menu option, then it will return an
 **                error.
 ************************************************************************/
void Menu::change(string optIn, int optNum){

  // Validating the int parameter.
  if(optNum < 1 || optNum > optCount){
    cout << "Error: There is no menu option " << optNum << "." << endl
         << "Please pass an int parameter from 1 to " << optCount << "." << endl;
    return;
  }

  // Changing option string.
  optArray[optNum-1] = optIn;
  return;
}

/*************************************************************************
 ** Description: Function to display the prompt and options and elicit
 **                a user input. After user input is obtained, will
 **                validate that it was a valid input (which is an int
 **                that corresponds to a menu option). If it is not valid
 **                will continue to loop until a valid input is obtained. 
 **                Floats and ints followed by other inputs will be
 **                truncated down. Returns the validated int.
 ************************************************************************/
int Menu::ask(){

  string inputStr;
  int inputInt;
  bool inputError;

  do{
	inputError = false;

    // Printing the prompt and each option.
    cout << prompt << endl;
    for(int i=0; i<optCount; i++){
      cout << i+1 << ". " << optArray[i] << endl;
    }

    cout << "Input: ";
	getline(cin, inputStr);

	// Checking that all chars are digits.
	for (int i = 0; i < inputStr.size(); i++) {
		char currentChar = inputStr.at(i);
		if (!isdigit(currentChar)) {
			inputError = true;
		}
	}

	// If input is invalid, will reiterate to the user what a
    //   valid input should be. If input is valid, will end loop.
	if (inputError) {
		cout << "The integer must be from 1 to " << optCount << "!" << endl << endl;
	}
	else {
		inputInt = stoi(inputStr);
		if (inputInt < 1 || inputInt > optCount) {
			cout << "The integer must be from 1 to " << optCount << "!" << endl << endl;
			inputError = true;
		}
		else {
			cout << "Your choice: " << inputInt << endl << endl;
			inputError = false;
		}
	}
  } while(inputError);

  return inputInt;
}
