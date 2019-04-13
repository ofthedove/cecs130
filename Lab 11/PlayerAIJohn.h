#ifndef PLAYERAIJOHN_H
#define PLAYERAIJOHN_H

#include "Player.h"

namespace jpstro04 {

class PlayerAIJohn : public Player
{
	
  public:
	PlayerAIJohn(bool);
	
	bool playTurn(GameBoard*, bool, bool, bool, bool);
};

}

#endif
