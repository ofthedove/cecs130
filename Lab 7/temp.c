//
// Author: Andrew Combs
// Date: //2013
// Section: 2

//***************************************************** Includes *****************************************************
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//************************************************* Function Prototype ************************************************


//**************************************** Main Function / Program Entry Point ****************************************
int main()
{
	int i = 0;
	for(i=0; i<10; i++) {
		if(i==5) {
			break; }
	}
	printf("%i", i);
	system("PAUSE");
}

//***************************************************** Functions *****************************************************
