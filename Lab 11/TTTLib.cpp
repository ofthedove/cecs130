#include "TTTLib.h"

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#include "PlayerHuman.h"
#include "PlayerAI1.h"
#include "GameBoard.h"

#include "PlayerAIAndrew.h"
#include "PlayerAIJohn.h"

//***************************************************** Constants ****************************************************
#define stdDelay 1500							// Define delays; easier to change for debugging and harder to miss when switching back

const char *CsVersionNum = "2.0.1";				// Program version number
const char *CsVersionDate =  "11/25/13";		// Program compile date

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
	cout << "      Press 'Enter' to begin \n\t\t\t";		// Press 'Enter' to begin
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
	cout << "\n\n\n\t\t\t";										// Move cursor to position
	cout << "3D Tic Tac Toe Battle\n\n\t\t\t";					// Program name
	cout << "Author:  Andrew Combs & John Stromberg\n\t\t\t";	// Author name
	cout << "Version: " << CsVersionNum << " \n\t\t\t";			// Version number, from constant
	cout << "Date:    " << CsVersionDate << " \n\n\t\t\t";		// Version Date, from constant
	cout << "CECS 130-02     Lab 11\n\n\n\t\t";					// Class, section and lab program was written for
	cout << "    Press any key to continue...";					// Prompt user
	getche();													// Wait for key press
	return;														// End function and return
}

//  ############################################# delay #############################################  //

void delay(int iAmountOfDelay)
{																				// Delay Function
	Sleep(iAmountOfDelay);
	return;
}



//  ############################################ PlayTTT ############################################  //

void playTTT()
{
	int p1Wins = 0;
	int p2Wins = 0;
	
	for (int i = 0; i < 10; i++)
	{
	/*FLAG*/	ajcomb01::PlayerAIAndrew player1(rand() % 2);
	/*FLAG*/	jpstro04::PlayerAIJohn player2(!( player1.getIsXPlayer() ));
		GameBoard game;
		
		bool p1IsX = player1.getIsXPlayer();
		bool p1IsP = true;
		bool p2IsP = false;
		
		int delayTime = 200;
		
		game.isGameOver();
		printGameInfo(p1IsX, p1IsP, p2IsP, p1IsX, game.getXWins(), game.getOWins(), p1Wins, p2Wins);
		game.printBoard();
		
		if (!p1IsX)
		{
			delay(delayTime/2);
			if (! player2.playTurn(&game, p1IsX, p1IsP, p2IsP, false) ) {
				return; }
			printGameInfo(p1IsX, p1IsP, p2IsP, !false, game.getXWins(), game.getOWins(), p1Wins, p2Wins);
			game.printBoard();
			delay(delayTime/2);
			std::cout << std::endl;
		}	
		
		while(!game.isGameOver())
		{
			delay(delayTime/2);
			if (! player1.playTurn(&game, p1IsX, p1IsP, p2IsP, true) ) {
				return; }
			printGameInfo(p1IsX, p1IsP, p2IsP, !true, game.getXWins(), game.getOWins(), p1Wins, p2Wins);
			game.printBoard();
			delay(delayTime/2);
			
			std::cout << std::endl;
			if(game.isGameOver()) {
				break; }
				
			delay(delayTime/2);
			if (! player2.playTurn(&game, p1IsX, p1IsP, p2IsP, false) ) {
				return; }
			game.isGameOver();
			printGameInfo(p1IsX, p1IsP, p2IsP, !false, game.getXWins(), game.getOWins(), p1Wins, p2Wins);
			game.printBoard();
			delay(delayTime/2);
		}
		
		char winner = game.getWhoWon();
		std::string winnerS;
		switch (winner)
		{
			case 'X':
				p1IsX ? winnerS = "Player 1" : winnerS = "Player 2";
				p1IsX ? p1Wins++ : p2Wins++;
				break;
			case 'O':
				!p1IsX ? winnerS = "Player 1" : winnerS = "Player 2";
				!p1IsX ? p1Wins++ : p2Wins ++;
				break;
			case '_':
				winnerS = "The Cat";
				break;
		}
	
		game.isGameOver();
		printGameInfo(p1IsX, p1IsP, p2IsP, true, game.getXWins(), game.getOWins(), p1Wins, p2Wins);
		game.printBoard();
		std::cout << "\n\t   Winner is : " << winnerS << " with a score of : " << game.getXWins() << " to " << game.getOWins() << " !";
		std::cout << "\n\t   Press any key to continue......";
		getch();
	}
	int whoWon = 0;
	if ( p1Wins > p2Wins ) {
		whoWon = 1;
	} else if ( p1Wins < p2Wins ) {
		whoWon = 2;
	} else {
		whoWon = 0; }
	std::string winnerS;
	switch (whoWon)
	{
		case 1:
			winnerS = "Player 1";
			break;
		case 2:
			winnerS = "Player 2";
			break;
		case 0:
			winnerS = "The Cat";
			break;
	}
	clearToHeader();
	std::cout << "\n\t   Winner is : " << winnerS << " with a score of : " << p1Wins << " to " << p2Wins << " !";
	std::cout << "\n\t   Press any key to continue......";
	getch();
}


//  ######################################## Print Game Info ########################################  //

void printGameInfo(bool player1IsX, bool p1IsP, bool p2IsP, bool isP1Turn, int xWins, int oWins, int p1GamesWon, int p2GamesWon)
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
	p1IsP ? player1Type = " Andrew " : player1Type = "  John  ";
	p2IsP ? player2Type = " Andrew " : player2Type = "  John  ";
	
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
		cout << "\t     <  Wins  : " << setw(2) << p1GamesWon << "    >     Wins  : " << setw(2) << p2GamesWon << endl;
		cout << "\t     <    " << player1Type << "    >       " << player2Type << endl << endl;
	} else {
		cout << "\n\t\t" << "Player 1 - " << player1Char << "     <  " << "Player 2 - " << player2Char << "  >" << endl;
		cout << "\t\tScore : " << setw(2) << p1Wins << "       <  Score : " << setw(2) << p2Wins << "    >" << endl;
		cout << "\t\tWins  : " << setw(2) << p1GamesWon << "       <  Wins  : " << setw(2) << p2GamesWon << "    >" << endl;
		cout << "\t\t  " << player1Type << "       <    " << player2Type << "    >" << endl << endl;
	}
}
