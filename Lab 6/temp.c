// Contact Book
// Author: Andrew Combs
// Date: 10/17/2013
// Section: 2

//***************************************************** Includes *****************************************************
#include <stdio.h>							// Include standard input output header
#include <stdlib.h>							// Include standard library header
#include <conio.h>							// Include co io header
#include <math.h>							// Include math header

//*********************************************** Structure Definitions ***********************************************
typedef struct CONTACT {
	char sFirstName[20];
	char sLastName[20];
	char sPhoneNumber[20];
} contact;

struct contactArray {
	contact *contacts;
	int numOfContacts;
	int contactsPointer;
};

//************************************************* Function Prototype ************************************************
void contactAdd(contact *, struct contactArray *);				// UI and functionality to add contact to contact book
																	// REQUIRES: 
																	// PARAMATERS: 
																	// RETURNS: 

int isrtContactAlpha(contact *, struct contactArray *);			// Insert a contact into a contactArray sorted A-Z )ignore case( 
																	// REQUIRES: 
																	// PARAMATERS: 
																	// RETURNS: 

//**************************************** Main Function / Program Entry Point ****************************************
int main()
{
	struct contactArray contactBook;
	

				contact newContact;
				contactAdd(&newContact, &contactBook);
	
	return 0;													// Exit program
}

//***************************************************** Functions *****************************************************
void contactAdd(contact *addContact, struct contactArray *contactBook)
{
	printf("\nContact First Name : ");
	scanf("%s", addContact->sFirstName);
	gets(addContact->sFirstName);
	printf("\nContact Last Name : ");
	scanf("%s", addContact->sLastName);
//	gets(addContact->sLastName);
	printf("\nContact Phone Number : ");
	scanf("%s", addContact->sPhoneNumber);
//	gets(addContact->sPhoneNumber);
	
//	addContact->sFirstName = gets();
	
	
	printf("\nContact First Name : %s", addContact->sFirstName);
	
	printf("\nContact Last Name : %s", addContact->sLastName);
	
	printf("\nContact Phone Number : %s", addContact->sPhoneNumber);
	printf("\n\n");
	system("PAUSE");
}

int isrtContactAlpha(contact *isrtContact, struct contactArray *contactBook) // will need string.h
{
// Allocate more space to our contact array so we can add a contact
	contact *newContacts = realloc(contactBook->contacts, ((contactBook->numOfContacts)+1) * sizeof(contact));
	if (!newContacts) { return -1; }	// If memory couldn't be aquired to expand list return -1 )fail(
	(contactBook->contacts) = newContacts;	// Set our old ponter to the same location as our new pointer
	(contactBook->numOfContacts)++;	// Increase the number of contacts by one
// Find what location in our array we want to put our new contact in
	for((contactBook->contactsPointer) = 0; (contactBook->contactsPointer) < (contactBook->numOfContacts); (contactBook->contactsPointer)++)
	{
		contact curContact = contactBook->contacts[contactBook->contactsPointer];
		if (strcmp((isrtContact->sLastName), curContact.sLastName) < 0) {
			break; }
	}
// Insert our new contact moving everything to the right of it over one
	
	for(; (contactBook->contactsPointer) < (contactBook->numOfContacts); (contactBook->contactsPointer)++)
	{
		contact tempContact = contactBook->contacts[contactBook->contactsPointer];
		//contactBook->contacts[contactBook->contactsPointer] = isrtContact;
		*(&(contactBook->contacts) + (contactBook->contactsPointer)) = isrtContact;
		isrtContact = &tempContact;
		(contactBook->contactsPointer)++;
		//contact tempContact = contactBook->contacts[contactBook->contactsPointer];
		//contactBook->contacts[contactBook->contactsPointer] = curContact;
	}
}
