#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printer(int, char);
void delay(int);

int main()
{
    char *myString = "Hello World\n";
    
    printer(5, &myString);
        
    system("PAUSE");
}

void printer(int length, char stringToPrint)
{
//     int strLength = strlen(&stringToPrint);
     int i = 0;
//     printf("%d \n", i);
//     printf(stringToPrint);
     for(i = 0; i < 5; i++)
     {
         printf(stringToPrint[i]);
//         delay(400);
     }
}

void delay(int iAmountOfDelay)
{
     int c = 1, d = 1;
     
     for ( c = 1 ; c <= iAmountOfDelay ; c++ )
     {
         for ( d = 1 ; d <= 32767 ; d++ )
         {
         }
     }
     return;
}
