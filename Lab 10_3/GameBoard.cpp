#include "GameBoard.h"

#include <iostream>
#include "Cursor.h"

GameBoard::GameBoard()
{
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			for(int k=0; k<3; k++) {
				board[i][j][k] = ' ';
			}
		}
	}
	gameOver = false;
	XWins = 0;
	OWins = 0;
	whoWon = '_';
}

GameBoard::~GameBoard()
{
	
}

bool GameBoard::checkMoveValid(int xCord, int yCord, int zCord)
{
	if(board[xCord][yCord][zCord] == ' ') {
		return true;
	} else {
		return false;
	}
}

bool GameBoard::makeMove(int xCord, int yCord, int zCord, bool XTurn)
{
	if( checkMoveValid(xCord, yCord, zCord) )
	{
		if( XTurn ) {
			board[xCord][yCord][zCord] = 'X';
		} else {
			board[xCord][yCord][zCord] = 'O';
		}
		return true;
	} else {
		return false;
	}
}

bool GameBoard::isGameOver()
{
	if(gameOver) {
		return true; }/*
	if(!isDraw()) {
		return false; }
	gameOver = true;*/
	XWins = 0;
	OWins = 0;
	enum { X, Y, Z };
	for (int rotation = X; rotation <= Z; rotation++)	// Slice the 3D board into three 2D boards along the x, y and x axis
	{
		for (int layer = 0; layer < 3; layer++)
		{
			char tempBoard[3][3];
			
			sliceBoard(tempBoard, board, rotation, layer);
			
			if (rotation == Z)
			{
				switch (tempBoard[1][1])
				{
					case 'X' :
						if( tempBoard[0][0] == 'X' && tempBoard[2][2] == 'X' ) {
							XWins++; }
						if( tempBoard[2][0] == 'X' && tempBoard[0][2] == 'X' ) {
							XWins++; }
						break;
					case 'O' :
						if( tempBoard[0][0] == 'O' && tempBoard[2][2] == 'O' ) {
							OWins++; }
						if( tempBoard[2][0] == 'O' && tempBoard[0][2] == 'O' ) {
							OWins++; }
						break;
				}
			} else if (rotation == Y) {
				switch (tempBoard[0][0])
				{
					case 'X':
						if( tempBoard[1][0] == 'X' && tempBoard[2][0] == 'X' ) {
							XWins++; }
						break;
					case 'O' :
						if( tempBoard[1][0] == 'O' && tempBoard[2][0] == 'O' ) {
							OWins++; }
						break;
				}
				switch (tempBoard[1][1])
				{
					case 'X' :
						if( tempBoard[0][1] == 'X' && tempBoard[2][1] == 'X' ) {
							XWins++; }
						break;
					case 'O' :
						if( tempBoard[0][1] == 'O' && tempBoard[2][1] == 'O' ) {
							OWins++; }
						break;
				}
				switch (tempBoard[2][2])
				{
					case 'X' :
						if( tempBoard[0][2] == 'X' && tempBoard[1][2] == 'X' ) {
							XWins++; }
						break;
					case 'O' :
						if( tempBoard[0][2] == 'O' && tempBoard[1][2] == 'O' ) {
							OWins++; }
						break;
				}
			} else {
				switch (tempBoard[0][0])
				{
					case 'X' :
						if( ( tempBoard[1][0] == 'X' && tempBoard[2][0] == 'X' ) ||
							( tempBoard[0][1] == 'X' && tempBoard[0][2] == 'X' ) ||
							( tempBoard[1][1] == 'X' && tempBoard[2][2] == 'X' ) )
						{
							XWins++; }
						break;
					case 'O' :
						if( ( tempBoard[1][0] == 'O' && tempBoard[2][0] == 'O' ) ||
							( tempBoard[0][1] == 'O' && tempBoard[0][2] == 'O' ) ||
							( tempBoard[1][1] == 'O' && tempBoard[2][2] == 'O' ) )
						{
							OWins++; }
						break;
				}
				switch (tempBoard[1][1])
				{
					case 'X' :
						if( ( tempBoard[1][0] == 'X' && tempBoard[1][2] == 'X' ) ||
							( tempBoard[0][1] == 'X' && tempBoard[2][1] == 'X' ) ||
							( tempBoard[0][2] == 'X' && tempBoard[2][0] == 'X' ) )
						{
							XWins++; }
						break;
					case 'O' :
						if( ( tempBoard[1][0] == 'O' && tempBoard[1][2] == 'O' ) ||
							( tempBoard[0][1] == 'O' && tempBoard[2][1] == 'O' ) ||
							( tempBoard[0][2] == 'O' && tempBoard[2][0] == 'O' ) )
						{
							OWins++; }
						break;
				}
				switch (tempBoard[2][2])
				{
					case 'X' :
						if( ( tempBoard[0][2] == 'X' && tempBoard[1][2] == 'X' ) ||
							( tempBoard[2][0] == 'X' && tempBoard[2][1] == 'X' ) ||
							( tempBoard[0][0] == 'X' && tempBoard[1][1] == 'X' ) )
						{
							XWins++; }
						break;
					case 'O' :
						if( ( tempBoard[0][2] == 'O' && tempBoard[1][2] == 'O' ) ||
							( tempBoard[2][0] == 'O' && tempBoard[2][1] == 'O' ) ||
							( tempBoard[0][0] == 'O' && tempBoard[1][1] == 'O' ) )
						{
							OWins++; }
						break;
				}
			}
		}
	}
	// First 3D diagonal
	if ((board[0][0][0] == 'X') && (board[1][1][1] == 'X') && (board[2][2][2] == 'X')) {
		XWins++; }
	if ((board[0][0][0] == 'O') && (board[1][1][1] == 'O') && (board[2][2][2] == 'O')) {
		OWins++; }
	// Second 3D diagonal
	if ((board[2][0][0] == 'X') && (board[1][1][1] == 'X') && (board[0][2][2] == 'X')) {
		XWins++; }
	if ((board[2][0][0] == 'O') && (board[1][1][1] == 'O') && (board[0][2][2] == 'O')) {
		OWins++; }
	// Third 3D diagonal
	if ((board[0][0][2] == 'X') && (board[1][1][1] == 'X') && (board[2][2][0] == 'X')) {
		XWins++; }
	if ((board[0][0][2] == 'O') && (board[1][1][1] == 'O') && (board[2][2][0] == 'O')) {
		OWins++; }
	// Fourth 3D diagonal
	if ((board[2][0][2] == 'X') && (board[1][1][1] == 'X') && (board[0][2][0] == 'X')) {
		XWins++; }
	if ((board[2][0][2] == 'O') && (board[1][1][1] == 'O') && (board[0][2][0] == 'O')) {
		OWins++; }	
	
	if(!isDraw()) {
		return false; }
	gameOver = true;	
	
	if ( XWins > OWins ) {
		whoWon = 'X';
	} else if ( XWins < OWins ) {
		whoWon = 'O';
	} else {
		whoWon = '_'; }
	
	return true;
}

