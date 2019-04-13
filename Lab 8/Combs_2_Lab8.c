// Contact Book III
// Author: Andrew Combs
// Date: 10/31/2013
// Section: 2

/*	A Coupe Notes : This program is, admitadly, not quite what I wanted it to be. Firstly, I intended to implement printFileNames
	functionality in a header file, this is why the code is seperated by whitespace and ' #include "dir.h" ' has been commented
	out. And of course there's the "contactView" feature that has been here, un-implemented, since v1. And the whole thing could
	stand for more documentation, UI polishing, and error checking. But on the whole, for the time I've been able to invest in it,
	I feel it satisfies the requirenments well. One additoinal note, the functionality for printFileNames, while largely modified,
	was origionally copied from code at this location : 
	http://stackoverflow.com/questions/19338823/copying-file-names-into-an-array-with-c
	*/

//***************************************************** Includes *****************************************************
#include <stdio.h>							// Include standard input output header
#include <stdlib.h>							// Include standard library header
#include <conio.h>							// Include co io header
#include <math.h>							// Include math header
#include <time.h>							// Include time header
//#include "dir.h"
#include <dirent.h>
#include <string.h>
#include <stdbool.h>

#define stdDelay 1500						// Define delays; easier to change for debugging and harder to miss when switching back

const char *CsVersionNum = "3.0.0";			// Program version number
const char *CsVersionDate =  "10/31/13";	// Program compile date

//*********************************************** Structure Definitions ***********************************************
typedef struct CONTACT {
	char sFirstName[20];			// First name of contact
	char sLastName[20];				// Last name of contact
	char sPhoneNumber[20];			// Phone number of contact
} contact;

struct contactArray {
	contact *contacts;				// Pointer to first element of array of contacts
	int numOfContacts;				// Number of contacts in array
	int contactsIndex;				// Our current index location in the array
};

//************************************************* Function Prototype ************************************************
void printSplash();												// Print ASCII art splash screen, used on load and exit of program
																	// REQUIRES: stdio.h
																	// PARAMATERS: none
																	// RETURNS: none
void clearToHeader();											// Clears the screen with system("cls") and prints a one line program header
																	// REQUIRES: stdio.h, stdlib.h
																	// PARAMATERS: none
																	// RETURNS: none
void printMenu();												// Prints the program's main menu
																	// REQUIRES: stdio.h
																	// PARAMATERS: none
																	// RETURNS: none
void printAbout();												// Print a screen displaying information about the program such as author name and compile date
																	// REQUIRES: stdio.h
																	// PARAMATERS: none, but accesses global constants CsVersionNum and CsVersionDate
																	// RETURNS: none
void contactAdd(struct contactArray *);							// UI and functionality to add contact to contact book
																	// REQUIRES: 
																	// PARAMATERS: A pointer to the contactArray structure to be added to
																	// RETURNS: void
void contactDelete(struct contactArray *);						// UI and functionality to delete contact from contact book
																	// REQUIRES: 
																	// PARAMATERS: 
																	// RETURNS: 
void contactList(struct contactArray *);						// Lists all contacts in contact book on screen
																	// REQUIRES: 
																	// PARAMATERS: A pointer to the contactArray structure to be viewed
																	// RETURNS: void
/* Not Yet Implemented
void contactView(struct contactArray *);						// UI to browse and view contacts in contact book
																	// REQUIRES: 
																	// PARAMATERS: 
																	// RETURNS: 
*/
void contactSearch(struct contactArray *);						// UI and functionality to search for a specific contact
																	// REQUIRES: 
																	// PARAMATERS: 
																	// RETURNS: 
void contactRandom(struct contactArray *);						// UI and functionality to show a random contact
																	// REQUIRES: 
																	// PARAMATERS: 
																	// RETURNS: 
void contactDeleteAll(struct contactArray *, int);				// UI and functionality to delete all contacts from contact book
																	// REQUIRES: 
																	// PARAMATERS: The current contact book; int : 0 = Use UI, 1 = Delete all no UI
																	// RETURNS: 
int contactLoadUI(struct contactArray *);						// UI to load contact book from file
																	// REQUIRES: 
																	// PARAMATERS: Contact book to be loaded into
																	// RETURNS: An int for error checking. = -2 : Memory failure
																	//										  1 : Success
int contactLoadFunc(FILE *, struct contactArray *);				// Functionality to load contact book from file
																	// REQUIRES: 
																	// PARAMATERS: File pointer to file to load from; contact book to be loaded into
																	// RETURNS: An int for error checking. = -1 : Incorrect file format / corrupt file
																	//										 -2 : Memory failure
																	//										  1 : Success
int contactSaveUI(struct contactArray *);						// UI to save contact book to file
																	// REQUIRES: 
																	// PARAMATERS: Contact book to be loaded into
																	// RETURNS: An int for error checking. = -2 : Memory failure
																	//										  1 : Success
