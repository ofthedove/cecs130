// For Loop Increment No Difference
// Author: Andrew Combs
// Date: 09/09/2013
// Section: 2

//***************************************************** Includes *****************************************************
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//****************************************8******* Function Prototypes ***8********************************************


//**************************************** Main Function / Program Entry Point ****************************************
int main()
{
    int i = 0;
    for(i = 0; i < 5; ++i)
    {
    	printf("%d \n", i);
    }
    
    printf("\n \n \n \n \n \n \n \n \n \n");
    
    for(i = 0; i < 5; i++)
    {
    	printf("%d \n", i);
    }
    system("PAUSE");
}

//***************************************************** Functions *****************************************************
