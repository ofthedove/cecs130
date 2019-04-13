#include "Game.h"

#include <stdlib.h>

#include "Player.h"
#include "PlayerHuman.h"
#include "PlayerAI1.h"
#include "Board.h"
#include "BoardTTT.h"
#include "BoardTTT3D.h"
#include "BoardMS.h"

enum { TTT, TTT3D, MS };

Game::Game(int gameMode, int playerMode)
{
	gameType = gameMode;
	switch(gameMode)
	{
		case TTT:
			theBoard = new BoardTTT();
			break;
		case TTT3D:
			theBoard = new BoardTTT3D();
			break;
		case MS:
			theBoard = new BoardMS();
			break;
	}
	
	if (gameMode == MS)
	{
		player1 = new PlayerHuman();
		player2 = NULL;
	} else {
		switch(playerMode)
		{
			case 1:
				player1 = new PlayerHuman();
				player2 = new PlayerHuman();
				break;
			case 2:
				player1 = new PlayerHuman();
				player2 = new PlayerAI1();
				break;
			case 3:
				player1 = new PlayerAI1();
				player2 = new PlayerAI1();
				break;
		}
	}
	
	if(player1 == NULL || (player2 == NULL && gameMode != MS) || theBoard == NULL) {
		memError = true;
		return; }
	
	memError = false;
	return;
}

Game::~Game()
{
	if(player1 != NULL) {
		delete(player1);
		player1 = NULL; }
	if(player2 != NULL) {
		delete(player2);
		player2 = NULL; }
	if(theBoard != NULL) {
		delete(theBoard);
		theBoard = NULL; }
}

void Game::playGame()
{
	switch (gameType)
	{
		case TTT:
			playTTT();
			break;
		case TTT3D:
			playTTT3D();
			break;
		case MS:
			playMS();
			break;
	}
}

void Game::playTTT()
{
	
}

void Game::playTTT3D()
{
	
}

void Game::playMS()
{
	
}

/*
int Game::returnGameType() { return gameType; }

Player* Game::returnPlayer1() { return player1; }

Player* Game::returnPlayer2() { return player2; }

Board* Game::returnTheBoard() { return theBoard; }
*/
