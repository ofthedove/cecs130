#include "TTTLib.h"

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#include "PlayerHuman.h"
#include "PlayerAI1.h"
#include "GameBoard.h"


//***************************************************** Constants ****************************************************
#define stdDelay 1500							// Define delays; easier to change for debugging and harder to miss when switching back

const char *CsVersionNum = "2.0.0";				// Program version number
const char *CsVersionDate =  "11/20/13";		// Program compile date

enum GameMode { PVP, PVC, CVC };		// Three posible game modes: Player vs Player, Player vs Computer, and Conputer vs Computer

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
	cout << "3D Tic Tac Toe\n\n\t\t\t";						// Program name
	cout << "Author:  Andrew Combs\n\t\t\t";				// Author name
	cout << "Version: " << CsVersionNum << " \n\t\t\t";	// Version number, from constant
	cout << "Date:    " << CsVersionDate << " \n\n\t\t\t";	// Version Date, from constant
	cout << "CECS 130-02     Lab 10\n\n\n\t\t";			// Class, section and lab program was written for
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



//  ############################################ PlayTTT ############################################  //

// Remember : enum GameMode { PVP, PVC, CVC };

void playTTT(int gameMode)
{
	switch (gameMode)
	{
		case PVP: {		// %%%%%%%%%%%%%%%%%%%% Player vs Player %%%%%%%%%%%%%%%%%%%% //
			PlayerHuman player1(rand() % 2);
			PlayerHuman player2(!( player1.getIsXPlayer() ));
			GameBoard game;
			
			bool p1IsX = player1.getIsXPlayer();
			bool p1IsP = true;
			bool p2IsP = true;
			
			game.isGameOver();
			printGameInfo(p1IsX, p1IsP, p2IsP, p1IsX, game.getXWins(), game.getOWins());
			game.printBoard();
			
			if (!p1IsX)
			{
				if (! player2.playTurn(&game, p1IsX, p1IsP, p2IsP, true) ) {
					return; }
				std::cout << std::endl;
			}	
			
			while(!game.isGameOver())
			{
				if (! player1.playTurn(&game, p1IsX, p1IsP, p2IsP, true) ) {
					return; }
				std::cout << std::endl;
				if(game.isGameOver()) {
					break; }
				if (! player2.playTurn(&game, p1IsX, p1IsP, p2IsP, false) ) {
					return; }
				std::cout << std::endl;
			}
			
			char winner = game.getWhoWon();
			std::string winnerS;
			switch (winner)
			{
				case 'X':
					p1IsX ? winnerS = "Player 1" : winnerS = "Player 2";
					break;
				case 'O':
					!p1IsX ? winnerS = "Player 1" : winnerS = "Player 2";
					break;
				case '_':
					winnerS = "The Cat";
					break;
			}
			
			game.isGameOver();
			printGameInfo(p1IsX, p1IsP, p2IsP, true, game.getXWins(), game.getOWins());
			game.printBoard();
			std::cout << "\n\t   Winner is : " << winnerS << " with a score of : " << game.getXWins() << " to " << game.getOWins() << " !";
			if(getche() == 27) {
				return; }
			break; }
		case PVC: {		// %%%%%%%%%%%%%%%%%%%% Player vs Computer %%%%%%%%%%%%%%%%%%%% //
			PlayerHuman player1(rand() % 2);
			PlayerAI1 player2(!( player1.getIsXPlayer() ));
			GameBoard game;
			
			bool p1IsX = player1.getIsXPlayer();
			bool p1IsP = true;
			bool p2IsP = false;
			
			game.isGameOver();
			printGameInfo(p1IsX, p1IsP, p2IsP, p1IsX, game.getXWins(), game.getOWins());
			game.printBoard();
			
			if (!p1IsX)
			{
				std::cout << std::endl;
				std::cout << "\t\t" << "Press any key for computer play" << std::endl;
				std::cout << "\t\t" << "Press \"Escape\" to return to main menu" << std::endl;	
				if(getche() == 27) {
					return; }
				if (! player2.playTurn(&game, p1IsX, p1IsP, p2IsP, false) ) {
					return; }
				std::cout << std::endl;
			}
			
			while(!game.isGameOver())
			{
				if (! player1.playTurn(&game, p1IsX, p1IsP, p2IsP, true) ) {
					return; }
				std::cout << std::endl;
				if(game.isGameOver()) {
					break; }
				std::cout << "\t\t" << "Press any key for computer play" << std::endl;
				std::cout << "\t\t" << "Press \"Escape\" to return to main menu" << std::endl;	
				if(getche() == 27) {
					return; }
				if (! player2.playTurn(&game, p1IsX, p1IsP, p2IsP, false) ) {
					return; }
				std::cout << std::endl;
			}
			
			char winner = game.getWhoWon();
			std::string winnerS;
			switch (winner)
			{
				case 'X':
					p1IsX ? winnerS = "Player 1" : winnerS = "Player 2";
					break;
				case 'O':
					!p1IsX ? winnerS = "Player 1" : winnerS = "Player 2";
					break;
				case '_':
					winnerS = "The Cat";
					break;
			}
			
			game.isGameOver();
			printGameInfo(p1IsX, p1IsP, p2IsP, true, game.getXWins(), game.getOWins());
			game.printBoard();
			std::cout << "\n\t   Winner is : " << winnerS << " with a score of : " << game.getXWins() << " to " << game.getOWins() << " !";
			if(getche() == 27) {
				return; }
			break; }
		case CVC: {		// %%%%%%%%%%%%%%%%%%%% Computer vs Computer %%%%%%%%%%%%%%%%%%%% //
			PlayerAI1 player1(rand() % 2);
			PlayerAI1 player2(!( player1.getIsXPlayer() ));
			GameBoard game;
			
			bool p1IsX = player1.getIsXPlayer();
			bool p1IsP = false;
			bool p2IsP = false;
			
			game.isGameOver();
			printGameInfo(p1IsX, p1IsP, p2IsP, p1IsX, game.getXWins(), game.getOWins());
			game.printBoard();
			
			if (!p1IsX)
			{
				std::cout << std::endl;
				std::cout << "\t\t" << "Press any key for computer play" << std::endl;
				std::cout << "\t\t" << "Press \"Escape\" to return to main menu" << std::endl;	
				if(getche() == 27) {
					return; }
				if (! player2.playTurn(&game, p1IsX, p1IsP, p2IsP, false) ) {
					return; }
				std::cout << std::endl;
			}	
			
			while(!game.isGameOver())
			{
				std::cout << std::endl;
				std::cout << "\t\t" << "Press any key for computer play" << std::endl;
				std::cout << "\t\t" << "Press \"Escape\" to return to main menu" << std::endl;	
				if(getche() == 27) {
					return; }
				if (! player1.playTurn(&game, p1IsX, p1IsP, p2IsP, true) ) {
					return; }
				std::cout << std::endl;
				if(game.isGameOver()) {
					break; }
				std::cout << "\t\t" << "Press any key for computer play" << std::endl;
				std::cout << "\t\t" << "Press \"Escape\" to return to main menu" << std::endl;	
				if(getche() == 27) {
					return; }
				if (! player2.playTurn(&game, p1IsX, p1IsP, p2IsP, false) ) {
					return; }
			}
			
			char winner = game.getWhoWon();
			std::string winnerS;
			switch (winner)
			{
				case 'X':
					p1IsX ? winnerS = "Player 1" : winnerS = "Player 2";
					break;
				case 'O':
					!p1IsX ? winnerS = "Player 1" : winnerS = "Player 2";
					break;
				case '_':
					winnerS = "The Cat";
					break;
			}
			
			game.isGameOver();
			printGameInfo(p1IsX, p1IsP, p2IsP, true, game.getXWins(), game.getOWins());
			game.printBoard();
			std::cout << "\n\t   Winner is : " << winnerS << " with a score of : " << game.getXWins() << " to " << game.getOWins() << " !";
			if(getche() == 27) {
				return; }
			break; }
	}
	
}

