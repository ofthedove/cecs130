#include "GameBoard.h"

#include <iostream>

GameBoard::GameBoard()
{
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			board[i][j] = ' ';
		}
	}
	gameOver = false;
	whoWon = ' ';
}

GameBoard::~GameBoard()
{
	
}

bool GameBoard::checkMoveValid(int xCord, int yCord)
{
	if(board[xCord][yCord] == ' ') {
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
				( board[0][1] == 'X' && board[2][1] == 'X' ) ||
				( board[0][2] == 'X' && board[2][0] == 'X' ) )
			{
				gameOver = true; whoWon = 'X'; return true; }
			break;
		case 'O' :
			if( ( board[1][0] == 'O' && board[1][2] == 'O' ) ||
				( board[0][1] == 'O' && board[2][1] == 'O' ) ||
				( board[0][2] == 'O' && board[2][0] == 'O' ) )
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
	if(isDraw()) {
		return true; }
	return false;
}

bool GameBoard::isDraw()
{
	bool draw = true;
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			if (board[i][j] == ' ') {
				draw = false;
			}
		}
	}
	return draw;
}

char GameBoard::getWhoWon()
{
	return whoWon;
}

void GameBoard::printBoard() const
{
	using std::cout;
	using std::endl;
	cout << "\t\t\t" << "_" << board[0][0] << "_|_" << board[1][0] << "_|_" << board[2][0] << "_" << endl;
	cout << "\t\t\t" << "_" << board[0][1] << "_|_" << board[1][1] << "_|_" << board[2][1] << "_" << endl;
	cout << "\t\t\t" << " " << board[0][2] << " | " << board[1][2] << " | " << board[2][2] << " " << endl;
	return;
}

void GameBoard::printBoardLin(int line) const
{
	using namespace std;
	switch(line)
	{
		case 1:
			cout << "_" << board[0][0] << "_|_" << board[1][0] << "_|_" << board[2][0] << "_" ;
			break;
		case 2:
			cout << "_" << board[0][1] << "_|_" << board[1][1] << "_|_" << board[2][1] << "_" ;
			break;
		case 3:
			cout << " " << board[0][2] << " | " << board[1][2] << " | " << board[2][2] << " " ;
			break;
		default:
			break;
	}
	return;
}
