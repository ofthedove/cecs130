
// Header for dir.c
// Code for getting names of files in a directory
// Author: Andrew Combs
// Date: 10/30/13

// Based off code from : http://stackoverflow.com/questions/19338823/copying-file-names-into-an-array-with-c

#include <assert.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <unistd.h>
#include <stdbool.h>

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

//int main_function(int argc, char *argv[]);



int printFileNames(const char *dirname, char *suffix);
