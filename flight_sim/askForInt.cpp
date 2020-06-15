/********************************************************************
** Function Name: askForInt
** Author:        Ryan Adams
** Date:          11/24/2019
** Description:   Function used to ask for an integer input from the
**                  user within the range of its two int parameters.
**                  The first int parameter must be less than or
**                  equal to the second int parameter. It will check
**                  the user's input and it will loop until a valid
**                  input is obtained. Floats and ints followed by
**                  other input will be truncated down. Will return
**                  the validated int.
********************************************************************/

#include "askForInt.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

/*************************************************************************
 ** Description: Function takes 2 parameters that represent the lower
 **                and upper bounds of an int. Then asks the user for
 **                and int within that range and returns the int once
 **                obtained. Will continue to loop until a valid int is
 **                inputted.
 ************************************************************************/
int askForInt(int lowerLimit, int upperLimit){

  // Validating parameters.
  if(lowerLimit > upperLimit){
    cout << "Error: The lower limit must be <= the upper limit. Returning 0." << endl;
    return 0;
  }

  cout << "Please enter an integer from " << lowerLimit
       << " to " << upperLimit << "." << endl;

  // Loop that will continue to ask user for input until a valid
  //   input is obtained.
  string inputStr;
  int inputInt;
  bool inputError;

  do{
	inputError = false;
    cout << "Input: ";
	getline(cin, inputStr);

	// Checking that all chars are digits.
	for (int i = 0; i < inputStr.size(); i++) {
		char currentChar = inputStr.at(i);
		if (!isdigit(currentChar) && !(currentChar == '-')) {
			inputError = true;
		}
	}

    // If input is invalid, will reiterate to the user what a
    //   valid input should be. If input is valid, will end loop.
	if (inputError) {
		cout << "The integer must be from " << lowerLimit
			 << " to " << upperLimit << "!" << endl;
	}
	else {
		inputInt = stoi(inputStr);
		if (inputInt < lowerLimit || inputInt > upperLimit) {
			cout << "The integer must be from " << lowerLimit
				<< " to " << upperLimit << "!" << endl;
			inputError = true;
		}
		else {
			inputError = false;
		}
	}
  } while(inputError);

  return inputInt;
} 
