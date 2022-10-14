/*
Program: lab5-search-sub-string.c
Author: Jamie Gorman
Input: a string and substring from command line
Output: the starting and ending index of substring in string
*/

/*Includes*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Function prototypes*/
void search_string(char *pString, char *pSubstring);

/*Main driver function*/
int main(int argc, char *argv[])
{
    char string[50];
    char *pString = string;

    char substring[10];
    char *pSubstring = substring;

    strcpy(pString, argv[1]);
    strcpy(pSubstring, argv[2]);

    search_string(pString, pSubstring);

    return 0;
}

/*Function prints the starting and ending index of a substring
loop through string, if a char matches the first char of substring*/
void search_string(char *pString, char *pSubstring)
{
    for (int i = 0; i < strlen(pString); ++i)
    {
        if (*(pString + i) == *pSubstring)
        {
            for (int j = 0; j < strlen(pSubstring); ++j)
            {
                if (*(pString + i + j) == *(pSubstring + j) &
                    j + 1 == strlen(pSubstring))
                {
                    printf("%d %d\n", i, j + i);
                    exit(0);
                }
            }
        }
    }
}