int contactSaveFunc(FILE *, struct contactArray *);				// Functionality to save contact book to file
																	// REQUIRES: 
																	// PARAMATERS: File pointer to file to load from; contact book to be loaded into
																	// RETURNS: An int for error checking. = -2 : Memory failure
																	//										  1 : Success
void contactSave(struct contactArray *);						// UI and functionality to delete all contacts from contact book
																	// REQUIRES: 
																	// PARAMATERS: 
																	// RETURNS: 
int getInt();													// Scans in int with error checking
																	// REQUIRES: stdio.h, conio.h
																	// PARAMATERS: none
																	// RETURNS: int scanned
float getFloat();												// Scans in float with error checking
																	// REQUIRES: stdio.h, conio.h
																	// PARAMATERS: none
																	// RETURNS: float scanned
void delay(int);												// Delays the program for a specified abount of time. EXTREAMLY POOR IMPLEMENTATION! Needs signifigant improvement to be reliable
																	// RETURNS: none
																	// RETURNS: int amount of time to delay, very unreliable
int isrtContactAlpha(contact *, struct contactArray *);			// Insert a contact into a contactArray sorted A-Z )ignore case( 
																	// REQUIRES: 
																	// PARAMATERS: A pointer to the contact to be added; A pointer to the contactArray structure to be added to
																	// RETURNS: An int for error checking. -1 indicates failure.
int rmContactAlpha(contact *, struct contactArray *);			// Remove a contact from a contactArray resizing array
																	// REQUIRES: 
																	// PARAMATERS: A pointer to a contact containing first and last name of contact to be deleted;
																	//				A pointer to the contactArray structure to be deleted from
																	// RETURNS: An int for error checking.	-1 : memory could not be allocated
																	//										-2 : contact could not be found in array






bool ends_with(char *str, char *sub);					// Check if a string ends with a specified sub string
															// PARAMATERS:	char *str : The string to be checked
															//				char *sub : The ending to look for
															// RETURNS:	bool	true : String has specified ending or boh are NULL
															//					false : String does not have ending or one but not both are NULL

int array_find(char *key, char *argv[], int argc);		// Check if a string ends with a specified sub string
															// PARAMATERS:	char *str : The string to be checked
															//				char *sub : The ending to look for
															// RETURNS:	bool	true : String has specified ending or boh are NULL
															//					false : String does not have ending or one but not both are NULL
int printFileNames(const char *dirname, char *suffix);







//**************************************** Main Function / Program Entry Point ****************************************
int main()
{
	struct contactArray contactBook;						// Create a new contactArray as ContactBook
	contactBook.contacts = NULL;							// Set the pointer equal to NULL )as opposed to junk value(
	contactBook.numOfContacts = 0;							// Set numOfContacts equal to zero )as opposed to junk value(
	
	srand(time(NULL));										// Seed the random number generator
	
	char menuSelect = '_';									// Create a variable to hold user selection on main menu
	
	printSplash();											// Print the splash screen
	delay(stdDelay);											// Hold splash screen
//	contact newContact;
	while(1)											// Begin main program loop
	{
		clearToHeader();									// Clear splash screen and print header
		printMenu();										// Print menu to screen
		
		menuSelect = getch();								// Get user menu selection
		
		if(menuSelect == 'x' || menuSelect == 'X')			// If user requested exit, break main loop
			break;
		
		if(menuSelect == 27) {								// If user presses escape, end program immidiately
			if(contactBook.contacts != NULL) {					// If our array of contacts has had memory allocated to it
				free(contactBook.contacts); }						// Free the memory
			return; }											// Then return out of main

		clearToHeader();									// Clear menu from screen but replace header
		
		switch (menuSelect)								// Use switch to process additional user input values
		{
			case 'a': case 'A': case '1': {					// Case to add contact
				contactAdd(&contactBook);
				break; }
			case 'd': case 'D': case '2': {					// Case to delete contact
				contactDelete(&contactBook);
				break; }
			case 'l': case 'L': case '3':					// Case to view a list of contacts
				contactList(&contactBook);
				break;
			case 'v': case 'V': case '4':					// Not yet Implemented
				//contactView(&contactBook);
				break;
			case 'f': case 'F': case '5':					// Case to search for contact
				contactSearch(&contactBook);
				break;
			case 'r': case 'R': case '6':					// Case to delete all contacts
				contactRandom(&contactBook);
				break;
			case 'k': case 'K': //case '0':					// Case to delete all contacts
				contactDeleteAll(&contactBook, 0);
				break;
			case 'o': case 'O': //case '0':					// Case to load contacts from file
				contactLoadUI(&contactBook);
				break;
			case 's': case 'S': case '0':					// Case to save contacts to file
				contactSaveUI(&contactBook);
				break;
			case 'i': case 'I':								// Case to view program information
				printAbout();
				break;
			default:
				printf("\n\t\t\t");								// Print error message
				printf("ERROR: Syntax \n\t\t\t");
				printf("The character you entered is not \n\t\t\t");
				printf("recognized as a valid operator \n\n\t\t\t");
				printf("Please try again.");
				printf("\n\n\n\n\t\t\t\t\t\t\t\t\t");
				delay(stdDelay/2);							// Hold error message on screen
				break;											// Exit the switch and loop back
		} // End of main menu switch
	} // End of main program loop							// When the user selects to exit the program
	system("cls");												// Clear the screen
	printSplash();												// Print the splash screen
	delay(stdDelay);											// Hold splash screen
	if(contactBook.contacts != NULL) {							// If our array of contacts has had memory allocated to it
		free(contactBook.contacts); }								// Free the memory
	system("cls");												// Clear the screen
	return 0;													// Exit program
}

