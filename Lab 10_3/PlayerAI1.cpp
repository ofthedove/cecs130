#include "PlayerAI1.h"

#include <stdlib.h>
#include "TTTLib.h"

PlayerAI1::PlayerAI1(bool isPlayerX)
	:Player(isPlayerX)
{}
bool PlayerAI1::playTurn(GameBoard *game, bool p1IsX, bool p1IsP, bool p2IsP, bool isP1Turn)
{
	while (!( game->makeMove( (rand() % 3), (rand() % 3), (rand() % 3), this->getIsXPlayer() ) )) {}
	game->isGameOver();
	printGameInfo(p1IsX, p1IsP, p2IsP, !isP1Turn, game->getXWins(), game->getOWins());
	game->printBoard();
	return true;
}
