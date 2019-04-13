// Random Story Generator
// Author: Andrew Combs
// Date: 10/03/2013
// Section: 2

//***************************************************** Includes *****************************************************
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

//************************************************* Function Prototype ************************************************
void printStory();					// Prints the story to the screen
										// PARAMATERS: none
										// RETURNS: none
void genRands();					// Generates all the random content for the story
										// PARAMATERS: none
										// RETURNS: none
void capitalizeWords(char *);		// Capitalizes all words in a string
										// PARAMATERS: Pointer to a 'string' to be capitalized
										// RETURNS: none

// Initialize all strings
char sMomName[20];
char sName[20];
float fRStarDate;
char sFavoriteColor[20];
char sFavoriteFruit[20];
char sFriendName[20];
char sFavoriteNumber[20];
char sPetName[20];

char *sRLocation;
char *sRRank;
char *sRVerb;

//**************************************** Main Function / Program Entry Point ****************************************
int main()
{
	srand(time(NULL));						// Seed random number generator
	
	printf("Your Name: ");					// Prompt user for name
	gets(sName);							// Get string from user
	capitalizeWords(sName);					// Capitalize name
	
	printf("Your Mom's Name: ");			// Prompt user for mothers name
	gets(sMomName);							// Get string from user
	capitalizeWords(sMomName);					// Capitalize mothers name
	
	printf("Your Favorite Color: ");		// Prompt user for favorite color
	gets(sFavoriteColor);					// Get string from user
	
	printf("Your Favorite Fruit: ");		// Prompt user for favorite fruit
	gets(sFavoriteFruit);					// Get string from user
	
	printf("Your Friend's Name: ");			// Prompt user for friend's name
	gets(sFriendName);						// Get string from user
	capitalizeWords(sFriendName);			// Capitalize friend's name
	
	printf("Your Favorite Number: ");		// Prompt user for favorite number
	gets(sFavoriteNumber);					// Get string from user
	
	printf("Your Pet's Name: ");			// Prompt user for pet's name
	gets(sPetName);							// Get string from user
	capitalizeWords(sPetName);				// Capitalize pet's name
	
	genRands();								// Generate random values
	
	system("cls");							// Clear screen and
	printStory();							// Print story
	
	printf("\nPress Any Key to Exit...");	// Prompt user
	getch();								// Wait for user to press a key to exit
	system("cls");							// Clear screen
	
	return;									// Return
}

//***************************************************** Functions *****************************************************
void printStory() // Print the actuall story. Nothing fancy here, just printfs
{
	printf("--- Ships Log ---\n");
	printf("USS %s\n", sMomName);
	printf("Captain %s\n", sName);
	printf("Stardate %.2f\n", fRStarDate);
	printf("\n");
	printf("We're starting out on a long haul to %s.\n", sRLocation);
	printf("Unfortunately, we won't be able to enjoy any %s %s drinks because \n", sFavoriteColor, sFavoriteFruit);
	printf("%s %s broke the machine and we can't replace it till \n", sRRank, sFriendName);
	printf("we get to Starbase %s. Anyway, there's not much else to report. Now to \n", sFavoriteNumber);
	printf("%s %s...", sRVerb, sPetName);
	printf("\n");
	printf("--- End Log ---\n");
}

void genRands()										// Generate all random content
{
	char *rankArray[6];									// Array of possible values for rank
	rankArray[0] = "Cadet";
	rankArray[1] = "Yoeman";
	rankArray[2] = "Ensign";
	rankArray[3] = "Lieutenant";
	rankArray[4] = "Lieutenant Commander";
	rankArray[5] = "Commander";
	
	char *locArray[6];									// Array of possible values for location
	locArray[0] = "the Madusa Cascade";
	locArray[1] = "Deep Space 9";
	locArray[2] = "Babylon 5";
	locArray[3] = "Kobol";
	locArray[4] = "Miranda";
	locArray[5] = "Earth";
	
	char *verbArray[6];									// Array of possible verb obtions
	verbArray[0] = "find";
	verbArray[1] = "rescue";
	verbArray[2] = "feed";
	verbArray[3] = "kick";
	verbArray[4] = "eat";
	verbArray[5] = "experiment on";
	
	int i = 0;											// Create variable to hold random 
	
	i = rand() % 6;										// Generate a random number between zero and six and write to i
	sRRank = rankArray[i];								// Pull value of rankArray at i and set sRRank to it
	
	i = rand() % 6;										// Generate a random number between zero and six and write to i
	sRLocation = locArray[i];							// Pull value of locArray at i and set sRLocation to it
	
	i = rand() % 6;										// Generate a random number between zero and six and write to i
	sRVerb = verbArray[i];								// Pull value of rankArray at i and set sRVerb to it
	
	fRStarDate = ((float)((rand() % 500000) + 139227857529)) / 100; // Generate a random number and do some math to it to get a random star date value
	
	return;												// Return
}

void recursiveWordCapitalizer(char *capString)			// Recursive component of word capitilization. 
{																// Note: Not prototyped because should only be called by capitalizeWords
	char *locOfSpace;										// Create pointer to hold location of space
	locOfSpace = strchr(capString, ' ');					// Search for a space and set our new pointer to its location
	if(!locOfSpace) { return; }								// If a space wasn't found return out
	locOfSpace++;											// Move pointer to char after space in array, ie first letter of word
	if( *locOfSpace > 96  &&  *locOfSpace < 123 )			// If the first letter in the string is lower case )ASCII value between 96 and 123 inclusive (
	{
		*locOfSpace -= 32;									// Capitalize the letter by subtracting 32 from the ASCII value
	}
	recursiveWordCapitalizer(locOfSpace);					// Call ourself with remaining string
	return;													// When all the spaces are gone we'll return all the way up and exit the function
}

void capitalizeWords(char *capString)					// Implement capitilization of words in a string
{
	if(*capString > 96 && *capString < 123)					// If the first letter in the string is lower case )ASCII value between 96 and 123 inclusive (
	{
		*capString -= 32;									// Capitalize the letter by subtracting 32 from the ASCII value
	}
	
	recursiveWordCapitalizer(capString);					// Call the recursive capitilization function
	
	return;													// When all the spaces are gone we'll return all the way up and exit the function
}
