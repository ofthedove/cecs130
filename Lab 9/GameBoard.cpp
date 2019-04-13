#include "GameBoard.h"

GameBoard::GameBoard(int myInt)
{
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			board[i][j] = '_';
		}
	}
	gameOver = false;
	whoWon = '_';
}

GameBoard::~GameBoard()
{
	
}

bool GameBoard::checkMoveValid(int xCord, int yCord)
{
	if(board[xCord][yCord] == '_') {
		return true;
	} else {
		return false;
	}
}

bool GameBoard::makeMove(int xCord, int yCord, bool XTurn)
{
	if( checkMoveValid(xCord, yCord) )
	{
		if( XTurn ) {
			board[xCord][yCord] = 'X';
		} else {
			board[xCord][yCord] = 'O';
		}
		return true;
	} else {
		return false;
	}
}

bool GameBoard::isGameOver()
{
	if(gameOver) {
		return true; }
	switch (board[0][0])
	{
		case 'X' :
			if( ( board[1][0] == 'X' && board[2][0] == 'X' ) ||
				( board[0][1] == 'X' && board[0][2] == 'X' ) ||
				( board[1][1] == 'X' && board[2][2] == 'X' ) )
			{
				gameOver = true; whoWon = 'X'; return true; }
			break;
		case 'O' :
			if( ( board[1][0] == 'O' && board[2][0] == 'O' ) ||
				( board[0][1] == 'O' && board[0][2] == 'O' ) ||
				( board[1][1] == 'O' && board[2][2] == 'O' ) )
			{
				gameOver = true; whoWon = 'O'; return true; }
			break;
	}
	switch (board[1][1])
	{
		case 'X' :
			if( ( board[1][0] == 'X' && board[1][2] == 'X' ) ||
				( board[0][1] == 'X' && board[2][1] == 'X' ) )
			{
				gameOver = true; whoWon = 'X'; return true; }
			break;
		case 'O' :
			if( ( board[1][0] == 'O' && board[1][2] == 'O' ) ||
				( board[0][1] == 'O' && board[2][1] == 'O' ) )
			{
				gameOver = true; whoWon = 'O'; return true; }
			break;
	}
	switch (board[2][2])
	{
		case 'X' :
			if( ( board[0][2] == 'X' && board[1][2] == 'X' ) ||
				( board[2][0] == 'X' && board[2][1] == 'X' ) ||
				( board[0][0] == 'X' && board[1][1] == 'X' ) )
			{
				gameOver = true; whoWon = 'X'; return true; }
			break;
		case 'O' :
			if( ( board[0][2] == 'O' && board[1][2] == 'O' ) ||
				( board[2][0] == 'O' && board[2][1] == 'O' ) ||
				( board[0][0] == 'O' && board[1][1] == 'O' ) )
			{
				gameOver = true; whoWon = 'O'; return true; }
			break;
	}
	return false;
}

char GameBoard::getWhoWon()
{
	return whoWon;
}

void GameBoard::returnGameBoard(char rtnGameBoard[3][3])
{
	rtnGameBoard = board;
	return;
}
