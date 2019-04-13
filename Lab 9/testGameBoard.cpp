//
// Author: Andrew Combs
// Date: //2013
// Section: 2

//***************************************************** Includes *****************************************************
#include <iostream>
#include "GameBoard.h"

//************************************************* Function Prototype ************************************************


//**************************************** Main Function / Program Entry Point ****************************************
int main()
{
	GameBoard myGameBoard(5);// = new GameBoard::GameBoard();
	
	using namespace std;
	
	cout << "Checking move valid 1, 1" << endl;
	bool wasValid = myGameBoard.checkMoveValid(1,1);
	cout << "The move was : " << wasValid << endl << endl;
	
	cout << "Making the move" << endl;
	bool madeMove = myGameBoard.makeMove(1,1,true);
	cout << "The move was : " << madeMove << endl << endl;
	
	cout << "Checking move valid 1, 1" << endl;
	bool wasValid2 = myGameBoard.checkMoveValid(1,1);
	cout << "The move was : " << wasValid2 << endl << endl;
	
	cout << "Making move at  1, 0 and 1, 2" << endl;
	bool madeMove1 = myGameBoard.makeMove(1,0,true);
	bool madeMove2 = myGameBoard.makeMove(1,2,true);
	cout << "The first move was : " << madeMove << endl;
	cout << "The second move was : " << madeMove << endl << endl;
	
	cout << "Is the game over? " << myGameBoard.isGameOver() << endl;
	cout << "Who won? " << myGameBoard.getWhoWon() << endl;
	
}

//***************************************************** Functions *****************************************************

