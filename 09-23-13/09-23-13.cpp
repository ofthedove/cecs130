//
// Author: Andrew Combs
// Date: //2013
// Section: 2

//***************************************************** Includes *****************************************************
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

//************************************************* Function Prototype ************************************************


//**************************************** Main Function / Program Entry Point ****************************************
int main()
{
	char myString[13] = {'H', 'e', 'l', 'l', 'o', '\t', ' ', 'W', 'o', 'r', 'l', 'd', '\0'};
	char myString2[] = "Hello";
	char *myString3 = "Hello";
	
	printf(myString);
	printf("\n");
//	sleep(5);
	printf(myString2);
	printf("\n");
	printf(myString3);
}

//***************************************************** Functions *****************************************************

