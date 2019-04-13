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
	myFile = fopen("C:/Users/Andrew/Desktop/test.txt", "r");
	if(myFile == NULL)
	{
		printf("Failure...");
		system("PAUSE");
		return 0;
	}
	char myString[100];// = { 'E', 'R', 'R', 'O', 'R', '\0' };
	//scanf("%s", myString);
	//fprintf(myFile, "%s", *myString);
	fscanf(myFile, "%s", &myString);
	fclose(myFile);
	printf("%s \n", myString);
	printf("Success!\n");
	system("PAUSE");
	return 0;
}

//***************************************************** Functions *****************************************************

