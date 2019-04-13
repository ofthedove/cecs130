// Lab 2: Currency Converter
// Author: Andrew Combs
// Date: 09/05/2013
// Section: 2

/* A Word On Variable Naming:
	Variables are named with up to three prefixes: Special Informatin, Data Type, and Array Size. For example, the variable name
	"Gf5x5ConversionRates" consists of three prefixes and a name. The first prefix, "G" indicates that this variable is global in scope.
	"C" would indicate a constant value. The second prefix, "f" means the variable is a float. Other options are "c" for char, "i" for 
	integer, etc. The third prefix, "5x5" indicates that this variable is a five by five array. So "Gf5x5ConversionRates" means a global 
	five by five array of floats named ConversionRates. Likewise, "fCurAmount" means a single, local float named CurAmount. */

//***************************************************** Includes *****************************************************
#include <stdio.h>			// Standard Input Output
#include <stdlib.h>			// Standard Library
#include <conio.h>			// Included for: getch()


//*********************************************** Function Prototypes ************************************************
void printTable();					// Prints currency conversion table
									//		PARAMATERS: None (accesses global variable)
									//		RETURNS: Void
									
void cls(int);						// Clears screen by printing a specified number of blank lines. Can also be used to simply create space
									//		PARAMATERS: int Number of Blank  Lines to Print
									//		Returns: Void

float getCurAmount();				// Gets amount of currancy from user
									//		PARAMATERS: None
									//		RETURNS: float Amount of currancy

void CalcConvRates();				// Calculates a 5x5 array of all conversion rates from USD conversion rates, saves to global variable
									//		PARAMATERS: None (accesses global constant "Cf5conversionRates")
									//		RETURNS: Void (accesses global variable "Gf5x5ConversionRates")

void CalcCurValues(float);			// Calculates a 5x5 array of all currency values using conversion rate array and currency amount, saves to global variable
									//		PARAMATERS: float Currency Amount as defined by user (accesses global variable "Gf5x5ConversionRates")
									//		RETURNS: Void (accesses global variable "Gf5x5CurrencyValues")


//************************************************ Constant Definitions ***********************************************
const float Cf5conversionRates[6] = { 1.0, 1.8264, 0.949938, 1.46849, 0.861801, 0.007455 }; // Conversion Rates		Order: USD GBP CAD EUR AUD		USD is 1.0

//************************************************* Global Definitions ************************************************
float Gf5x5ConversionRates[6][6] = { { 0.0 } };		// Initialize empty 5x5 array of float values for conversion rates
float Gf5x5CurrencyValues[6][6] = { { 0.0 } };		// Initialize empty 5x5 array of float values for currency values



//*****#####*****#####*****#####*****##### Main Function / Program Entry Point #####*****#####*****#####*****#####*****
int main()
{
	CalcConvRates();													// Calculate conversion rates once at beggining because constant through program execution
	
	int isRunning = 1;
	
	while(isRunning)													// Loop so user can evaluate multiple inputs
	{
		float fCurAmount = getCurAmount();								// Get amount of currency from user
		CalcCurValues(fCurAmount);										// Calculate currency values
		
		cls(50);														// Clear screan with 50 lines
		
	    printTable();													// Print conversion table
	    
	    cls(10);														// Move table to top of screen
		
		printf("Would you like to convert another value? (y/n)");		// Ask user if they would like to run again
		char YorN = getch();											// Get yes or no character
		if(YorN == 'N' || YorN == 'n') {								// If no stop program
			isRunning = 0;												// By setting is running to 0 ( False )
		}
		cls(50);														// Clear the screen
	}
	
	return 0;															// When loop breaks, return no error
}



