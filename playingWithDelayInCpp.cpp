//
// Author: Andrew Combs
// Date: //2013
// Section: 2

//***************************************************** Includes *****************************************************
#include <iostream>
#include <windows.h>

//************************************************* Function Prototype ************************************************


//**************************************** Main Function / Program Entry Point ****************************************
int main()
{
	using namespace std;
	int countTo = 100;
	countTo++;
	for(int i = 0; i < countTo; i++)
	{
		for(int j = 0; j < i; j++)
		{
			cout << static_cast<char>(32);
		}
		cout << i << "\n";
		Sleep(1000);
	}
}

//***************************************************** Functions *****************************************************

