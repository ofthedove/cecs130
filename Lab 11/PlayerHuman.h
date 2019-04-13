#ifndef PLAYERHUMAN_H
#define PLAYERHUMAN_H

#include "Player.h"

class PlayerHuman : public Player
{
  public:
  	PlayerHuman(bool);					// Constructor
  	
  	bool playTurn(GameBoard*, bool, bool, bool, bool);	// Implementation of astract method, actually plays a turn
  										// Five arguments: the game board, p1IsX, p1IsP, p2IsP, isP1Turn
  										// This one is the human player UI version
};

#endif
