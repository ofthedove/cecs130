// Lab 9 : Tic Tac Toe
// Author: Andrew Combs
// Date: 11/5/2013
// Section: 2

// I had intended to make this project multi-file, but Dev C++ _really_ doesn't like that very much, so I've seperated
// the source code as if it were in seperate files, using comments to show which code would go with which file. This 
// bit here would be in the main file but these comments need to be at the top, and the includes, constants, and function
// prototypes need to be at the top so they can be used in the functions

//***************************************************** Includes *****************************************************
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

//***************************************************** Constants ****************************************************
#define stdDelay 1500							// Define delays; easier to change for debugging and harder to miss when switching back

const char *CsVersionNum = "1.0.0";				// Program version number
const char *CsVersionDate =  "11/07/13";		// Program compile date

//************************************************* Function Prototype ************************************************
void printSplash();								// Print the program's splash screen
void clearToHeader();							// Clear the screen and print the program header
void printMenu();								// Print the program's main menu
void printAbout();								// Print information about the program
void delay(int);								// Delay execution for (int) milliseconds

void playTTT(int);								// Contains the actual game code
void printGameInfo(bool, bool, bool, bool);		// Print info about the game, players and such. Goes above the game board



// GameBoard.h																								&&&&&&&&&&  GameBoard.h  &&&&&&&&&&
class GameBoard {					// Class to hold the game board and related functions
	char board[3][3];					// 2D char array, the actual game board
	bool gameOver;						// Bool, true if the game is over, false if still in progress
	char whoWon;						// '_' = in progress or draw 'X' = X won 'O' = O won
	
  public:  
	GameBoard();						// Constructor, no arguments
	~GameBoard();						// Destructor
	
  	bool checkMoveValid(int, int);		// Check if a spot on the board is already taken, returns true if spot is open
  	bool makeMove(int, int, bool);		// Places a piece on the game board. Returns true on success, false on failure. Bool is isXTurn
	bool isGameOver();					// Returns the value of gameOver
	bool isDraw();						// Checks if the game is a draw, returns true if it is and modifies whoWon
	char getWhoWon();					// Returns value of whoWon
  	
  	void printBoard() const;			// Prints the game board
  	void printBoardLin(int) const;		// Prints one line of the game board, the line specified by (int)
};


// GameBoard.cpp																							&&&&&&&&&&  GameBoard.cpp  &&&&&&&&&&
GameBoard::GameBoard()
{
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			board[i][j] = '_';
		}
	}
	gameOver = false;
	whoWon = '_';
}

GameBoard::~GameBoard()
{
	
}

bool GameBoard::checkMoveValid(int xCord, int yCord)
{
	if(board[xCord][yCord] == '_') {
		return true;
	} else {
		return false;
	}
}

bool GameBoard::makeMove(int xCord, int yCord, bool XTurn)
{
	if( checkMoveValid(xCord, yCord) )
	{
		if( XTurn ) {
			board[xCord][yCord] = 'X';
		} else {
			board[xCord][yCord] = 'O';
		}
		return true;
	} else {
		return false;
	}
}

bool GameBoard::isGameOver()
{
	if(gameOver) {
		return true; }
	if(isDraw()) {
		return true; }
	switch (board[0][0])
	{
		case 'X' :
			if( ( board[1][0] == 'X' && board[2][0] == 'X' ) ||
				( board[0][1] == 'X' && board[0][2] == 'X' ) ||
				( board[1][1] == 'X' && board[2][2] == 'X' ) )
			{
				gameOver = true; whoWon = 'X'; return true; }
			break;
		case 'O' :
			if( ( board[1][0] == 'O' && board[2][0] == 'O' ) ||
				( board[0][1] == 'O' && board[0][2] == 'O' ) ||
				( board[1][1] == 'O' && board[2][2] == 'O' ) )
			{
				gameOver = true; whoWon = 'O'; return true; }
			break;
	}
	switch (board[1][1])
	{
		case 'X' :
			if( ( board[1][0] == 'X' && board[1][2] == 'X' ) ||
				( board[0][1] == 'X' && board[2][1] == 'X' ) ||
				( board[0][2] == 'X' && board[2][0] == 'X' ) )
			{
				gameOver = true; whoWon = 'X'; return true; }
			break;
		case 'O' :
			if( ( board[1][0] == 'O' && board[1][2] == 'O' ) ||
				( board[0][1] == 'O' && board[2][1] == 'O' ) ||
				( board[0][2] == 'O' && board[2][0] == 'O' ) )
			{
				gameOver = true; whoWon = 'O'; return true; }
			break;
	}
	switch (board[2][2])
	{
		case 'X' :
			if( ( board[0][2] == 'X' && board[1][2] == 'X' ) ||
				( board[2][0] == 'X' && board[2][1] == 'X' ) ||
				( board[0][0] == 'X' && board[1][1] == 'X' ) )
			{
				gameOver = true; whoWon = 'X'; return true; }
			break;
		case 'O' :
			if( ( board[0][2] == 'O' && board[1][2] == 'O' ) ||
				( board[2][0] == 'O' && board[2][1] == 'O' ) ||
				( board[0][0] == 'O' && board[1][1] == 'O' ) )
			{
				gameOver = true; whoWon = 'O'; return true; }
			break;
	}
	return false;
}

