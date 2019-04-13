// Pointer to a Pointer
// Author: Andrew Combs
// Date: 09/18/2013
// Section: 2

//***************************************************** Includes *****************************************************
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//************************************************* Function Prototype ************************************************


//**************************************** Main Function / Program Entry Point ****************************************
int main()
{
	int x = 52;
	int *px = &x;
	int *ppx = &px;
	printf(" *px  %d\n px   %p\n *ppx %p\n ppx  %p\n", *px, px, *ppx, ppx);
	system("PAUSE");
}

//***************************************************** Functions *****************************************************

