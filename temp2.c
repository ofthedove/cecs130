//
// Author: Andrew Combs
// Date: //2013
// Section: 2

//***************************************************** Includes *****************************************************
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
// Use size of with union?
//************************************************* Function Prototype ************************************************

char *sName = "Andrew";

//**************************************** Main Function / Program Entry Point ****************************************
int main()
{
	printf("Your Name: ");
	int c = 0, i = 0;
	while(((c = getchar()) != EOF) && (c != '\n')) {
		//*(sName+i) = c;
		i++;
	}
	printf("Your Name is : %s", sName);
}

//***************************************************** Functions *****************************************************