//***************************************************** Functions *****************************************************

//  ############################################# printSplash #############################################  //

void printSplash()
{								// Print ASCII art splash screen
	printf("#########################################################################\n");
	printf("#########################################################################\n");
	printf("#########################################################################\n");
	printf("#########################################################################\n");
	printf("#########################################################################\n");
	printf("#####        __         __         __      _    __    __            #####\n");
	printf("#####       |  \\ |  |  /  \\ |\\  | |       | \\  /  \\  /  \\ | /       #####\n");
	printf("#####       |__/ |--|  |  | | \\ | |-      |-<  |  |  |  | |\\        #####\n");
	printf("#####       |    |  |  \\__/ |  \\| |__     |_/  \\__/  \\__/ | \\       #####\n");
	printf("#####                                                               #####\n");
	printf("#####                       -Andrew Combs-                          #####\n");
	printf("#####                                                               #####\n");
	printf("#########################################################################\n");
	printf("#########################################################################\n");
	printf("#########################################################################\n");
	printf("#########################################################################\n");
	printf("#########################################################################\n");
	return;
}

//  ############################################# clearToHeader #############################################  //

void clearToHeader()
{																							// Clear screen and print header line
	system("cls");																				// Use terminal command cls to clear screen
	printf("############################# Contact Book III ############################\n");		// Print header line
	return;																						// End function and return
}

//  ############################################# printMenu #############################################  //

void printMenu()
{														// Print main menu
	printf("\n\t\t\t");										// Move cursor to position
	printf("A     (1) Add Contact \n\t\t\t");				// Add: a or 1
	printf("D     (2) Delete Contact \n\n\t\t\t");			// Delete: d or 2
	printf("L     (3) List Contacts \n\t\t\t");				// List: l or 3
	printf("V     (4) View Contact Book \n\n\t\t\t");		// View: v or 4
	printf("F     (5) Search For Contact \n\t\t\t");		// List: s or 5
	printf("R     (6) Random Contact \n\n\t\t\t");			// List: r or 6
	printf("K     (0) Delete All Contacts \n\n\t\t\t");		// View: k or 0
	printf("    ---------------------------- \n\n\t\t\t");	// Print formatting line
	printf("I     Info  \t  O     Load \n\t\t\t");			// About: I or i
	printf("X     Exit  \t  S     Save ");					// Exit: X or x
	printf("\n\n\n\n\t\t\t\t\t\t\t\t\t");					// Formatting
	return;													// End function and return
}

//  ############################################# printAbout #############################################  //

void printAbout()
{														// Detail information about program
	 printf("\n\n\n\t\t\t");								// Move cursor to position
	 printf("Contact Book III\n\n\t\t\t");						// Program name
	 printf("Author:  Andrew Combs\n\t\t\t");				// Author name
	 printf("Version: %s \n\t\t\t", CsVersionNum);			// Version number, from constant
	 printf("Date:    %s \n\n\t\t\t", CsVersionDate);		// Version Date, from constant
	 printf("CECS 130-02     Lab 8 \n\n\n\t\t");			// Class, section and lab program was written for
	 printf("    Press any key to continue...");			// Prompt user
	 getch();												// Wait for key press
	 return;												// End function and return
}

//  ############################################# contactAdd #############################################  //

void contactAdd(struct contactArray *contactBook)
{
	contact addContact;										// Create a new contact to be added
	printf("\nContact First Name : ");						// Fill the contact with information from the user
	scanf("%s", addContact.sFirstName);
	printf("\nContact Last Name : ");
	scanf("%s", addContact.sLastName);
	printf("\nContact Phone Number : ");
	scanf("%s", addContact.sPhoneNumber);
	
	isrtContactAlpha(&addContact, contactBook);				// Call isrtContactAlpha to insert our new contact into the array
}

