#include "PlayerAIAndrew.h"

#include <stdlib.h>
#include "TTTLib.h"

namespace ajcomb01
{
	
PlayerAIAndrew::PlayerAIAndrew(bool isPlayerX) : Player(isPlayerX)
{
	
}
	
bool PlayerAIAndrew::playTurn(GameBoard *game, bool p1IsX, bool p1IsP, bool p2IsP, bool isP1Turn) {
	bool amXPlayer = this->getIsXPlayer();
	while (!( game->makeMove( (rand() % 3), (rand() % 3), (rand() % 3), amXPlayer /*this->getIsXPlayer()*/ ) )) {}
	return true;
}
	
}
