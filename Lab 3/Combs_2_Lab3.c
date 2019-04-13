// Lab 3: Simple Calculator
// Author: Andrew Combs
// Date: 09/12/2013
// Section: 2

//***************************************************** Includes *****************************************************
#include <stdio.h>							// Include standard input output header
#include <stdlib.h>							// Include standard library header
#include <conio.h>							// Include conio header
#include <math.h>							// Include math header


const char *CsVersionNum = "1.0.0";			// Program version number
const char *CsVersionDate = "9/17/13";		// Program compile date

//************************************************* Function Prototype ************************************************
void printSplash();									// Print ASCII art splash screen, used on load and exit of program
														// REQUIRES: stdio.h
														// PARAMATERS: none
														// RETURNS: none
void clearToHeader();								// Clears the screen with system("cls") and prints a one line program header
														// REQUIRES: stdio.h, stdlib.h
														// PARAMATERS: none
														// RETURNS: none
void printMenu();									// Prints the calculator's main menu
														// REQUIRES: stdio.h
														// PARAMATERS: none
														// RETURNS: none
void printAbout();									// Print a screen displaying information about the program such as author name and compile date
														// REQUIRES: stdio.h
														// PARAMATERS: none, but accesses global constants CsVersionNum and CsVersionDate
														// RETURNS: none
int calculatorAdd();								// Adds two numbers. Has internal UI.
														// REQUIRES: stdio.h, conio.h
														// PARAMATERS: none
														// RETURNS: int for error handling, not yet implemented
int calculatorSub();								// Subtract two numbers. Has internal UI.
														// REQUIRES: stdio.h, conio.h
														// PARAMATERS: none
														// RETURNS: int for error handling, not yet implemented
int calculatorMul();								// Multiply two numbers. Has internal UI.
														// REQUIRES: stdio.h, conio.h
														// PARAMATERS: none
														// RETURNS: int for error handling, not yet implemented
int calculatorDiv();								// Divide two numbers. Has internal UI.
														// REQUIRES: stdio.h, conio.h
														// PARAMATERS: none
														// RETURNS: int for error handling, not yet implemented
int calculatorMod();								// Calculate Modulus of two numbers. Has internal UI.
														// REQUIRES: stdio.h, conio.h
														// PARAMATERS: none
														// RETURNS: int for error handling, not yet implemented
int calculatorPrimeTest();							// Tests to see if a number is prime. Has internal UI. Uses simple implementation, efficiancy could be signifigantly improved
														// REQUIRES: stdio.h, conio.h
														// PARAMATERS: none
														// RETURNS: int for error handling, not yet implemented
int calculatorFac();								// Calculates factorial of a number. Has internal UI. Cannont handle input greater than 65.
														// REQUIRES: stdio.h, conio.h
														// PARAMATERS: none
														// RETURNS: int for error handling, not yet implemented
void delay(int);									// Delays the program for a specified abount of time. EXTREAMLY POOR IMPLEMENTATION! Needs signifigant improvement to be reliable
														// RETURNS: none
														// RETURNS: int amount of time to delay, very unreliable

//**************************************** Main Function / Program Entry Point ***************************************
int main()
{
	char menuSelect = '_';									// Create a variable to hold user selection on main menu
	
	printSplash();											// Print the splash screen
	delay(500);												// Hold splash screen
	
	while(1)											// Begin main program loop
	{
		clearToHeader();									// Clear splash screen and print header
		printMenu();										// Print menu to screen
		
		menuSelect = getch();								// Get user menu selection
		
		if(menuSelect == 'x' || menuSelect == 'X')			// If user requested exit, break main loop
			break;

		clearToHeader();									// Clear menu from screen but replace header
		
		switch (menuSelect)								// Use switch to process additional user input values
		{
			case '+': case 'a': case '1':					// If user selected addition
				calculatorAdd();								// Call the addition function
				break;											// Then exit the switch and loop back
			case '-': case 's': case '2':					// If user selected subtraction
				calculatorSub();								// Call the subtraction function
				break;											// Then exit the switch and loop back
			case '*': case 'm': case '3':					// If user selected multiplication
				calculatorMul();								// Call the multiplication function
				break;											// Then exit the switch and loop back
			case '/': case 'd': case '4':					// If user selected division
				calculatorDiv();								// Call the division function
				break;											// Then exit the switch and loop back
			case '%': case 'u': case '5':					// If user selected modulus
				calculatorMod();								// Call the modulus function
				break;											// Then exit the switch and loop back
			case 'p': case '6':								// If user selected modulus
				calculatorPrimeTest();							// Call the modulus function
				break;											// Then exit the switch and loop back
			case '!': case 'f': case '7':					// If user selected factorial
				calculatorFac();								// Call the factorial function
				break;											// Then exit the switch and loop back
			case 'i': case 'I':								// If user selected to view program information
				printAbout();									// Print about page
				break;											// Then exit the switch and loop back
			default:										// If user input anything else
				printf("\n\t\t\t");								// Print error message
				printf("ERROR: Syntax \n\t\t\t");
				printf("The character you entered is not \n\t\t\t");
				printf("recognized as a valid operator \n\n\t\t\t");
				printf("Please try again.");
				printf("\n\n\n\n\t\t\t\t\t\t\t\t\t");
				delay(750);										// Hold error message on screen
				break;											// Exit the switch and loop back
		} // End of main menu switch
	} // End of main program loop							// When the user selects to exit the program
	system("cls");												// Clear the screen
	printSplash();												// Print the splash screen
	delay(500);													// Hold splash screen
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
	printf("#####   __                __                     _______  __    __  #####\n");
	printf("#####  /     /\\   |      /   |    | |       /\\      |    /  \\  |  \\ #####\n");
	printf("##### |     /__\\  |     |    |    | |      /__\\     |   |    | |__/ #####\n");
	printf("#####  \\__ /    \\ |____  \\__  \\__/| |____ /    \\    |    \\__/  |  \\ #####\n");
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
	printf("############################### Calculator ##############################\n");		// Print header line
	return;																						// End function and return
}

