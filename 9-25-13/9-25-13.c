// 
// Author: Andrew Combs
// Date: //2013
// Section: 2

//***************************************************** Includes *****************************************************
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define screenWidth 70
#define screenHeight 20

struct peice{
	int xCord;
	int yCord;
	int speed;
	int dir;
	char rep;
};

char screen[screenWidth][screenHeight];

//************************************************* Function Prototype ************************************************
void printScreen();
void calcBallMove(struct peice*);
void moveBall(struct peice*);
void initScreenArray();

//**************************************** Main Function / Program Entry Point ****************************************
int main()
{
	initScreenArray();
	struct peice peiceBallOne;
	peiceBallOne.xCord = 15;
	peiceBallOne.yCord = 10;
	peiceBallOne.speed = 0;
	peiceBallOne.dir = 6;
	peiceBallOne.rep = 'O';
	
	while(1)
	{
		calcBallMove(&peiceBallOne);
		moveBall(&peiceBallOne);
		printScreen();
		if(getch() == 27) { break; }
		system("cls");
	}
	
}

//***************************************************** Functions *****************************************************
void initScreenArray()
{
	int i = 0, j = 0;
	
	for(i = 0; i < screenHeight; i++)
	{
		for(j = 0; j < screenWidth; j++)
		{
			screen[j][i] = 32;
		}
	}
}

void printScreen()
{
	int i = 0, j = 0;
	
	for(i = (screenHeight-1); i >= 0; i--)
	{
		for(j = 0; j < screenWidth; j++)
		{
			printf("%c", screen[j][i]);
		}
		printf("\n");
	}
	
	for(j = 0; j < screenWidth; j++)
	{
		printf("#");
	}
	
	printf("\n");
}

void calcBallMove(struct peice *ptBall)
{
	if (ptBall->dir == 6) {
		ptBall->speed += 1;
	} else {
		ptBall->speed -= 1;
	}
}

void moveBall(struct peice *ptBall)
{
	switch (ptBall->dir)
	{
		case 1:
			
			break;
		case 2:
			
			break;
		case 3:
			screen[ptBall->xCord][ptBall->yCord] = ' ';
			ptBall->yCord += ptBall->speed;
			if (ptBall->yCord < screenHeight) { 
				ptBall->yCord = screenHeight;
				ptBall->dir = 6;
				ptBall->speed = ((ptBall->speed) / 2); }
			screen[ptBall->xCord][ptBall->yCord] = ptBall->rep;
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			screen[ptBall->xCord][ptBall->yCord] = ' ';
			ptBall->yCord -= ptBall->speed;
			if (ptBall->yCord < 0) { 
				ptBall->yCord = 0;
				ptBall->dir = 3;
				ptBall->speed = ((ptBall->speed) / 2); }
			screen[ptBall->xCord][ptBall->yCord] = ptBall->rep;
			break;
		case 7:
			
			break;
	}
	return;
}
