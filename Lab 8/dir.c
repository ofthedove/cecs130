// Definitions for dir.c
// Code for getting names of files in a directory
// Author: Andrew Combs
// Date: 10/30/13

// Based off code from : http://stackoverflow.com/questions/19338823/copying-file-names-into-an-array-with-c

// Reworked to be header file

// Nevermind, I'm going to have to pretty much re-write the whole thing

#include <assert.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <unistd.h>
#include <stdbool.h>

int array_find(char *key, char *argv[], int argc)
{
	int i;
    for (i = 0; i < argc; i++)
    {
        if (strcmp(key, argv[i]) == 0)
            return i;
    }
    return -1;
}

bool ends_with(char *str, char *sub)													// | Function determines if a string ends with another string
{																						// | 
    if (str == NULL && sub == NULL) {													// | 	// Checks if both strings are NULL
        return true; }																	// | 		// If so, return true
    if (str == NULL || sub == NULL) {													// | 	// Checks if one but not both strings are NULL
        return false; }																	// | 		// If so, return false
    char *last_instance_of_sub = strrchr(str, *sub);									// | 	// Get a pointer to the last occourance of substring in string
    size_t sub_len = strlen(sub);														// | 	// Get the size of the sub string
    if (last_instance_of_sub == NULL || strlen(last_instance_of_sub) != sub_len)		// | 	// If substring isn't in string or it's not the last thing in the string
        return false;																	// | 		// return false
    return strcmp(last_instance_of_sub, sub) == 0;										// | 	// Otherwise double check to be sure string ends in substring, and return the result
}																						// | End of ends_with function

// 1	success
// 0	unkown failure
// -1	bad dir
// -2	memory failure
// -3

/*
pass in dir name, pointer to int for size of array of file names, null pointer for array of file names
find number of file names, set to int pointer for number of file names
alloc memory for array of file names assign to passed in pointer for array of file names
return int for error checking.
*/
/*
int main_fuction(const char *dirname, char *suffix, int *numOfFiles, char **ArrayOfFileNames)
{
	if (dirname == NULL) {
		return -1; }
    
    DIR *dir = opendir(dirname);
    if (dir == NULL) {
        return -1; }

    struct dirent *entry;
    int num_files = 0;
    while ((entry = readdir(dir)) != NULL)
    {
        if (ends_with(entry->d_name, suffix)) {
            num_files++; }
    }

    if (closedir(dir) != 0) {									// | Close and immediatel re-open dir. This is required. bc opened as a stream, have to re-open to re-use
        return -1; }											// | 
																// | 
    *numOfFiles = num_files;									// | 	// Set the number of files to our larger scope number of files
																// | 
	dir = opendir(dirname);										// | This is where we open the new one.
    if (dir == NULL) {											// | 
        return -1; }											// | 

//	char *file_names[num_files];
    char **file_names = (char **)malloc(num_files*128*sizeof(char));
    if (file_names == NULL) {
    	return -2; }
    int i = 0;
    while ((entry = readdir(dir)) != NULL)
    {
        if (ends_with(entry->d_name, suffix))
        {
            *(*file_names + i) = strdup(entry->d_name);
            if (file_names[i++] == NULL) {
                return 0; }
        }
    }
    if(!(i <= num_files)) {
    	return 0; }
    if (i < num_files)
        num_files = i;

/*	for (i = 0; i < num_files; i++)
	{
		printf("%s\n", file_names[i]);
		free(file_names[i]);
	}
* /	
	closedir(dir);
	return 1;
}
*/



//void main() {}




int printFileNames(const char *dirname, char *suffix)
{
	if (dirname == NULL) {
		return -1; }
    
    DIR *dir = opendir(dirname);
    if (dir == NULL) {
        return -1; }

    struct dirent *entry;
    int num_files = 0;
    while ((entry = readdir(dir)) != NULL)
    {
        if (ends_with(entry->d_name, suffix)) {
            num_files++; }
    }

    if (closedir(dir) != 0) {									// | Close and immediatel re-open dir. This is required. bc opened as a stream, have to re-open to re-use
        return -1; }											// | 
																// | 
//    *numOfFiles = num_files;									// | 	// Set the number of files to our larger scope number of files
																// | 
	dir = opendir(dirname);										// | This is where we open the new one.
    if (dir == NULL) {											// | 
        return -1; }											// | 

	char *file_names[num_files];
//   char **file_names = (char **)malloc(num_files*128*sizeof(char));
    if (file_names == NULL) {
    	return -2; }
    int i = 0;
    while ((entry = readdir(dir)) != NULL)
    {
        if (ends_with(entry->d_name, suffix))
        {
        	file_names[i] = strdup(entry->d_name);
			//*(*file_names + i) = strdup(entry->d_name);
            if (file_names[i++] == NULL) {
                return 0; }
        }
    }
    
    if(!(i <= num_files)) {
    	return 0; }
    if (i < num_files)
        num_files = i;

	for (i = 0; i < num_files; i++)
	{
		printf("%s\n", file_names[i]);
		free(file_names[i]);
	}
	
	closedir(dir);
	return 1;
}
