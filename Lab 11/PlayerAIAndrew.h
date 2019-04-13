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
