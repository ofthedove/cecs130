#ifndef GAMEBOARD3D_H
#define GAMEBOARD3D_H

class GameBoard3D {					// Class to hold the game board and related functions
	GameBoard GB_Z1;
	GameBoard GB_Z2;
	GameBoard GB_Z3;
	
  public:  
	GameBoard3D();						// Constructor, no arguments
	~GameBoard3D();						// Destructor
	
  	bool checkMoveValid(int, int, int);		// Check if a spot on the board is already taken, returns true if spot is open
  	bool makeMove(int, int, int, bool);		// Places a piece on the game board. Returns true on success, false on failure. Bool is isXTurn
	bool isGameOver();						// Returns the value of gameOver
	bool isDraw();							// Checks if the game is a draw, returns true if it is and modifies whoWon
	char getWhoWon();						// Returns value of whoWon
  	
  	void printBoard() const;				// Prints the game board
  	void printBoardLin(int) const;			// Prints one line of the game board, the line specified by (int)
};

#endif