bool GameBoard::isDraw()
{
	bool draw = true;
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			if (board[i][j] == '_') {
				draw = false;
			}
		}
	}
	return draw;
}

char GameBoard::getWhoWon()
{
	return whoWon;
}

void GameBoard::printBoard() const
{
	using std::cout;
	using std::endl;
	cout << "\t\t\t" << "_" << board[0][0] << "_|_" << board[1][0] << "_|_" << board[2][0] << "_" << endl;
	cout << "\t\t\t" << "_" << board[0][1] << "_|_" << board[1][1] << "_|_" << board[2][1] << "_" << endl;
	cout << "\t\t\t" << " " << board[0][2] << " | " << board[1][2] << " | " << board[2][2] << " " << endl;
	return;
}

void GameBoard::printBoardLin(int line) const
{
	using namespace std;
	switch(line)
	{
		case 1:
			cout << "_" << board[0][0] << "_|_" << board[1][0] << "_|_" << board[2][0] << "_" ;
			break;
		case 2:
			cout << "_" << board[0][1] << "_|_" << board[1][1] << "_|_" << board[2][1] << "_" ;
			break;
		case 3:
			cout << " " << board[0][2] << " | " << board[1][2] << " | " << board[2][2] << " " ;
			break;
		default:
			break;
	}
	return;
}


// Player.h																									&&&&&&&&&&  Player.h  &&&&&&&&&&
class Player
{
	bool isXPlayer;						// Keeps track of wether or not this player is player X
	
  public:
	Player(bool);						// Constructor, one argument (bool) true if this is player X false if O
	~Player();							// Destructor
	
	bool getIsXPlayer();				// Returns the value of isXPlayer
	
  	virtual bool playTurn(GameBoard*, bool, bool, bool, bool) = 0;	// Abstract method, actually plays a turn
  										// Five arguments: the game board, p1IsX, p1IsP, p2IsP, isP1Turn
};


// Player.cpp																								&&&&&&&&&&  Player.cpp  &&&&&&&&&&
Player::Player(bool isPlayerX)
{
	isXPlayer = isPlayerX;
}
Player::~Player()
{
	
}
bool Player::getIsXPlayer()
{
	return isXPlayer;
}



// PlayerHuman.h																							&&&&&&&&&&  PlayerHuman.h  &&&&&&&&&&
class PlayerHuman : public Player
{
  public:
  	PlayerHuman(bool);					// Constructor
  	
  	bool playTurn(GameBoard*, bool, bool, bool, bool);	// Implementation of astract method, actually plays a turn
  										// Five arguments: the game board, p1IsX, p1IsP, p2IsP, isP1Turn
  										// This one is the human player UI version
};


// PlayerHuman.cpp																							&&&&&&&&&&  PlayerHuman.cpp  &&&&&&&&&&
PlayerHuman::PlayerHuman(bool isPlayerX)
	:Player(isPlayerX)
{}
bool PlayerHuman::playTurn(GameBoard *game, bool p1IsX, bool p1IsP, bool p2IsP, bool isP1Turn)
{
	while (true)
	{
		using namespace std;
		
		printGameInfo(p1IsX, p1IsP, p2IsP, isP1Turn);
		game->printBoard();
		
		int xcord;
		cout << "X cord (1-3) : ";
	/*	while(true)					// This code was put in to try and add error checking to cin becuase it has major issues, plus
		{							// to allow escape to actually work for something, but it didn't work I think it still has potential,
			char temp = getche();	// so its still here so I can come back to it. Ignore for now
			if (temp == 27) {
				return false; }
			if (temp == '\n') {
				ungetch(1);
				break; }
			if ( (temp == 1) || (temp == 2) || (temp == 3) ) {
				ungetch(1); }
		}*/
		cin >> xcord;
		
		int ycord;
		cout << "\nY cord (1-3) : ";
		cin >> ycord;
		
		if( (ycord >= 1 && ycord <= 3) && (xcord >= 1 && xcord <= 3) )
		{
			if( game->makeMove((xcord - 1), (ycord - 1), this->getIsXPlayer()) ) {
				break; }
		}
		
		cout << "\nError: Invalid move! Please try again...";
		getche();
	}
	printGameInfo(p1IsX, p1IsP, p2IsP, !isP1Turn);
	game->printBoard();
	return true;
}