//  ############################################# contactDelete #############################################  //

void contactDelete(struct contactArray *contactBook)
{
	contact delContact;											// Create a contact to compare to our array
	
	printf("\nContact First Name : ");							// Fill the contact with information from the user
	scanf("%s", delContact.sFirstName);
	printf("\nContact Last Name : ");
	scanf("%s", delContact.sLastName);
	
	int status = rmContactAlpha(&delContact, contactBook);		// Call rmContactAlpha to remove the contact from the array
	
	clearToHeader();											// Clear the screen
	switch( status )
	{
		case -2:												// If rmContactAlpha returned -2 warn user that contact doesn't exist
			printf("Warning! Specified contact does not exist.");
			break;
		case -1:												// If rmContactAlpha returned -1 warn user that memory could not be allocated
			printf("ERROR: Memory allocation failed!");
			break;
		case 1:													// If rmContactAlpha returned 1 inform user that contact was deleted successfully
			printf("Contact deleted successfully.");
			break;
		default:												// If rmContactAlpha returns a different value print a generic error message
			printf("ERROR: Unknown error.");
			break;
	}
	delay(stdDelay/2);											// Hold the eror message on the screen before returning
}

//  ############################################# contactList #############################################  //

void contactList(struct contactArray *contactBook)
{
	if(contactBook->numOfContacts == 0)							// If the array is empty don't try to display contacts
	{
		printf("\n\n\t\tNo contacts to display");
		printf("\n\n\t\tPress any key to continue...");
		getch();
		return;
	}
	contactBook->contactsIndex = 0;								// Set the index to the first location in the array
	clearToHeader();											// Clear the screen
	printf("Name\t Phone Number\n");							// Print a header describing information displayed
	for(; (contactBook->contactsIndex) < (contactBook->numOfContacts); (contactBook->contactsIndex)++)
	{															// Iterate through array
		if(&(contactBook->contacts[contactBook->contactsIndex]) == NULL) {	// If contact is null, don't display it
			continue; }			// )This will never happend and is completely unneeded, but it's in the assignment(
		contact listContact = contactBook->contacts[contactBook->contactsIndex];
		char *firstName = listContact.sFirstName;
		char *lastName = listContact.sLastName;
		char *phoneNumber = listContact.sPhoneNumber;
		printf("\n%s %s \t %s", firstName, lastName, phoneNumber);	// Print the contact
	}	// End of for loop
	printf("\n\nPress any key to continue...");					// Prompt user to return
	getch();
}

//  ############################################# contactView #############################################  //

/* Not Yet Implemented
void contactView(struct contactArray *contactBook)
{
	
}*/

//  ############################################# contactSearch #############################################  //

void contactSearch(struct contactArray *contactBook)
{
	contact searchContact;										// Create a contact to compare to our array
	
	printf("\nContact First Name : ");							// Fill the contact with information from the user
	scanf("%s", searchContact.sFirstName);
	printf("\nContact Last Name : ");
	scanf("%s", searchContact.sLastName);
	
	// Set our index equal to 0, iterate through all array indecies till the end of the array
	for((contactBook->contactsIndex) = 0; (contactBook->contactsIndex) < (contactBook->numOfContacts); (contactBook->contactsIndex)++)
	{
		// Create a temporary contact equal to the contact at our current index. We don't necessarily /need/ to do this, but it really cleans things up.
		contact curContact = contactBook->contacts[contactBook->contactsIndex];
		// Compare the first and last name of the contact at the current index to the first and last name of the contact we want to find.
		// If the names match we have the index of the contact we want to find, so break with current index.
		if ((strcmp((searchContact.sLastName), curContact.sLastName) == 0) && (strcmp((searchContact.sFirstName), curContact.sFirstName) == 0)) {
			break; }
	} // End of for loop, curContact is now gone, contactsIndex points to contact we found
	
	clearToHeader();											// Clear the screen
	
	// If the index is past the end of the array we know we didn't find the contact
	if (contactBook->contactsIndex >= contactBook->numOfContacts)
	{
		printf("\n\n\t\tContact not found.");
	} else {	// Else print the contact
		contact foundContact = contactBook->contacts[contactBook->contactsIndex];
		printf("\n\n\t\tFirst Name   : %s", foundContact.sFirstName);
		printf("\n\t\tLast Name    : %s", foundContact.sLastName);
		printf("\n\t\tPhone Number : %s", foundContact.sPhoneNumber);
	}
	
	printf("\n\n\t\tPress any key to continue...");				// Prompt user to return
	getch();
}

//  ############################################# contactRandom #############################################  //