void printMenu()
{														// Print main menu
	printf("\n\t\t\t");										// Move cursor to position
	printf("+     (1) Addition \n\t\t\t");						// Addition: +, a or 1
	printf("-     (2) Subtraction \n\t\t\t");					// Subtraction: -, s or 2
	printf("*     (3) Multiplication \n\t\t\t");				// Multiplication: *, m or 3
	printf("/     (4) Division \n\t\t\t");						// Division: /, d or 4
	printf("%%     (5) Modulus \n\t\t\t");						// Modulus: %, u or 5
	printf("p     (6) Primality Test \n\t\t\t");				// Primality Test: p or 6
	printf("!     (7) Factorial \n\n\t\t");						// Factorial: !, f or 7
	printf("    ---------------------------- \n\n\t\t\t");	// Print formatting line
	printf("I     Info \n\t\t\t");							// About: I or i
	printf("X     Exit \n\n\n\n\t\t\t\t\t\t\t\t\t");		// Exit: X or x
	return;													// End function and return
}

void printAbout()
{														// Detail information about program
	 printf("\n\n\n\t\t\t");								// Move cursor to position
	 printf("Calculator\n\n\t\t\t");						// Program name
	 printf("Author:  Andrew Combs\n\t\t\t");				// Author name
	 printf("Version: %s \n\t\t\t", CsVersionNum);			// Version number, from constant
	 printf("Date:    %s \n\n\t\t\t", CsVersionDate);		// Version Date, from constant
	 printf("CECS 130-02     Lab 3 \n\n\n\t\t");			// Class, section and lab program was written for
	 printf("    Press any key to continue...");			// Prompt user
	 getch();												// Wait for key press
	 return;												// End function and return
}

int calculatorAdd()
{																				// Implement Addition Functionality
	float fOperand1 = 0, fOperand2 = 0, fSolution = 0;								// Create variables to hold operands and solution
	printf("\n\t\t\t");																// Move cursor to position
	printf("Addition \n\t\t\t\t");													// Print operation type to top of page
	printf("Operand 1: ");															// Prompt user for first operand
	scanf("%f", &fOperand1);														// Store user input
	printf("\n\t\t\t\tOperand 2: ");												// Prompt user for second operand
	scanf("%f", &fOperand2);														// Store user input
	fSolution = fOperand1 + fOperand2;												// Perform operation
	printf("\n\n\t\t\t    %.3f + %.3f = %.3f ", fOperand1, fOperand2, fSolution);	// Print result
	printf("\n\n\n\t\t\tPress any key to continue...");								// Prompt user
	getch();																		// Wait for key press
	return;																			// End function and return
}

int calculatorSub()
{																				// Implement Subtraction Functionality
	float fOperand1 = 0, fOperand2 = 0, fSolution = 0;								// Create variables to hold operands and solution
	printf("\n\t\t\t");																// Move cursor to position
	printf("Subtraction \n\t\t\t\t");												// Print operation type to top of page
	printf("Operand 1: ");															// Prompt user for first operand
	scanf("%f", &fOperand1);														// Store user input
	printf("\n\t\t\t\tOperand 2: ");												// Prompt user for second operand
	scanf("%f", &fOperand2);														// Store user input
	fSolution = fOperand1 - fOperand2;												// Perform operation
	printf("\n\n\t\t\t    %.3f - %.3f = %.3f ", fOperand1, fOperand2, fSolution);	// Print result
	printf("\n\n\n\t\t\tPress any key to continue...");								// Prompt user
	getch();																		// Wait for key press
	return;																			// End function and return
}

int calculatorMul()
{																				// Implement Multiplication Functionality
	float fOperand1 = 0, fOperand2 = 0, fSolution = 0;								// Create variables to hold operands and solution
	printf("\n\t\t\t");																// Move cursor to position
	printf("Multiplication \n\t\t\t\t");											// Print operation type to top of page
	printf("Operand 1: ");															// Prompt user for first operand
	scanf("%f", &fOperand1);														// Store user input
	printf("\n\t\t\t\tOperand 2: ");												// Prompt user for second operand
	scanf("%f", &fOperand2);														// Store user input
	fSolution = fOperand1 * fOperand2;												// Perform operation
	printf("\n\n\t\t\t    %.3f * %.3f = %.3f ", fOperand1, fOperand2, fSolution);	// Print result
	printf("\n\n\n\t\t\tPress any key to continue...");								// Prompt user
	getch();																		// Wait for key press
	return;																			// End function and return
}

