#ifndef PLAYERAIANDREW_H
#define PLAYERAIANDREW_H

#include "Player.h"

namespace ajcomb01
{

class PlayerAIAndrew : public Player
{
	
	
  public:
	PlayerAIAndrew(bool);
	
	bool playTurn(GameBoard*, bool, bool, bool, bool);
};

}

#endif

#ifndef PLAYERAI2_H
#define PLAYERAI2_H

#include "Player.h"

class PlayerAI2 : public Player
{
	
  public:
  	PlayerAI2(bool);					// Constructor
  	
  	bool playTurn(GameBoard*, bool, bool, bool, bool);	// Implementation of astract method, actually plays a turn
  										// Five arguments: the game board, p1IsX, p1IsP, p2IsP, isP1Turn
  										// This one is the human player UI version
};

#endif
