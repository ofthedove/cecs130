#include "PlayerAIJohn.h"

#include <stdlib.h>
#include "TTTLib.h"

namespace jpstro04
{

PlayerAIJohn::PlayerAIJohn(bool isPlayerX) : Player(isPlayerX)
{}

bool PlayerAIJohn::playTurn(GameBoard *game, bool p1IsX, bool p1IsP, bool p2IsP, bool isP1Turn)
{
if(game->checkMoveValid(1,1,1)==' '){ game->makeMove(1,1,1, this->getIsXPlayer()); return true;}
if(game->checkMoveValid(2,2,2)==' '){ game->makeMove(2,2,2, this->getIsXPlayer()); return true;}
if(game->checkMoveValid(3,3,3)==' '){ game->makeMove(3,3,3, this->getIsXPlayer()); return true;}
if(game->checkMoveValid(1,3,3)==' '){ game->makeMove(1,3,3, this->getIsXPlayer()); return true;}
if(game->checkMoveValid(3,3,1)==' '){game->makeMove(3,3,1, this->getIsXPlayer()); return true;}
else{
	while (!( game->makeMove( (rand() % 3), (rand() % 3), (rand() % 3), this->getIsXPlayer() ) )) {}
	return true;}
}

}