//***************************************************** Functions *****************************************************
//------------------------- printTable ---------------------
void printTable()
{
	printf("       |    USD    |    GBP    |    CAD    |    EUR    |    AUD    |    BTC    \n");		// Fairly self explanitory, print table of float values
	printf("===============================================================================\n");		// Values are formatted to be to 2 decimal places padded to total of 9 characters wide
	printf("  USD  | %9.4f | %9.4f | %9.4f | %9.4f | %9.4f | %9.4f \n", Gf5x5CurrencyValues[0][0], Gf5x5CurrencyValues[0][1], Gf5x5CurrencyValues[0][2], Gf5x5CurrencyValues[0][3], Gf5x5CurrencyValues[0][4], Gf5x5CurrencyValues[0][5]);
	printf("-------------------------------------------------------------------------------\n");
	printf("  GBP  | %9.4f | %9.4f | %9.4f | %9.4f | %9.4f | %9.4f \n", Gf5x5CurrencyValues[1][0], Gf5x5CurrencyValues[1][1], Gf5x5CurrencyValues[1][2], Gf5x5CurrencyValues[1][3], Gf5x5CurrencyValues[1][4], Gf5x5CurrencyValues[1][5]);
	printf("-------------------------------------------------------------------------------\n");
	printf("  CAD  | %9.4f | %9.4f | %9.4f | %9.4f | %9.4f | %9.4f \n", Gf5x5CurrencyValues[2][0], Gf5x5CurrencyValues[2][1], Gf5x5CurrencyValues[2][2], Gf5x5CurrencyValues[2][3], Gf5x5CurrencyValues[2][4], Gf5x5CurrencyValues[2][5]);
	printf("-------------------------------------------------------------------------------\n");
	printf("  EUR  | %9.4f | %9.4f | %9.4f | %9.4f | %9.4f | %9.4f \n", Gf5x5CurrencyValues[3][0], Gf5x5CurrencyValues[3][1], Gf5x5CurrencyValues[3][2], Gf5x5CurrencyValues[3][3], Gf5x5CurrencyValues[3][4], Gf5x5CurrencyValues[3][5]);
	printf("-------------------------------------------------------------------------------\n");
	printf("  AUD  | %9.4f | %9.4f | %9.4f | %9.4f | %9.4f | %9.4f \n", Gf5x5CurrencyValues[4][0], Gf5x5CurrencyValues[4][1], Gf5x5CurrencyValues[4][2], Gf5x5CurrencyValues[4][3], Gf5x5CurrencyValues[4][4], Gf5x5CurrencyValues[4][5]);
	printf("-------------------------------------------------------------------------------\n");
	printf("  BTC  | %9.4f | %9.4f | %9.4f | %9.4f | %9.4f | %9.4f \n", Gf5x5CurrencyValues[5][0], Gf5x5CurrencyValues[5][1], Gf5x5CurrencyValues[5][2], Gf5x5CurrencyValues[5][3], Gf5x5CurrencyValues[5][4], Gf5x5CurrencyValues[5][5]);
	
	return;		// Return
}

//----------------------------- cls ------------------------
void cls(int iNumLines)
{
	int i = 0;						// Initialize iteration variable
	for(i = 0; i < iNumLines; i++)	// Run loop specified number of times
	{
		printf("\n");				// Print a new line each iteration
	}
	
	return;							// Return
}

//---------------------- getCurAmount ------------------------
float getCurAmount()
{
	float fCurAmount = 0.0;											// Amount of currancy to be converted
	
	printf("What amount of currency would you like to convert?");	// Print question to user
	cls(23);														// Move question to top of screen
	printf("Amount: ");												// Prompt user
	scanf("%f", &fCurAmount);										// Retrieve user input
	
	return fCurAmount;												// Return amount of currancy obtained from user
}

//---------------------- CalcConvRates ----------------------
void CalcConvRates()
{ 
	int i = 0;															// Initialize iteration variables
	int j = 0;
	
	for(i = 0; i < 6; i++)												// Iterate through table rows
	{
		if(i == 0)														// If first row,
		{
			for(j = 0; j < 6; j++)										// Iterate through columns
			{
				Gf5x5ConversionRates[0][j] = Cf5conversionRates[j];		// Inserting USD conversion rates from constant array
			}
		} else {														// Else , i.e. last five rows,
			for(j = 0; j < 6; j++)										// Iterate through columns
			{
				Gf5x5ConversionRates[i][j] = 							// Calculating and inserting conversion rates
					(1 / Gf5x5ConversionRates[0][i]) * Gf5x5ConversionRates[0][j];
			}		// This gets a little complicated, to simplify the math I'm converting everything to USD and then using the USD 
		}			// conversion rates to go to the intended currancy. This is a wee complicated, but better than doing all the math 
	}				// by hand and hard coding it in. (In my opinion.)
	
	return;																// Return
}

//---------------------- CalcCurValues ----------------------
void CalcCurValues(float fCurAmount)
{
	int i = 0;																		// Initialize iteration variables
	int j = 0;
	
	for(i=0; i < 6; i++)															// Iterate through rows
	{
		for(j=0; j < 6; j++)														// Iterate through columns
		{
			Gf5x5CurrencyValues[i][j] = Gf5x5ConversionRates[i][j] * fCurAmount;	// Multiply currency amount by conversion rate 
		}																			// and store in currency value table
	}
	return;																			// Return
}
