// Contact Book
// Author: Andrew Combs
// Date: 10/17/2013
// Section: 2

//***************************************************** Includes *****************************************************
#include <stdio.h>							// Include standard input output header
#include <stdlib.h>							// Include standard library header
#include <conio.h>							// Include co io header
#include <math.h>							// Include math header

#define splashDelay 1500					// Define delays; easier to change for debugging and harder to miss when switching back

const char *CsVersionNum = "0.1.0";			// Program version number
const char *CsVersionDate =  "10/17/13";		// Program compile date

//*********************************************** Structure Definitions ***********************************************
typedef struct CONTACT {
	char sFirstName[20];			// First name of contact
	char sLastName[20];				// Last name of contact
	char sPhoneNumber[20];			// Phone number of contact
} contact;

struct contactArray {
	contact *contacts;				// Pointer to first element of array of contacts
	int numOfContacts;				// Number of contacts in array
	int contactsPointer;			// Our current index location in the array
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
void contactAdd(struct contactArray *);						// UI and functionality to add contact to contact book
																	// REQUIRES: 
																	// PARAMATERS: A pointer to the contactArray structure to be added to
																	// RETURNS: void
void contactDelete(contact *, struct contactArray *);			// UI and functionality to delete contact from contact book
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
																	// RETURNS: 
int rmContactAlpha(contact *, struct contactArray *);			// Remove a contact from a contactArray resizing array
																	// REQUIRES: 
																	// PARAMATERS: A pointer to a contact containing first and last name of contact to be deleted;
																	//				A pointer to the contactArray structure to be deleted from
																	// RETURNS: 

//**************************************** Main Function / Program Entry Point ****************************************
int main()
{
	struct contactArray contactBook;						// Create a new contactArray as ContactBook
	contactBook.contacts = NULL;							// Set the pointer equal to NULL )as opposed to junk value(
	contactBook.numOfContacts = 0;							// Set numOfContacts equal to zero )as opposed to junk value(
	
	char menuSelect = '_';									// Create a variable to hold user selection on main menu
	
	printSplash();											// Print the splash screen
	delay(splashDelay);											// Hold splash screen
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
				contact delContact;
				contactDelete(&delContact, &contactBook);
				break; }
			case 'l': case 'L': case '3':					// Case to view a list of contacts
				contactList(&contactBook);
				break;
			/*case 'v': case 'V': case '4':{				// Not yet Implemented
				contactView(&contactBook);
				break;*/
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
				delay(splashDelay/2);							// Hold error message on screen
				break;											// Exit the switch and loop back
		} // End of main menu switch
	} // End of main program loop							// When the user selects to exit the program
	system("cls");												// Clear the screen
	printSplash();												// Print the splash screen
	delay(splashDelay);											// Hold splash screen
	if(contactBook.contacts != NULL) {							// If our array of contacts has had memory allocated to it
		free(contactBook.contacts); }								// Free the memory
	system("cls");												// Clear the screen
	return 0;													// Exit program
}

//***************************************************** Functions *****************************************************
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

void clearToHeader()
{																							// Clear screen and print header line
	system("cls");																				// Use terminal command cls to clear screen
	printf("############################## Contact Book #############################\n");		// Print header line
	return;																						// End function and return
}

void printMenu()
{														// Print main menu
	printf("\n\t\t\t");										// Move cursor to position
	printf("A     (1) Add Contact \n\t\t\t");				// Add: a or 1
	printf("D     (2) Delete Contact \n\t\t\t");			// Delete: d or 2
	printf("L     (3) List Contacts \n\t\t\t");				// List: l or 3
//	printf("V     (4) View Contact Book \n\t\t\t");			// View: v or 4
	printf("    ---------------------------- \n\n\t\t\t");	// Print formatting line
	printf("I     Info \n\t\t\t");							// About: I or i
	printf("X     Exit \n\n\n\n\t\t\t\t\t\t\t\t\t");		// Exit: X or x
	return;													// End function and return
}

