#include <stdio.h>
#include <stdlib.h>

int main()
{
	char character = 'A';
	
	printf("character is : %c \nASCII is : %i\n", character, character);
	
	if (character == 65)
	{
		printf("character was equal to 65!\n");
	} else {
		printf("character was not equal to 65...\n");
	}
	
	system("PAUSE");
}
