#ifndef GAMEBOARD_H
#define GAMEBOARD_H

class GameBoard {
	char board[3][3];
	bool gameOver;
	char whoWon;				// '_' = in progress 'X' = X won 'O' = O won 'D' = draw
	
  public:  
	GameBoard(int);
	~GameBoard();
	
  	bool checkMoveValid(int, int);
  	bool makeMove(int, int, bool);
	bool isGameOver();
	char getWhoWon();
  	
  	void returnGameBoard(char[3][3]);
};

#endif
