//
// Author: Andrew Combs
// Date: //2013
// Section: 2

//***************************************************** Includes *****************************************************
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//************************************************* Function Prototype ************************************************
void delay(int);

//**************************************** Main Function / Program Entry Point ****************************************
int main()
{
	system("PAUSE");
	delay(1000);
	system("PAUSE");
}

//***************************************************** Functions *****************************************************
void delay(int iAmountOfDelay)
{
     int c = 1, d = 1, e = 1;
     
     for ( c = 1 ; c <= iAmountOfDelay ; c++ )
     {         for ( d = 1 ; d <= 32000 ; d++ )
         {
         	for ( e = 1 ; e <= 30 ; e++ )
         	{
         	}
         }
     }
return;
}
