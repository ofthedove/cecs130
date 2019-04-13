#include "Lab10Util.h"

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

enum { TTT, TTT3D, MS };

namespace Lab10Util
{
// ***************************************************** Constants ****************************************************

	const char *CsVersionNum = "1.0.2";				// Program version number
	const char *CsVersionDate =  "11/14/13";		// Program compile date
	
	//  ############################################# printSplash #############################################  //
	
	void printSplash()
	{								// Print ASCII art splash screen
		using std::cout;
		cout << "#########################################################################\n";
		cout << "#########################################################################\n";
		cout << "#########################################################################\n";
		cout << "#########################################################################\n";
		cout << "#########################################################################\n";
		cout << "#####       ___ ___  __    ___         __    ___  __   __           #####\n";
		cout << "#####        |   |  /       |    /\\   /       |  /  \\ |             #####\n";
		cout << "#####        |   |  |       |   /__\\  |       |  |  | |--           #####\n";
		cout << "#####        |  _|_ \\__     |  /    \\ \\__     |  \\__/ |__           #####\n";
		cout << "#####                                                               #####\n";
		cout << "#####                       -Andrew Combs-                          #####\n";
		cout << "#####                                                               #####\n";
		cout << "#########################################################################\n";
		cout << "#########################################################################\n";
		cout << "#########################################################################\n";
		cout << "#########################################################################\n";
		cout << "#########################################################################\n";
		return;
	}
	
	//  ############################################# clearToHeader #############################################  //
	
	void clearToHeader()
	{																							// Clear screen and print header line
		using std::cout;
		system("cls");																				// Use terminal command cls to clear screen
		cout << "############################## Tic Tac Toe #############################\n";		// Print header line
		return;																						// End function and return
	}
	
	//  ############################################# printMenu #############################################  //
	
	void printMenu(int gameMode, int playerMode)
	{														// Print main menu
		using std::cout;
		cout << "\n\t\t    Current Game : " << returnGameModeString(gameMode);
		cout << "\n\n\t\t\t";									// Move cursor to position
		if(gameMode != MS) {								// Only single player available for MS
			if(playerMode == 1) {
				cout << "   -> Player vs Player \n\t\t\t";
			} else { 
				cout << "      Player vs Player \n\t\t\t"; }
			if(playerMode == 2) {
				cout << "   -> Player vs Computer \n\t\t\t";
			} else { 
				cout << "      Player vs Computer \n\t\t\t"; }
			if(playerMode == 3) {
				cout << "   -> Computer vs Computer \n\n\t\t\t";
			} else { 
				cout << "      Computer vs Computer \n\n\t\t\t"; }
		} else {
			if(playerMode == 0) {
				cout << "\n\t\t\t" << "      Single Player\n" << "\n\n\t\t\t";
			} else { 
				cout << "\n\t\t\t" << "   -> Single Player\n" << "\n\n\t\t\t"; }
		}
		cout << "    ---------------------------- \n\n\t\t\t";	// Print formatting line
		cout << "I     Info\n\t\t\t";							// About: I or i
		cout << "X     Exit";									// Exit: X or x
		cout << "\n\n\n\n\n\t\t\t";
		cout << "   Use 'A' and 'D' to switch games \n\t\t\t";
		cout << "Use 'W' and 'S' to switch player modes \n\t\t\t";
		cout << "        Press 'Enter' to begin";
		cout << "\n\t\t\t\t\t\t\t\t\t";					// Formatting
		return;													// End function and return
	}
	
	//  ############################################# printAbout #############################################  //
	
	void printAbout()
	{														// Detail information about program
		using std::cout;
		cout << "\n\n\n\t\t\t";								// Move cursor to position
		cout << "Tic Tac Toe\n\n\t\t\t";						// Program name
		cout << "Author:  Andrew Combs\n\t\t\t";				// Author name
		cout << "Version: " << CsVersionNum << " \n\t\t\t";	// Version number, from constant
		cout << "Date:    " << CsVersionDate << " \n\n\t\t\t";	// Version Date, from constant
		cout << "CECS 130-02     Lab 9 \n\n\n\t\t";			// Class, section and lab program was written for
		cout << "    Press any key to continue...";			// Prompt user
		getche();											// Wait for key press
		return;												// End function and return
	}
	
	//  ############################################# delay #############################################  //
	
	void delay(int iAmountOfDelay)
	{																				// Delay Function
		Sleep(iAmountOfDelay);
		return;
	}
	
	//  ############################################# returnGameModeString #############################################  //
	
	char * returnGameModeString(int gameMode)
	{																				// 
		switch (gameMode)
		{
			case TTT:
				return " Tic Tac Toe ";
			case TTT3D:
				return "3D Tic Tac Toe";
			case MS:
				return " Mine Sweeper ";
			default:
				return "";
		}
	}
}