void contactRandom(struct contactArray *contactBook)
{
	contactBook->contactsIndex = (rand() % contactBook->numOfContacts);			// Set the index to a random valid value
	clearToHeader();															// Clear the screen
	
	contact randContact = contactBook->contacts[contactBook->contactsIndex];	// Create a temporary contact to hold the random contact
	printf("\n\n\t\tFirst Name   : %s", randContact.sFirstName);				// Print the contact
	printf("\n\t\tLast Name    : %s", randContact.sLastName);
	printf("\n\t\tPhone Number : %s", randContact.sPhoneNumber);
	
	printf("\n\nPress any key to continue...");									// Prompt user to return
	getch();
}

//  ############################################# contactDeleteAll #############################################  //

void contactDeleteAll(struct contactArray *contactBook, int noUI)
{
	if(noUI == 0)
	{	// If UI is to be used :
		if(contactBook->contacts == NULL)							// If the contact book is empty, inform the user and exit
		{
			printf("\n Contact book is already empty.");
			delay(stdDelay/2);
			return;
		}
		
		char confirmDelete = 'n';									// Make sure the user wants to delete all contacts
		printf("\nAre you sure you want to delete all contacts? \nThey will be gone forever. )A /very/ long time( \n(y/n) : ");
		confirmDelete = getch();
		
		char absolutelyPositive = 'n';	
		if(confirmDelete == 'y' || confirmDelete == 'Y')
		{							// Make _ver_ sure the user wants to delete all contacts
			printf("\nAre you absolutely positive? \n!Forever! \n(y/n) : ");
			absolutelyPositive = getch();
		}
		
		clearToHeader();											// Clear the screen
		
		if((confirmDelete == 'y' || confirmDelete == 'Y') && (absolutelyPositive == 'y' || absolutelyPositive == 'Y'))
		{															// If the user confirmed that they want to delete all contacts
			free(contactBook->contacts);								// Free the allocated memory
			contactBook->contacts = NULL;								// Set our array pointer to NULL
			contactBook->numOfContacts = 0;								// Set numOfContacts to zero
		
			printf("\nContacts Deleted!");								// Tell the user contacts have been deleted
		} else {
			printf("\nDelete Canceled");							// Else tell user deleting is canceled
		}
		
		delay(stdDelay/2);											// Hold results on screen
	} else {	// If we just want to delete contacts, no UI :
		if(contactBook->contacts == NULL) {							// If the contact book is empty, exit
			return; }
		
		free(contactBook->contacts);								// Free the allocated memory
		contactBook->contacts = NULL;								// Set our array pointer to NULL
		contactBook->numOfContacts = 0;								// Set numOfContacts to zero
	}	// End if
}

//  ############################################# contactLoad #############################################  //

int contactLoadUI(struct contactArray *contactBook)
{
	char filePath[512];
	FILE *loadFile;
	int c;
	
	clearToHeader();
	
// Establish working dir
	char workingDir[256];
	printf("\n Would you like to use the default directory? (y/n) : ");
	
	char useStdDir = getch();
	switch (useStdDir)
	{
		case 'n': case 'N':
		{
			printf("\n\n Please specify directory path : ");
			scanf("%s", &workingDir);
			DIR *dir = opendir(workingDir);
			if( dir == NULL){
				printf("\n\n Warning! Directory does not exist.");
				printf("\n Press any key to continue... ");
				getch();
				closedir(dir);
				return contactLoadUI(contactBook);
			} // End If
			break;
		} // End Case 
		case 'y': case 'Y': case 10: case 13:
		{
			strcpy(workingDir, getenv("APPDATA"));
			strcat(workingDir, "\\CECS130");
			DIR *dir = opendir(workingDir);
			if( dir == NULL){
				if (mkdir(workingDir) != 0) {
					perror( "\n MKDir Error "); }
					 }
			closedir(dir);
			
			strcat(workingDir, "\\ContactBookIII\\");
			dir = opendir(workingDir);
			if( dir == NULL){
				if (mkdir(workingDir) != 0) {
					perror( "\n MKDir Error "); }
					 }
			closedir(dir);
			break;
		} // End Case
		case 27:
			return 2;
		default:
			printf("\n\n Error : Invalid input.");
			printf("\n Press any key to continue");
			getch();
			return contactLoadUI(contactBook);
	}
	
	// Establish file name
	char fileName[128];
	printf("\n\n List of current files : \t (Choose file from list)\n");
	printFileNames(workingDir, ".dat");
	printf("\n\n Please specify file name : ");
	scanf("%s", &fileName);
	
	strcat(workingDir, fileName);
	
	loadFile = fopen(workingDir, "r");
	if(loadFile == NULL) {
		perror( "Access Error" ); }
	int error = contactLoadFunc(loadFile, contactBook);
	fclose(loadFile);
	
	system("PAUSE");
	
	return error;
}

