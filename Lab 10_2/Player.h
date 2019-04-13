#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"

class Player
{
	bool isXPlayer;
	
  public:
  	virtual void playTurn(Board) = 0;
	
};

#endif
