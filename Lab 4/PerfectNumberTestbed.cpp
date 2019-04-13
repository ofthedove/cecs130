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
	int iOperand1 = 0, i = 0;
//	int AiDivisors[];
	int iArrayCounter = 0;
	float largestRatio = 0;
	float fDivisorRatio = 0;
	
	printf("Number \t\t # Divisors \t Ratio \t\t\t Largest Ratio\n\n");
while(1) {
	
//	printf("\n\t\t\t");
//	printf("Perfect Number Finder \n\t\t\t\t");
//	printf("How many?: ");
//	scanf("%d", &iHowMany);
//	printf("\n\t\t\t\tVerbose? (y/n/v): ");
//	scanf("%c", &cIsVerbose);

//	printf("\n\t\t\t");
//	printf("Perfect Number Finder \n\t\t\t\t");
//	printf("Number: ");
	
	iArrayCounter = 0;
	fDivisorRatio = 0;
	++iOperand1;
	
	for(i = 2; i < ((iOperand1+3)/2); i++)
	{
//		printf("%d \t\t", i);
		if((iOperand1 % i) == 0)
		{
//			printf("Yes\n");
//			AiDivisors[iArrayCounter] = i;
			iArrayCounter++;
		} else {
//			printf("No\n");
		}
	}
	
//	for(i = 0; i < iArrayCounter; i++)
//	{
//		printf("%d \n", AiDivisors[i]);
//	}
	
	fDivisorRatio = (float)iArrayCounter / (float)iOperand1;
	if(fDivisorRatio > largestRatio) { largestRatio = fDivisorRatio; }
	
	printf("%d \t\t %d \t\t %f \t\t %f\n", iOperand1, iArrayCounter, fDivisorRatio, largestRatio);
	
	if(iOperand1 > 50) { break; }
}
	printf("\n\n\n\t\t\tPress any key to continue...");
	getch();
}

//***************************************************** Functions *****************************************************