int calculatorDiv()
{																				// Implement Division Functionality
	float fOperand1 = 0, fOperand2 = 0, fSolution = 0;								// Create variables to hold operands and solution
	printf("\n\t\t\t");																// Move cursor to position
	printf("Division \n\t\t\t\t");													// Print operation type to top of page
	printf("Operand 1: ");															// Prompt user for first operand
	scanf("%f", &fOperand1);														// Store user input
	printf("\n\t\t\t\tOperand 2: ");												// Prompt user for second operand
	scanf("%f", &fOperand2);														// Store user input
	if (fOperand2 == 0) { // Divide by zero error check								// If denominator is equal to zero
		printf("\n\n\t\t\tERROR: Cannot divide by zero!");								// Print error message
	} else {																		// Else; denominator not equal to zero
		fSolution = fOperand1 / fOperand2;												// Perform operation
		printf("\n\n\t\t\t    %.3f / %.3f = %.3f ", fOperand1, fOperand2, fSolution);	// Print result
	} //End divide by zero error check
	printf("\n\n\n\t\t\tPress any key to continue...");								// Prompt user
	getch();																		// Wait for key press
	return;																			// End function and return
}

int calculatorMod()
{																				// Implement Modulus Functionality
	int iOperand1 = 0, iOperand2 = 0, iSolution = 0;								// Create variables to hold operands and solution
	printf("\n\t\t\t");																// Move cursor to position
	printf("Modulus \n\t\t\t\t");													// Print operation type to top of page
	printf("Operand 1: ");															// Prompt user for first operand
	scanf("%d", &iOperand1);														// Store user input
	printf("\n\t\t\t\tOperand 2: ");												// Prompt user for second operand
	scanf("%d", &iOperand2);														// Store user input
	iSolution = iOperand1 % iOperand2;												// Perform operation
	printf("\n\n\t\t\t\t%d %% %d = %d ", iOperand1, iOperand2, iSolution);			// Print result
	printf("\n\n\n\t\t\tPress any key to continue...");								// Prompt user
	getch();																		// Wait for key press
	return;																			// End function and return
}

int calculatorPrimeTest()
{																				// Implement Primality Test Functionality
	int iOperand1 = 0, i = 0, iSolution = 1;										// Create variables to hold operands and solution
	printf("\n\t\t\t");																// Move cursor to position
	printf("Primality Test \n\t\t\t\t");											// Print operation type to top of page
	printf("Operand 1: ");															// Prompt user for first operand
	scanf("%d", &iOperand1);														// Store user input	
	if(iOperand1 < 0) { iOperand1 = 0 - iOperand1; }								// Replace operand with absolute value of operand
	
	for(i = 2; i < ((iOperand1+1)/2); i++)											// Starting with value 2 loop through all values less than operand
	{
		if((iOperand1 % i) == 0)													// If operand can be divided by current counter value
		{																			// operand must not be a prime
			printf("\n\n\t\t\t\t%d is not prime.", iOperand1);							// Report to user that operand is not prime
			int iQuotient = iOperand1 / i;												// Divide operand by lowest divisor
			printf("\n\n\t\t\t\t%d / %d = %d", iOperand1, i, iQuotient);				// Show operation proving operand is not prime
			printf("\n\n\n\t\t\tPress any key to continue...");							// Prompt user
			getch();																	// Wait for key press
			return;																		// Exit function and return to main menu
		} // End operand divisible by counter test
	} // End search for divisor loop												
	printf("\n\n\t\t\t\t   %d is prime", iOperand1);								// Print result
	printf("\n\n\n\t\t\tPress any key to continue...");								// Prompt user
	getch();																		// Wait for key press
	return;																			// End function and return
}

int calculatorFac()
{
	int iOperand1 = 0, i = 0;														// Create variables to hold operand and counter
	unsigned long long int lSolution = 1;											// Create variable for solution as unsigned long long int
	printf("\n\t\t\t");																// Move cursor to position
	printf("Factorial \n\t\t\t\t");													// Print operation type to top of page
	printf("Operand 1: ");															// Prompt user for first operand
	scanf("%d", &iOperand1);														// Store user input	
	if(iOperand1 < 0) { iOperand1 = 0 - iOperand1; }								// Replace operand with absolute value of operand
	for(i = iOperand1; i > 0; i--)													// Loop through all values equal to or less than the operand
	{
		lSolution *= i;																// And multiply them together to get factorial
	}
	printf("\n\n\t\t\t\t   %d! = %llu ", iOperand1, lSolution);						// Print result
	printf("\n\n\n\t\t\tPress any key to continue...");								// Prompt user
	getch();																		// Wait for key press
	return;																			// End function and return
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