int contactLoadFunc(FILE *loadFile, struct contactArray *contactBook)
{
	contactDeleteAll(contactBook, 1);
	int numOfContacts;
	if( fscanf(loadFile, "%d", &numOfContacts) > 0 )
	{
		int i;
		for(i = 0; i < numOfContacts; i++)
		{
			contact addContact;										// Create a new contact to be added
			fscanf(loadFile, "%s", addContact.sFirstName);						// Fill the contact with information from the user
			fscanf(loadFile, "%s", addContact.sLastName);
			fscanf(loadFile, "%s", addContact.sPhoneNumber);
			
			int error = isrtContactAlpha(&addContact, contactBook);	// Call isrtContactAlpha to insert our new contact into the array
			if(error != 1) {
				return -2; }
		}
	} else {
		return -1;
	}
	return 1;
}

//  ############################################# contactSave #############################################  //

int contactSaveUI(struct contactArray *contactBook)
{
	char filePath[512];
	FILE *saveFile;
	int c;
	
	clearToHeader();
	
	// Establish working dir
	char workingDir[256];
	printf("\n Would you like to use the default directory? (y/n) : ");
	
	char useStdDir = getch();
	switch (useStdDir)
	{
		case 'n': case 'N':
		{
			printf("\n\n Please specify directory path : ");
			scanf("%s", &workingDir);
			DIR *dir = opendir(workingDir);
			if( dir == NULL){
				printf("\n\n Warning! Directory does not exist.");
				printf("\n Press any key to continue... ");
				getchar();
				closedir(dir);
				return contactSaveUI(contactBook);
			} // End If
			break;
		} // End Case 
		case 'y': case 'Y': case 10: case 13:
		{
			strcpy(workingDir, getenv("APPDATA"));
			strcat(workingDir, "\\CECS130");
			DIR *dir = opendir(workingDir);
			if( dir == NULL){
				if (mkdir(workingDir) != 0) {
					perror( "\n MKDir Error "); }
					 }
			closedir(dir);
			
			strcat(workingDir, "\\ContactBookIII\\");
			dir = opendir(workingDir);
			if( dir == NULL){
				if (mkdir(workingDir) != 0) {
					perror( "\n MKDir Error "); }
					 }
			closedir(dir);
			break;
		} // End Case
		case 27:
			return 2;
		default:
			printf("\n\n Error : Invalid input.");
			printf("\n Press any key to continue");
			getch();
			return contactSaveUI(contactBook);
	}
	
	char fileName[128];
	printf("\n\n List of current files : \n (Choose file from list or choose a new file name)\n");
	printFileNames(workingDir, ".dat");
	printf("\n\n Please specify file name : ");
	scanf("%s", &fileName);
	
	strcat(workingDir, fileName);
	strcat(workingDir, ".dat");
	
	saveFile = fopen(workingDir, "w");
	if(saveFile == NULL) {
		perror( "Access Error" ); }
	int error = contactSaveFunc(saveFile, contactBook);
	fclose(saveFile);
	
	system("PAUSE");
	
	return error;
}

int contactSaveFunc(FILE *saveFile, struct contactArray *contactBook)
{
	fprintf(saveFile, "%d\n", contactBook->numOfContacts);
	for (contactBook->contactsIndex = 0; contactBook->contactsIndex < contactBook->numOfContacts; contactBook->contactsIndex++) {
		contact saveContact;
		saveContact = *(contactBook->contacts + contactBook->contactsIndex);
		fprintf(saveFile, "%s ", saveContact.sFirstName);						// Fill the contact with information from the user
		fprintf(saveFile, "%s ", saveContact.sLastName);
		fprintf(saveFile, "%s \n", saveContact.sPhoneNumber);
	}
	return 1;
}

//  ############################################# getInt #############################################  //

int getInt(){
	int iIn = 0;											// Initialize a variable to hold the int we intend to get
	int c;													// Will be used as a character for error checking, must be int so can hold EOF
	
	while(scanf("%d", &iIn) != 1) {							// Attempts to read in an int, if successful move on
		if(getchar() == '.') {								// If not successful, print an error message
			printf("\n\t\t\t\tError: Non-Integer");				// If error was caused by decimal place print appropriate message
		} else {
			printf("\n\t\t\t\tError: Non-Numeric"); }			// Else print generic error message
		printf("\n\t\t\t\tTry Again: ");
		while((c = getchar()) != EOF && c != '\n');			// And purge the buffer, then loop back and try again
	} // End of scanf error checking loop
	
	while((c = getchar()) != EOF && c != '\n');				// Purge the buffer
	
	return iIn;
}

//  ############################################# getFloat #############################################  //

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

//  ############################################# delay #############################################  //