void GameBoard::sliceBoard(char tempBoard[3][3], char currentBoard[3][3][3], int rotation, int layer)
{
	enum { X, Y, Z };
	switch (rotation)
		{
			case X:
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						tempBoard[i][j] = currentBoard[layer][i][j];
					}
				}
				break;
			case Y:
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						tempBoard[i][j] = currentBoard[i][layer][j];
					}
				}
				break;
			case Z:
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						tempBoard[i][j] = currentBoard[i][j][layer];
					}
				}
				break;
		}
}

bool GameBoard::isDraw()
{
	bool draw = true;
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			for(int k = 0; k<3; k++){
				if (board[i][j][k] == ' ') {
					draw = false;
				}
			}
		}
	}
	return draw;
}

char GameBoard::getWhoWon()
{
	return whoWon;
}

int GameBoard::getXWins()
{
	return XWins;
}

int GameBoard::getOWins()
{
	return OWins;
}

void GameBoard::printBoard() const
{
	using std::cout;
	using std::endl;
	
	char hLine[12] = { 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196, 0 };
	char vLine[4] = { 32, 179, 32, 0 };
	
	cout << "\t\t" << " " << board[0][0][0] << vLine << board[1][0][0] << vLine << board[2][0][0] << " " << endl;
	cout << "\t\t" << hLine << endl;
	cout << "\t\t" << " " << board[0][1][0] << vLine << board[1][1][0] << vLine << board[2][1][0] << " " << endl;
	cout << "\t\t" << hLine << endl;
	cout << "\t\t" << " " << board[0][2][0] << vLine << board[1][2][0] << vLine << board[2][2][0] << " ";
	
	cout << "  " << board[0][0][1] << vLine << board[1][0][1] << vLine << board[2][0][1] << " " << endl;
	cout << "\t\t\t    " << hLine << endl;
	cout << "\t\t\t     " << board[0][1][1] << vLine << board[1][1][1] << vLine << board[2][1][1] << " " << endl;
	cout << "\t\t\t    " << hLine << endl;
	cout << "\t\t\t     " << board[0][2][1] << vLine << board[1][2][1] << vLine << board[2][2][1] << " ";
	
	cout << "  " << board[0][0][2] << vLine << board[1][0][2] << vLine << board[2][0][2] << " " << endl;
	cout << "\t\t\t\t\t" << hLine << endl;
	cout << "\t\t\t\t\t " << board[0][1][2] << vLine << board[1][1][2] << vLine << board[2][1][2] << " " << endl;
	cout << "\t\t\t\t\t" << hLine << endl;
	cout << "\t\t\t\t\t " << board[0][2][2] << vLine << board[1][2][2] << vLine << board[2][2][2] << " " << endl;
	return;
}

void GameBoard::printBoard(Cursor *cursor)
{
	char orgBoard[3][3][3];
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			for(int k = 0; k < 3; k++) {
				orgBoard[i][j][k] = board[i][j][k];
			}
		}
	}
	
	cursor->overlayPointer(board);
	
	this->printBoard();
	
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			for(int k = 0; k < 3; k++) {
				board[i][j][k] = orgBoard[i][j][k];
			}
		}
	}
}
/*
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
}*/
