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
	FILE *myFile;
	myFile = fopen("C:/Users/Andrew/Desktop/test.txt", "w");
	if(myFile == NULL)
	{
		printf("Failure...");
		system("PAUSE");
		return 0;
	}
	int myInt;
	scanf("%d", &myInt);
	fprintf(myFile, "%d", myInt);
	//fprintf(myFile, "%s", "Hello World!");
	fclose(myFile);
	printf("Success!");
	system("PAUSE");
	return 0;
}

//***************************************************** Functions *****************************************************

