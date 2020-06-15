/*****************************************************************
** Program Name:  flightSim
** Author:        Ryan Adams
** Date:          12/10/2019
** Description:   Program that simulates a passenger's journey to
**                put away their luggage and find a seat. Program
**                creates a game map and allows the player to freely
**                roam and interact with spaces. The player will
**                lose if the stewardess loses all of her patience
**                and will win if the player puts away their luggage
**                and finds a seat.
**
** Citation: Learned about and implemented code from question on
**           stackoverflow to pause program until key press. Link:
** https://stackoverflow.com/questions/92802/what-is-the-linux-equivalent-to-dos-pause
*****************************************************************/

#include "Menu.hpp"
#include "askForInt.hpp"
#include "LinkedMap.hpp"
#include "ItemBag.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::to_string;

int main(){
	// Seeding random number generator.
	srand(time(NULL));

	// Creating start menu.
	string startPrompt = "What would you like to do?";
	string playOpt = "Play Realistic Flight Simulator";
	string quitOpt = "Quit";

	Menu startMenu(startPrompt, playOpt, quitOpt);

	cout << "Welcome to Realistic Flight Simulator by Ryan Adams" << endl << endl;

	// Loop that continues asking the user if they want to play, until they choose to quit.
	int userQuits = startMenu.ask();
	while (userQuits != 2) {

		// Displaying scenario and rules.
		system("clear");
		cout << "**************************************************************************************************************" << endl
			<< "** You are finally taking the long sought after trip to Hawaii that your therapist recommended.\t\t    **" << endl
			<< "** The plane is pretty packed, so it might be a bit difficult to find some overhead space for your luggage. **" << endl
			<< "** But, being the crafty asshole with no shame that you are, you know exactly what to do...\t\t    **" << endl
			<< "**************************************************************************************************************" << endl << endl;
		cout << "****************" << endl
			<< "** Directions **" << endl
			<< "****************" << endl;
		cout << " - Your task is simple. Put your luggage away in an overhead bin and then find a seat." << endl
			<< " - However, the stewardess wants to keep a tight schedule and will be looking for any reason to throw you off the plane." << endl
			<< " - Once the stewardess's patience with you reaches 0, you will be forcibly de-boarded without a refund." << endl
			<< " - You will have three options each turn: Move, Check items, and some type of \"Interaction.\"" << endl
			<< "\t- Movement is limited to forward, backward, left, and right." << endl
			<< "\t  You can move anywhere within the plane's passenger area." << endl
			<< "\t- Checking your items will show a list of all your currently held items." << endl
			<< "\t  You start with luggage in your inventory and can carry up to 5 items." << endl
			<< "\t  You can give items you find to other passengers, but just know that not everyone will be grateful..." << endl
			<< "\t- The type of interaction available depends on where you currently are in the plane." << endl
			<< "\t  You will need to find out for yourself what each type of interaction entails." << endl
			<< " - Map Key: @ = You, # = Seated Passenger, O = Empty Seat" << endl << endl;
		system("read -n1 -r -p \"Press any key to continue...\"");

		// Generating initial game scenario.
		LinkedMap gameMap;
		ItemBag items;
		int patience = 10;
		bool playerSitting = false;
		system("clear");
		gameMap.printLinkedMap();
		cout << "You are standing in the aisle near the front of the plane with your luggage." << endl;

		// Creating action menu.
		string actionPrompt = "What would you like to do?";
		string moveOpt = "Move";
		string itemOpt = "Check items";
		string interactOpt = gameMap.getPlayer()->getInteractOpt();
		Menu actionMenu(actionPrompt, moveOpt, itemOpt);
		actionMenu.add(interactOpt);

		// Creating movement direction menu.
		string directionPrompt = "What direction would you like to move?";
		Menu directionMenu(directionPrompt, "Forward", "Right");
		directionMenu.add("Backward");
		directionMenu.add("Left");
		
		// Loop that will continue asking the user for actions until a win or lose condition is met.
		while (playerSitting == false && patience > 0) {

			// Displaying patience gauge and action menu.
			cout << endl << "Stewardess's Patience: " << patience << endl;
			int actionChoice = actionMenu.ask();

			// Switch to perform action depending on player's choice.
			switch (actionChoice) {
				case 1: {
					// Moving player in specified direction and adjusting patience based on move.
					patience += gameMap.movePlayer(directionMenu.ask() - 1);

					// Changing action menu based on player location.
					actionMenu.change(gameMap.getPlayer()->getInteractOpt(), 3);
					break;
				}
				case 2: {
					// Displaying items.
					items.displayItems();
					system("read -n1 -r -p \"Press any key to continue...\"");
					system("clear");
					gameMap.printLinkedMap();
					break;
				}
				case 3: {
					patience += gameMap.getPlayer()->interact(items);
					playerSitting = gameMap.getPlayer()->getPlayerSitting();
					system("read -n1 -r -p \"Press any key to continue...\"");
					system("clear");
					gameMap.printLinkedMap();
					break;
				}
			}
		}

		// Displaying message depending on whether or not the player won.
		system("clear");
		if (playerSitting == true) {
			cout << "You've put up your luggage and found a seat." << endl
				<< "The stewardess is noticeably relieved and returns to her duties." << endl
				<< "Have a safe flight!" << endl << endl;
		}
		else {
			cout << "Stewardess: \"Alright, sir! I'm going to have to ask you to de-board this plane.\"" << endl
				<< "You grab your luggage and awkwardly walk past the rows of people staring at you." << endl
				<< "You try to avoid eye contact, but you notice that everyone is visibly happy." << endl
				<< "Just after you exit the plane, you hear cheers from the cabin crew and passengers." << endl
				<< "You are back standing in the terminal. So much for Hawaii..." << endl << endl;
		}
		system("read -n1 -r -p \"Press any key to continue...\"");

		// Changing start menu play option string.
		startMenu.change("Play again", 1);

		system("clear");
		userQuits = startMenu.ask();
	}

	cout << "Thank you, come play again!" << endl;
	return 0;
}
 
