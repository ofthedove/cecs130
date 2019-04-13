// 09-04-13 Random Numbers
// Author: Andrew Combs
// Date: 09/04/2013
// Section: 2

//***************************************************** Includes *****************************************************
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

//*********************************************** Function Declerations ***********************************************


//**************************************** Main Function / Program Entry Point ****************************************
int main()
{
    int iRandomNumber = 0;
    srand(time(NULL));
    iRandomNumber = (rand()%4) + 1;
    printf("%i\n", iRandomNumber);
    system("PAUSE");
}

// (rand() % x
// (rand() % x) +1
// (rand() %10) +1
// srand(seed);
// srand(time(NULL));
// time(NULL) requires #include <time.h>
// rand requires stdio.h

//***************************************************** Functions *****************************************************
