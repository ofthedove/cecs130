#include "PlayerHuman.h"

#include <iostream>
#include <conio.h>
#include "TTTLib.h"

PlayerHuman::PlayerHuman(bool isPlayerX)
	:Player(isPlayerX)
{}
bool PlayerHuman::playTurn(GameBoard *game, bool p1IsX, bool p1IsP, bool p2IsP, bool isP1Turn)
{
	while (true)
	{
		using namespace std;
		
		printGameInfo(p1IsX, p1IsP, p2IsP, isP1Turn);
		game->printBoard();
		
		int xcord;
		cout << "X cord (1-3) : ";
	/*	while(true)					// This code was put in to try and add error checking to cin becuase it has major issues, plus
		{							// to allow escape to actually work for something, but it didn't work I think it still has potential,
			char temp = getche();	// so its still here so I can come back to it. Ignore for now
			if (temp == 27) {
				return false; }
			if (temp == '\n') {
				ungetch(1);
				break; }
			if ( (temp == 1) || (temp == 2) || (temp == 3) ) {
				ungetch(1); }
		}*/
		cin >> xcord;
		
		int ycord;
		cout << "\nY cord (1-3) : ";
		cin >> ycord;
		
		if( (ycord >= 1 && ycord <= 3) && (xcord >= 1 && xcord <= 3) )
		{
			if( game->makeMove((xcord - 1), (ycord - 1), this->getIsXPlayer()) ) {
				break; }
		}
		
		cout << "\nError: Invalid move! Please try again...";
		getche();
	}
	printGameInfo(p1IsX, p1IsP, p2IsP, !isP1Turn);
	game->printBoard();
	return true;
}
