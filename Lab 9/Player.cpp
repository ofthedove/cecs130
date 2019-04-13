#include <iostream>
#include "Player.h"

void Player::printBoard(char gameBoard[3][3]) const
{
	using std::cout;
	cout << "_" << gameBoard[0][0] << "_|_" << gameBoard[1][0] << "_|_" << gameBoard[2][0] << "_" ;
	cout << "_" << gameBoard[0][1] << "_|_" << gameBoard[1][1] << "_|_" << gameBoard[2][1] << "_" ;
	cout << " " << gameBoard[0][2] << " | " << gameBoard[1][2] << " | " << gameBoard[2][2] << " " ;
	return;
}

void Player::printBoardLin(char gameBoard[3][3], int line) const
{
	using namespace std;
	switch(line)
	{
		case 1:
			cout << "_" << gameBoard[0][0] << "_|_" << gameBoard[1][0] << "_|_" << gameBoard[2][0] << "_" ;
			break;
		case 2:
			cout << "_" << gameBoard[0][1] << "_|_" << gameBoard[1][1] << "_|_" << gameBoard[2][1] << "_" ;
			break;
		case 3:
			cout << " " << gameBoard[0][2] << " | " << gameBoard[1][2] << " | " << gameBoard[2][2] << " " ;
			break;
		default:
			break;
	}
	return;
}
