// Lab 10 : 3D Tic Tac Toe
// Author: Andrew Combs
// Date: 11/14/2013
// Section: 2

// ********************************************* Standard Library Inlcudes ********************************************* //
#include <iostream>				// For cout
#include <stdlib.h>				// For system("cls");
#include <conio.h>				// For getche

// ************************************************** Custom Includes ************************************************** //
#include "Lab10Util.h"			// Include Lab10Util.h, a library of standard program functions in namespace Lab10Util
#include "Game.h"

// ******************************************** Global Constant Definitions ******************************************** //
#define stdDelay 1500			// Define delays; easier to change for debugging and harder to miss when switching back

enum { TTT, TTT3D, MS };

// **************************************** Main Function / Program Entry Point **************************************** //
int main() {
	using namespace Lab10Util;
	using namespace std;
	
	char menuSelect = '_';									// Create a variable to hold user selection on main menu
	int gameMode = TTT;
	int playerMode = 1;
	
	printSplash();											// Print the splash screen
	delay(stdDelay);											// Hold splash screen
	
	while(1)											// Begin main program loop
	{
		clearToHeader();									// Clear splash screen and print header
		printMenu(gameMode, playerMode);								// Print menu to screen
		
		menuSelect = getche();								// Get user menu selection
		
		if(menuSelect == 'x' || menuSelect == 'X')			// If user requested exit, break main loop
			break;
		
		if(menuSelect == 27) {								// If user presses escape, end program immidiately
			return 0; }											// Return out of main to end immidiately

		clearToHeader();									// Clear menu from screen but replace header
		
		switch (menuSelect)								// Use switch to process additional user input values
		{
			case 'd': case 'D':				// Case D : Game mode right
				if (gameMode < MS) {
					gameMode++;
				} else {
					gameMode = TTT; }
				break;
			case 'a': case 'A':				// Case A : Game mode left
				if (gameMode > TTT) {
					gameMode--;
				} else {
					gameMode = MS; }
				break;
			case 'w': case 'W':				// Case W : Player mode up
				if (playerMode > 1) {
					playerMode--;
				} else {
					playerMode = 1; }
				break;
			case 's': case 'S':				// Case S : Player mode down
				if (playerMode < 3) {
					playerMode++;
				} else {
					playerMode = 3; }
				break;
			case 10: case 13: {
				Game theGame(gameMode, playerMode);
				theGame.playGame();
				break; }
			case 'i': case 'I':								// Case to view program information
				printAbout();
				break;
			default:
				cout << "\n\t\t\t";								// Print error message
				cout << "ERROR: Syntax \n\t\t\t";
				cout << "The character you entered is not \n\t\t\t";
				cout << "recognized as a valid operator \n\n\t\t\t";
				cout << "Please try again.";
				cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t";
				delay(stdDelay/2);							// Hold error message on screen
				break;											// Exit the switch and loop back
		} // End of main menu switch
	} // End of main program loop							// When the user selects to exit the program
	system("cls");												// Clear the screen
	printSplash();												// Print the splash screen
	delay(stdDelay);											// Hold splash screen
	system("cls");												// Clear the screen
	return 0;													// Exit program
}
