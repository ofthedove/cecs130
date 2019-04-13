//
// Author: Andrew Combs
// Date: //2013
// Section: 2

//***************************************************** Includes *****************************************************
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//************************************************* Function Prototype ************************************************
void workWithPointer(int *);

//**************************************** Main Function / Program Entry Point ****************************************
int main()
{
	int *myInt;
	workWithPointer(myInt);
	printf("myInt is equal to : %f", *myInt);
	system("PAUSE");
}

//***************************************************** Functions *****************************************************

void workWithPointer(int *integer)
{
	*integer = 42;
	return;
}
