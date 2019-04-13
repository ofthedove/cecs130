#ifndef TTTLIB_H
#define TTTLIB_H

void printSplash();										// Print the program's splash screen
void clearToHeader();									// Clear the screen and print the program header
void printMenu();										// Print the program's main menu
void printAbout();										// Print information about the program
void delay(int);										// Delay execution for (int) milliseconds

void playTTT(int);										// Contains the actual game code
void printGameInfo(bool, bool, bool, bool, int, int);	// Print info about the game, players and such. Goes above the game board

#endif
