//************************************************* Function Prototype ************************************************
int isrtContactAlpha(contact *, struct contactArray *);			// Insert a contact into a contactArray sorted A-Z )ignore case(
																	// PARAMATERS: A pointer to the contact to be added; A pointer to the contactArray structure to be added to
																	// RETURNS: An int for error checking. -1 indicates failure.

//************************************************ Structure Definition ***********************************************
typedef struct CONTACT {		// Structure for individual contact
	char sFirstName[20];			// First name of contact
	char sLastName[20];				// Last name of contact
	char sPhoneNumber[20];			// Phone number of contact
} contact;

struct contactArray {			// Structre for array of contact
	contact *contacts;				// Pointer to first element of array of contacts
	int numOfContacts;				// Number of contacts in array
	int contactsIndex;			// Our current index location in the array
};

//********************************************** Structure Initialization *********************************************
// Values must be initiaized before call or will contain trash values
struct contactArray contactBook;						// Create a new contactArray as ContactBook
	contactBook.contacts = NULL;							// Set the pointer equal to NULL )as opposed to junk value(
	contactBook.numOfContacts = 0;							// Set numOfContacts equal to zero )as opposed to junk value(

//***************************************************** Functions *****************************************************
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
//###	contactBook->contactsIndex--; 
	
// Insert our new contact moving everything to the right of it over one
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
