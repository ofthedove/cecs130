// Percent Grade To Letter Grade Converter
// Author: Andrew Combs
// Date: 09/4/2013
// Section: 2

//***************************************************** Includes *****************************************************
#include <stdio.h>			//	Standard Input Output
#include <stdlib.h>			//	Standard Library
#include <conio.h>			//	
#include <math.h>			//	Included for: floor(), 
#include <ctype.h>			//	Included for: isdigit(), 

//*********************************************** Function Declerations ***********************************************


//**************************************** Main Function / Program Entry Point ****************************************
int main()
{
//	while (error = True)
//	{
		float fPercentGrade = 0.00;
		printf("Please Enter Percent Grade : ");
		scanf("%f", &fPercentGrade);
		
//	}
	
	float fPercentGradeOrg = fPercentGrade;
	char cLetterGrade = 'E';
	
	fPercentGrade = fPercentGrade / 10;
	fPercentGrade = floor(fPercentGrade);
	fPercentGrade = fPercentGrade * 10;
	
	int iPercentGrade = fPercentGrade;
	
	switch (iPercentGrade)
	{
		case 90:
			cLetterGrade = 'A';
			break;
		case 80:
			cLetterGrade = 'B';
			break;
		case 70:
			cLetterGrade = 'C';
			break;
		case 60:
			cLetterGrade = 'D';
			break;
		default:
			cLetterGrade = 'F';
			break;
	}
	
	printf("Percent Grade : %3.2f \n", fPercentGradeOrg);
	printf("Letter Grade : %c", cLetterGrade);
	
    return 0;
}

// isdigit(char/string) returns if is digit #include <ctype.h> //

//***************************************************** Functions *****************************************************
