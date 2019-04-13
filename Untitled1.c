//
// Author: Andrew Combs
// Date: //2013
// Section: 2

//***************************************************** Includes *****************************************************
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//************************************************* Function Prototype ************************************************
float getFloat();

//**************************************** Main Function / Program Entry Point ****************************************
int main()
{
	printf("Float : ");
	float myFloat = getFloat();
	printf("/n/nYour float is : ");
}

//***************************************************** Functions *****************************************************
float getFloat(){									// Get a clean float with error checking
	float fIn = 0;											// Initialize a variable to hold the float we intend to get
	int c;													// Will be used as a character for error checking, must be int so can hold EOF
	
	while(scanf("%f", &fIn) != 1) {							// Attempts to read in a float, if successful move on
		printf("\n\t\t\t\tError: Non-Numeric");				// If not successful, print an error message
		printf("\n\t\t\t\tTry Again: ");
		while((c = getchar()) != EOF && c != '\n');			// And purge the buffer, then loop back and try again
	} // End of scanf error checking loop
	
	while((c = getchar()) != EOF && c != '\n');				// Purge the buffer
	
	return fIn;												// Return our nice clean float
}
