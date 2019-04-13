#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Board.h"

class Game
{
	bool memError;
	
	int gameType;
	Player *player1;
	Player *player2;
	Board *theBoard;
	
	void playTTT();
	void playTTT3D();
	void playMS();
	
  public:
	Game(int, int);
	~Game();
	
	void playGame();
	
/*	int returnGameType();
	Player* returnPlayer1();
	Player* returnPlayer2();
	Board* returnTheBoard(); */
};

#endif
