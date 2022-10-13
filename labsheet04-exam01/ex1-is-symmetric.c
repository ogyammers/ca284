/*
Program: ex1-is-symmetric.c
Author: Jamie Gorman
Date: 06/10/22
Input: a single string from command line
Output: yes or no, if the string is symmetrical(palindrome)
*/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function prototype*/
int is_symmetric(int length, char str[]);

/*
Function: main
Parameters: argc, argv
Desciption: collects a string from command line, copys it to str
    drives the function is_symmetric
*/
int main(int argc, char *argv[])
{
    /* take the lenght as the length of the string at command line index 1*/
    int length = strlen(argv[1]);
    /* creats an array to store our string*/
    char str[length];

    /* copy string from argv to our new array str*/
    strcpy(str, argv[1]);

    /* call is_symmetric and pass it the string and the length of the
    string*/
    is_symmetric(length, str);

    return 0;
}

/*
Function: is_symmetriv
Parameters: string and string length
Desciption: prints yes or no depending on whether the string is
    symmetrical or not
*/
int is_symmetric(int length, char str[])
{
    /* loop while the i'th char in string is equal to the i'th char
    from the end of the string*/
    for (int i = 0; str[i] == str[length - i - 1]; ++i)
    {
        /* if we have passed the half way point of the string
        we know it is symmetrical and we can print yes and return to main*/
        if (i > length / 2 + 1)
        {
            printf("yes\n");
            return 0;
        }
    }
    /* if we make it this far we know the loop has ended and the conditions
    for symmetry were not met print no*/
    printf("no\n");
}