void printAbout()
{														// Detail information about program
	 printf("\n\n\n\t\t\t");								// Move cursor to position
	 printf("Contact Book\n\n\t\t\t");						// Program name
	 printf("Author:  Andrew Combs\n\t\t\t");				// Author name
	 printf("Version: %s \n\t\t\t", CsVersionNum);			// Version number, from constant
	 printf("Date:    %s \n\n\t\t\t", CsVersionDate);		// Version Date, from constant
	 printf("CECS 130-02     Lab 6 \n\n\n\t\t");			// Class, section and lab program was written for
	 printf("    Press any key to continue...");			// Prompt user
	 getch();												// Wait for key press
	 return;												// End function and return
}

void contactAdd(struct contactArray *contactBook)
{
	contact addContact;
	printf("\nContact First Name : ");
	scanf("%s", addContact.sFirstName);
	printf("\nContact Last Name : ");
	scanf("%s", addContact.sLastName);
	printf("\nContact Phone Number : ");
	scanf("%s", addContact.sPhoneNumber);
	
	isrtContactAlpha(&addContact, contactBook);
}

void contactDelete(contact *delContact, struct contactArray *contactBook)
{
	printf("\nContact First Name : ");
	scanf("%s", delContact->sFirstName);
	printf("\nContact Last Name : ");
	scanf("%s", delContact->sLastName);
	
	rmContactAlpha(delContact, contactBook);
}

void contactList(struct contactArray *contactBook)
{
	contactBook->contactsPointer = 0;
	clearToHeader();
	printf("Name\t Phone Number\n");
	for(; (contactBook->contactsPointer) < (contactBook->numOfContacts); (contactBook->contactsPointer)++)
	{
		contact listContact = contactBook->contacts[contactBook->contactsPointer];
		char *firstName = listContact.sFirstName;
		char *lastName = listContact.sLastName;
		char *phoneNumber = listContact.sPhoneNumber;
		if(lastName[0] != '\0') {
			printf("\n%s %s \t %s", firstName, lastName, phoneNumber); }
	}
	printf("\n\nPress any key to continue...");
	getch();
}

/* Not Yet Implemented
void contactView(struct contactArray *contactBook)
{
	
}*/

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

int isrtContactAlpha(contact *isrtContact, struct contactArray *contactBook)
{
	if(contactBook->contacts == NULL)									// If the array is empty we have to use malloc to allocate memory to it for the first time
	{
		contactBook->contacts = (contact*)malloc(((contactBook->numOfContacts)+1) * sizeof(contact));	// Allocate the memory
		if (contactBook->contacts == NULL) { return -1; }					// If memory can't be aquired return -1 )fail(
	} else {															// If the array has something in it we want to use realloc so we don't lose the existing information
		contact *newContacts = realloc((contactBook->contacts), (((contactBook->numOfContacts)+1) * sizeof(contact)));	// Reallocate the memory
		if (!newContacts) { return -1; }									// If memory couldn't be aquired to expand list return -1 )fail(
		(contactBook->contacts) = newContacts;								// Set our old ponter to the same thing as our new pointer
	}																// End If
	(contactBook->numOfContacts)++;										// Incrememnt numOfContacts because there is one more contact in the contact book now

	contactBook->contactsPointer = contactBook->numOfContacts - 1;		// Choose the last index in the array of contacts, the empty space we just allocated
	contactBook->contacts[contactBook->contactsPointer] = *isrtContact;	// and write the contact we want to insert into the empty contact space at that location
}

int rmContactAlpha(contact *delContact, struct contactArray *contactBook)
{
	for((contactBook->contactsPointer) = 0; (contactBook->contactsPointer) < (contactBook->numOfContacts); (contactBook->contactsPointer)++)
	{
		contact tempContact = contactBook->contacts[contactBook->contactsPointer];
		if(strcmp(delContact->sLastName, tempContact.sLastName) == 0 && strcmp(delContact->sLastName, tempContact.sLastName) == 0)
		{
			contactBook->contacts[contactBook->contactsPointer].sLastName[0] = '\0';
			return 1;
		}
	}
	return 0;
}
