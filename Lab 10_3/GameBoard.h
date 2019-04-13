#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Cursor.h"

class GameBoard {					// Class to hold the game board and related functions
	char board[3][3][3];					// 2D char array, the actual game board
	bool gameOver;						// Bool, true if the game is over, false if still in progress
	int XWins;							// Number of three-in-a-rows X has
	int OWins;							// Number of three-in-a-rows O has
	char whoWon;						// '_' = in progress or draw 'X' = X won 'O' = O won
	
	void sliceBoard(char[3][3], char[3][3][3], int, int);
	
  public:  
	GameBoard();						// Constructor, no arguments
	~GameBoard();						// Destructor
	
  	bool checkMoveValid(int, int, int);		// Check if a spot on the board is already taken, returns true if spot is open
  	bool makeMove(int, int, int, bool);		// Places a piece on the game board. Returns true on success, false on failure. Bool is isXTurn
	bool isGameOver();					// Returns the value of gameOver
	bool isDraw();						// Checks if the game is a draw, returns true if it is and modifies whoWon
	char getWhoWon();					// Returns value of whoWon
	int getXWins();						// Returns number of three-ina-rows X got
	int getOWins();						// Returns number of three-ina-rows O got
  	
  	void printBoard() const;			// Prints the game board
  	void printBoard(Cursor*);
//  	void printBoardLin(int) const;		// Prints one line of the game board, the line specified by (int)
};

#endif
