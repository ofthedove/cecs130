#include "Lab10Util.h"

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

namespace Lab10Util
{
// ***************************************************** Constants ****************************************************

	const char *CsVersionNum = "1.0.1";				// Program version number
	const char *CsVersionDate =  "11/11/13";		// Program compile date
	
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
	
	void printMenu()
	{														// Print main menu
		using std::cout;
		cout << "\n\t\t\t";										// Move cursor to position
		cout << "P     (1) Player vs Player \n\t\t\t";			// PVP : P, p, or 1
		cout << "V     (2) Player vs Computer \n\t\t\t";		// PVC : V, v, or 2
		cout << "C     (3) Computer vs Computer \n\t\t\t";		// CVC : C, c, or 3
		cout << "    ---------------------------- \n\n\t\t\t";	// Print formatting line
		cout << "I     Info\n\t\t\t";							// About: I or i
		cout << "X     Exit";									// Exit: X or x
		cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t";					// Formatting
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
	
}