void delay(int iAmountOfDelay)
{																				// Delay Function
     int c = 1, d = 1, e = 1;														// Create counters for for loops
     
     for ( c = 1 ; c <= iAmountOfDelay ; c++ )										// Outer for loop, loops number of times specified by parameter
     {
	 	for ( d = 1 ; d <= 32000 ; d++ )											// Inner for loop, loops huge number of times to waste time on fast processor
         {
         	sqrt(d);																// Do big long operation that takes a lot of time
         }
     }
return;
}

//  ############################################# isrtContactAlpha #############################################  //

int isrtContactAlpha(contact *isrtContact, struct contactArray *contactBook)
{
// Allocate more space to our contact array so we can add a contact
	// If the contact book is empty, we have to use malloc to allocate it memory
	if(contactBook->contacts == NULL)
	{
		// Set our currently null pointer equal to a pointer from malloc of size one contact
		contactBook->contacts = (contact*)malloc(sizeof(contact));
		// If memory couldn't be aquired to expand list return -1 )fail(
		if (contactBook->contacts == NULL) { return -1; }
	// However if it allready contains data we will want to preserve those values, so we use realloc
	} else {
		// Create a new contact array pointer and set it equal to the re-allocation of our old contact array pointer with room for one more contact.
		// We use a new pointer so if realloc fails to get memory we don't affect the origonal array in any way before returning fail.
		contact *newContacts = realloc((contactBook->contacts), (((contactBook->numOfContacts)+1) * sizeof(contact)));
		// If memory couldn't be aquired to expand array return -1 )fail(
		if (newContacts == NULL) { return -1; }
		// Set our old ponter to the same location as our new pointer. When we leave the if our new pointer will go away.
		(contactBook->contacts) = newContacts;
	}
	// Increase the number of contacts by one so our counter matches our array
	(contactBook->numOfContacts)++;
	
// Find what location in our array we want to put our new contact in
	// Set our index equal to 0, iterate through all array indecies till the end of the array
	for((contactBook->contactsIndex) = 0; (contactBook->contactsIndex) < (contactBook->numOfContacts); (contactBook->contactsIndex)++)
	{
		// Create a temporary contact equal to the contact at our current index. We don't necessarily /need/ to do this, but it really cleans things up.
		contact curContact = contactBook->contacts[contactBook->contactsIndex];
		// Compare the last name of the contact at the current index to the last name of the contact we want to insert.
		// If our new new contact goes before it, we have the index we want to insert our new contact at, so break with the current index.
		if (strcmp((isrtContact->sLastName), curContact.sLastName) < 0) {
			break; }
	} // End of for loop, curContact is now gone
	
// Insert our new contact moving everything to the right of it over one
	
	if((contactBook->contactsIndex) == ((contactBook->numOfContacts)))
	{
		*((contactBook->contacts) + ((contactBook->numOfContacts) - 1)) = *isrtContact;
	}
	// Starting at our current index, iterate through all remaining contacts in the array
	for(; (contactBook->contactsIndex) < (contactBook->numOfContacts); (contactBook->contactsIndex)++)
	{
		// Create a new contact and put the contact in the current index of the array in it
		contact tempContact = contactBook->contacts[contactBook->contactsIndex];
		// Put the contact we are inserting into the current index of our contact array
		*((contactBook->contacts) + (contactBook->contactsIndex)) = *isrtContact;
		// Put our temporary contact into the contact we are inserting
		*isrtContact = tempContact;
		// Loop around doing this until we hit the last contact in the array, which will be pushed off the end and deleted.
		// This is fine because it is just a trash value given to us by realloc()
	} // End of for loop, tempContact is now gone
	// Return 1 for success
	return 1;
} // End of isrtContactAlpha function.

//  ############################################# rmContactAlpha #############################################  //