// PlayerAI1.h																								&&&&&&&&&&  PlayerAI1.h  &&&&&&&&&&
class PlayerAI1 : public Player
{
	
  public:
  	PlayerAI1(bool);					// Constructor
  	
  	bool playTurn(GameBoard*, bool, bool, bool, bool);	// Implementation of astract method, actually plays a turn
  										// Five arguments: the game board, p1IsX, p1IsP, p2IsP, isP1Turn
  										// This one is the human player UI version
};


// PlayerAI1.cpp																							&&&&&&&&&&  PlayerAI1.cpp  &&&&&&&&&&
PlayerAI1::PlayerAI1(bool isPlayerX)
	:Player(isPlayerX)
{}
bool PlayerAI1::playTurn(GameBoard *game, bool p1IsX, bool p1IsP, bool p2IsP, bool isP1Turn)
{
	while (!( game->makeMove( (rand() % 3), (rand() % 3), this->getIsXPlayer() ) )) {}
	printGameInfo(p1IsX, p1IsP, p2IsP, !isP1Turn);
	game->printBoard();
	return true;
}



// Combs_2_Lab9.cpp																							&&&&&&&&&&  Combs_2_Lab9.cpp  &&&&&&&&&&

enum GameMode { PVP, PVC, CVC };		// Three posible game modes: Player vs Player, Player vs Computer, and Conputer vs Computer

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

//***************************************************** Functions *****************************************************

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
			
			printGameInfo(p1IsX, p1IsP, p2IsP, true);
			game.printBoard();
			
			while(!game.isGameOver())
			{
				player1.playTurn(&game, p1IsX, p1IsP, p2IsP, true);
				std::cout << std::endl;
				if(game.isGameOver()) {
					break; }
				player2.playTurn(&game, p1IsX, p1IsP, p2IsP, false);
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
			
			printGameInfo(p1IsX, p1IsP, p2IsP, true);
			game.printBoard();
			std::cout << "\n\t\t   Winner is : " << winnerS << " !";
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
			
			printGameInfo(p1IsX, p1IsP, p2IsP, true);
			game.printBoard();
			
			while(!game.isGameOver())
			{
				player1.playTurn(&game, p1IsX, p1IsP, p2IsP, true);
				std::cout << std::endl;
				if(game.isGameOver()) {
					break; }
				std::cout << "\t\t" << "Press any key for computer play" << std::endl;
				std::cout << "\t\t" << "Press \"Escape\" to return to main menu" << std::endl;	
				if(getche() == 27) {
					return; }
				player2.playTurn(&game, p1IsX, p1IsP, p2IsP, false);
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
			
			printGameInfo(p1IsX, p1IsP, p2IsP, true);
			game.printBoard();
			std::cout << "\n\t\t   Winner is : " << winnerS << " !";
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
			
			printGameInfo(p1IsX, p1IsP, p2IsP, true);
			game.printBoard();
			
			while(!game.isGameOver())
			{
				std::cout << std::endl;
				std::cout << "\t\t" << "Press any key for computer play" << std::endl;
				std::cout << "\t\t" << "Press \"Escape\" to return to main menu" << std::endl;	
				if(getche() == 27) {
					return; }
				player1.playTurn(&game, p1IsX, p1IsP, p2IsP, true);
				std::cout << std::endl;
				if(game.isGameOver()) {
					break; }
				std::cout << "\t\t" << "Press any key for computer play" << std::endl;
				std::cout << "\t\t" << "Press \"Escape\" to return to main menu" << std::endl;	
				if(getche() == 27) {
					return; }
				player2.playTurn(&game, p1IsX, p1IsP, p2IsP, false);
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
			
			printGameInfo(p1IsX, p1IsP, p2IsP, true);
			game.printBoard();
			std::cout << "\n\t\t   Winner is : " << winnerS << " !";
			if(getche() == 27) {
				return; }
			break; }
	}
	
}

//  ######################################## Print Game Info ########################################  //

void printGameInfo(bool player1IsX, bool p1IsP, bool p2IsP, bool isP1Turn)
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
	
	clearToHeader();
	if(isP1Turn) {
		cout << "\n\t     <  " << "Player 1 - " << player1Char << "  >     " << "Player 2 - " << player2Char << endl;
		cout << "\t     <    " << player1Type << "    >       " << player2Type << endl << endl;
	} else {
		cout << "\n\t\t" << "Player 1 - " << player1Char << "     <  " << "Player 2 - " << player2Char << "  >" << endl;
		cout << "\t\t  " << player1Type << "       <    " << player2Type << "    >" << endl << endl;
	}
}
