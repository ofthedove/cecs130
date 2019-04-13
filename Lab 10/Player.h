#ifndef PLAYER_H
#define PLAYER_H

#include "GameBoard.h"

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

#endif
