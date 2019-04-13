// First Program: Hello World in C
// Author: Andrew Combs
// Date: 08/29/2013
// Section: 2

//***************************************************** Includes *****************************************************
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//*********************************************** Function Declerations ***********************************************
void slowPrint(char*);
void delay(int);

//**************************************** Main Function / Program Entry Point ****************************************
int main()
{
    char *p = "Hello World!";
    slowPrint(p);
    system("PAUSE");
//	slowPrint(['H', 'e', 'l'], 200, 1000);
}

//***************************************************** Functions *****************************************************
void slowPrint(char* p)
{
	int i = 0;
	for(i=0; i < strlen(p); i++)
	{
		putchar(p[i]);
		delay(500);
	}
	printf("\n");
}

/*void slowPrint(char[3] stringToPrint = ['A', 'A', 'A'], int charDisplayInt = 0, int lineDisplayInt = 0)
{
     //char[] printCharArray = printString.getCharArray
     
     //char *a=new char[s.size()+1]
     //a[s.size()]=0;
     //memcpy(a,s.c_str(),s.size());
     
     printf(stringToPrint);
     
     return;
}*/

void delay(int iAmountOfDelay)
{
     int c = 1, d = 1, e = 1;
     
     for ( c = 1 ; c <= iAmountOfDelay ; c++ )
     {
         for ( d = 1 ; d <= 32000 ; d++ )
         {
         	for ( e = 1 ; e <= 30 ; e++ )
         	{
         	}
         }
     }
return;
}