//  ######################################## Print Game Info ########################################  //

void printGameInfo(bool player1IsX, bool p1IsP, bool p2IsP, bool isP1Turn, int xWins, int oWins)
{
	using namespace std;
	
	char player1Char = '_';
	char player2Char = '_';
	if (player1IsX) {
		player1Char = 'X'; player2Char = 'O';
	} else {
		player2Char = 'X'; player1Char = 'O';
	}
	
	string player1Type = "";
	string player2Type = "";
	p1IsP ? player1Type = " Human  " : player1Type = "Computer";
	p2IsP ? player2Type = " Human  " : player2Type = "Computer";
	
	int p1Wins = 0, p2Wins = 0;
	if (player1IsX) {
		p1Wins = xWins;
		p2Wins = oWins;
	} else {
		p1Wins = oWins;
		p2Wins = xWins;
	}
	
	clearToHeader();
	if(isP1Turn) {
		cout << "\n\t     <  " << "Player 1 - " << player1Char << "  >     " << "Player 2 - " << player2Char << endl;
		cout << "\t     <  Score : " << setw(2) << p1Wins << "    >     Score : " << setw(2) << p2Wins << endl;
		cout << "\t     <    " << player1Type << "    >       " << player2Type << endl << endl;
	} else {
		cout << "\n\t\t" << "Player 1 - " << player1Char << "     <  " << "Player 2 - " << player2Char << "  >" << endl;
		cout << "\t\tScore : " << setw(2) << p1Wins << "       <  Score : " << setw(2) << p2Wins << "    >" << endl;
		cout << "\t\t  " << player1Type << "       <    " << player2Type << "    >" << endl << endl;
	}
}