int rmContactAlpha(contact *delContact, struct contactArray *contactBook)
{
	// Create a new )temporary( array one contact smaller than the current array
	contact *delArray = (contact*)malloc((contactBook->numOfContacts - 1) * sizeof(contact));
	// If memory couldn't be aquired for new array return -1 )Error: Memory could not be allocated(
	if (delArray == NULL) { return -1; }

// Find the location of the contact we want to delete
	// Set our index equal to 0, iterate through all array indecies till the end of the array
	for((contactBook->contactsIndex) = 0; (contactBook->contactsIndex) < (contactBook->numOfContacts); (contactBook->contactsIndex)++)
	{
		// Create a temporary contact equal to the contact at our current index. We don't necessarily /need/ to do this, but it really cleans things up.
		contact curContact = contactBook->contacts[contactBook->contactsIndex];
		// Compare the first and last name of the contact at the current index to the first and last name of the contact we want to delete.
		// If the names match we have the index of the contact we want to delete, so break with current index.
		if ((strcmp((delContact->sLastName), curContact.sLastName) == 0) && (strcmp((delContact->sFirstName), curContact.sFirstName) == 0)) {
			break; }
	} // End of for loop, curContact is now gone, contactsIndex points to contact to be deleted
	// If the index is past the end of the array we know we didn't find the contact we wanted to delete
	if (contactBook->contactsIndex >= contactBook->numOfContacts) {
		// So return -2, contact not found
		return -2; }
	
	if((contactBook->contactsIndex) == ((contactBook->numOfContacts) - 1))
	{
	// Copy our old array into our new one, skipping the contact we want to remove
		// Initialize our counters
		int delArrayIndex = 0;
		int i = 0;
		// Iterate through our array, using i instead of contactsIndex because contactsIndex has the location of the contact we wish to delete
		for(i = 0; i < (contactBook->numOfContacts - 1); i++)
		{
			// Copy one contact from old array to new one
			*(delArray + delArrayIndex) = *(contactBook->contacts + i);
			// If its not the one we want to delete, move to the next contact in the array
			// If it is, stay on the same contact so we over write it and our index stays off by one so array is one smaller
			if( i != contactBook->contactsIndex ) {
				delArrayIndex++; }
		}
	} else {
	// Copy our old array into our new one, skipping the contact we want to remove
		// Initialize our counters
		int delArrayIndex = 0;
		int i = 0;
		// Iterate through our array, using i instead of contactsIndex because contactsIndex has the location of the contact we wish to delete
		for(i = 0; i < contactBook->numOfContacts; i++)
		{
			// Copy one contact from old array to new one
			*(delArray + delArrayIndex) = *(contactBook->contacts + i);
			// If its not the one we want to delete, move to the next contact in the array
			// If it is, stay on the same contact so we over write it and our index stays off by one so array is one smaller
			if( i != contactBook->contactsIndex ) {
				delArrayIndex++; }
		}
	}
	
	// Free the memory held by our old contact array
	free(contactBook->contacts);
	// Change the pointer to our old )now freed( contact array to our new contact array. The new array's pointer will go away, but its memory will stay, so this is valid
	(contactBook->contacts) = delArray;
	
	// Decrease the number of contacts by one so our counter matches our new array
	(contactBook->numOfContacts)--;
	// Return 1 for success
	return 1;
} // End of rmContactAlpha function.








int array_find(char *key, char *argv[], int argc)
{
	int i;
    for (i = 0; i < argc; i++)
    {
        if (strcmp(key, argv[i]) == 0)
            return i;
    }
    return -1;
}

bool ends_with(char *str, char *sub)													// | Function determines if a string ends with another string
{																						// | 
    if (str == NULL && sub == NULL) {													// | 	// Checks if both strings are NULL
        return true; }																	// | 		// If so, return true
    if (str == NULL || sub == NULL) {													// | 	// Checks if one but not both strings are NULL
        return false; }																	// | 		// If so, return false
    char *last_instance_of_sub = strrchr(str, *sub);									// | 	// Get a pointer to the last occourance of substring in string
    size_t sub_len = strlen(sub);														// | 	// Get the size of the sub string
    if (last_instance_of_sub == NULL || strlen(last_instance_of_sub) != sub_len)		// | 	// If substring isn't in string or it's not the last thing in the string
        return false;																	// | 		// return false
    return strcmp(last_instance_of_sub, sub) == 0;										// | 	// Otherwise double check to be sure string ends in substring, and return the result
}																						// | End of ends_with function

int printFileNames(const char *dirname, char *suffix)
{
	if (dirname == NULL) {
		return -1; }
    
    DIR *dir = opendir(dirname);
    if (dir == NULL) {
        return -1; }

    struct dirent *entry;
    int num_files = 0;
    while ((entry = readdir(dir)) != NULL)
    {
        if (ends_with(entry->d_name, suffix)) {
            num_files++; }
    }

    if (closedir(dir) != 0) {									// | Close and immediatel re-open dir. This is required. bc opened as a stream, have to re-open to re-use
        return -1; }											// | 
																// | 
//    *numOfFiles = num_files;									// | 	// Set the number of files to our larger scope number of files
																// | 
	dir = opendir(dirname);										// | This is where we open the new one.
    if (dir == NULL) {											// | 
        return -1; }											// | 

	char *file_names[num_files];
//   char **file_names = (char **)malloc(num_files*128*sizeof(char));
    if (file_names == NULL) {
    	return -2; }
    int i = 0;
    while ((entry = readdir(dir)) != NULL)
    {
        if (ends_with(entry->d_name, suffix))
        {
        	file_names[i] = strdup(entry->d_name);
            if (file_names[i++] == NULL) {
                return 0; }
        }
    }
    
    if(!(i <= num_files)) {
    	return 0; }
    if (i < num_files)
        num_files = i;

	for (i = 0; i < num_files; i++)
	{
		printf("\t%s\n", file_names[i]);
		free(file_names[i]);
	}
	
	closedir(dir);
	return 1;
}
