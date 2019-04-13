#include "PlayerHuman.h"

#include <iostream>
#include <conio.h>
#include "TTTLib.h"
#include "Cursor.h"

PlayerHuman::PlayerHuman(bool isPlayerX)
	:Player(isPlayerX)
{}

int getTTTCord() {
	using std::cout;
	int input;
	while (1)
	{
		input = getch();
		if (input == 27) {
			return -1; }
		if (input == '1') {
			cout << (char)input;
			input = 1;
			break; }
		if (input == '2') {
			cout << (char)input;
			input = 2;
			break; }
		if (input == '3') {
			cout << (char)input;
			input = 3;
			break; }
	}
	return input;
}
/*
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
			if ( (temp == 1) || (telkmp == 2) || (temp == 3) ) {
				ungetch(1); }
		} * /
		xcord = getTTTCord();
		if(xcord == -1) {
			return false; }
		
		
		int ycord;
		cout << "\nY cord (1-3) : ";
		ycord = getTTTCord();
		if(ycord == -1) {
			return false; }
		
		int zcord;
		cout << "\nZ cord (1-3) : ";
		zcord = getTTTCord();
		if(zcord == -1) {
			return false; }
		
		delay(200);
		
		if( (ycord >= 1 && ycord <= 3) && (xcord >= 1 && xcord <= 3) && (zcord >= 1 && zcord <= 3) )
		{
			if( game->makeMove((xcord - 1), (ycord - 1), (zcord - 1), this->getIsXPlayer()) ) {
				break; }
		}
		
		cout << "\nError: Invalid move! Please try again...";
		getche();
	}
	printGameInfo(p1IsX, p1IsP, p2IsP, !isP1Turn);
	game->printBoard();
	return true;
}
*/

bool PlayerHuman::playTurn(GameBoard *game, bool p1IsX, bool p1IsP, bool p2IsP, bool isP1Turn)
{
	using namespace std;
	char inputChar = ' ';
	Cursor cursor;
	bool moveSuccess = false;
	
	while (true)
	{
		game->isGameOver();
		printGameInfo(p1IsX, p1IsP, p2IsP, isP1Turn, game->getXWins(), game->getOWins(), 0, 0);
		game->printBoard(&cursor);
		cout << "\n\t\tUse W A S D Q E to move the cursor";
		cout << "\n\t\tUse 'Enter' to place piece";
		
		inputChar = getch();
		
		switch (inputChar)
		{
			case 'a': case 'A':
				cursor.moveCursor(-1, 0, 0);
				break;
			case 'd': case 'D':
				cursor.moveCursor(1, 0, 0);
				break;
			case 'w': case 'W':
				cursor.moveCursor(0, -1, 0);
				break;
			case 's': case 'S':
				cursor.moveCursor(0, 1, 0);
				break;
			case 'q': case 'Q':
				cursor.moveCursor(0, 0, -1);
				break;
			case 'e': case 'E':
				cursor.moveCursor(0, 0, 1);
				break;
			case 10: case 13:
				int px, py, pz;
				cursor.returnCursorPos(&px, &py, &pz);
				if ( game->makeMove(px, py, pz, this->getIsXPlayer()) ) {
					moveSuccess = true; }
				break;
			case 27:
				return false;
			default:
				break;
		}
		
		if (moveSuccess) {
			break; }
		
		//cout << "\nError: Invalid move! Please try again...";
		//getche();
	}
	game->isGameOver();
	printGameInfo(p1IsX, p1IsP, p2IsP, !isP1Turn, game->getXWins(), game->getOWins(), 0, 0);
	game->printBoard();
	return true;
}
