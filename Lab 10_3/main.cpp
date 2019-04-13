// Lab 10 : 3D Tic Tac Toe
// Author: Andrew Combs
// Date: 11/21/2013
// Section: 2

//***************************************************** Includes *****************************************************
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#include "TTTLib.h"

#include "GameBoard.h"
#include "Player.h"
#include "PlayerHuman.h"
#include "PlayerAI1.h"

//***************************************************** Constants ****************************************************
#define stdDelay 1500							// Define delays; easier to change for debugging and harder to miss when switching back

enum { PVP, PVC, CVC };		// Three posible game modes: Player vs Player, Player vs Computer, and Conputer vs Computer

//**************************************** Main Function / Program Entry Point ****************************************
main()
{
	using std::cout;
	using std::cin;
	
	srand(time(NULL));										// Seed the random number generator
	
	char menuSelect = '_';									// Create a variable to hold user selection on main menu
	
	printSplash();											// Print the splash screen
	delay(stdDelay);											// Hold splash screen
	
	while(1)											// Begin main program loop
	{
		clearToHeader();									// Clear splash screen and print header
		printMenu();										// Print menu to screen
		
		menuSelect = getche();								// Get user menu selection
		
		if(menuSelect == 'x' || menuSelect == 'X')			// If user requested exit, break main loop
			break;
		
		if(menuSelect == 27) {								// If user presses escape, end program immidiately
			return 0; }											// Return out of main to end immidiately

		clearToHeader();									// Clear menu from screen but replace header
		
		switch (menuSelect)								// Use switch to process additional user input values
		{
			case 'p': case 'P': case '1': {					// Case for PVP
				playTTT(PVP);
				break; }
			case 'v': case 'V': case '2': {					// Case for PVC
				playTTT(PVC);
				break; }
			case 'c': case 'C': case '3': {					// Case for CVC
				playTTT(CVC);
				break; }
			case 'i': case 'I':								// Case to view program information
				printAbout();
				break;
			default:
				printf("\n\t\t\t");								// Print error message
				printf("ERROR: Syntax \n\t\t\t");
				printf("The character you entered is not \n\t\t\t");
				printf("recognized as a valid operator \n\n\t\t\t");
				printf("Please try again.");
				printf("\n\n\n\n\t\t\t\t\t\t\t\t\t");
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
