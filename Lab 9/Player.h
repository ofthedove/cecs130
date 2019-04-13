#ifndef PLAYER_H
#define PLAYER_H

#include "GameBoard.h"

class Player
{
	bool isXPlayer;
	
	Player(bool);
	~Player();
	
  public:
  	virtual void playTurn(GameBoard) = 0;
  	
  	void printBoard(char[3][3]) const;
  	void printBoardLin(char[3][3], int) const;
};

#endif
