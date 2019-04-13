// Pointer to a Pointer
// Author: Andrew Combs
// Date: 09/18/2013
// Section: 2

// If you create a pointer to a variable and de-allocate the variable and try to write to the location of the pointer what will happen?

// Is it possible to use pointers to call individual bytes in an array instead of cell elements. I.E. while *(list + n) points to the
// nth element in an array could you have something like *(list + b) where it calls bth byte in the array / variable
// Yes. Don't know what it is, assuming beyond current scope.

//***************************************************** Includes *****************************************************
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//************************************************* Function Prototype ************************************************


//**************************************** Main Function / Program Entry Point ****************************************
int main()
{
	int ary = {5, 4, 1, 2, 3};
	int arySize = 5;
	int *pSm, *pWalk;
	pLast = (ary + (arySize - 1));
	for (int pSm = ary, pWalk = ary + 1;
			 pWalk <= pLast;
			 pWalk++ )
		if(*pWalk < *pSm)
				pSm = pWalk;
	
	printf("%d", *pSm);
}

//***************************************************** Functions *****************************************************

