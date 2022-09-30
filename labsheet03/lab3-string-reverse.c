/*
Program: lab3-string-reverse.c
Author: Jamie Gorman
Input: a string/ array of chars from command line
Output: print out the string reversed
*/

// includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototype declarations
char *reverse(char string[], char arr[]);

/* 
Function: main
Parameters: int argc(argument count), char *argv(argument vector)
Desciption: takes a string and passes it to the reverse function
    and prints the return value
*/
int main(int argc, char *argv[])
{
    // create an array to store argv[1]
    char string[50];

    // copy argv[1] to the array called string
    strcpy(string, argv[1]);

    // create an array to store the reversed string
    char rev[strlen(string)];

    // pass the array string and the array rev to the 
    // function reverse and print the return value
    printf("%s\n", reverse(string, rev));

    return 0;
}

/* 
Function: reverse
Parameters: char string[](source string), char rev[](destination string)
Desciption: takes the source string and stores the reversed value in 
    destination string and returns it to the main function
*/
char *reverse(char string[], char rev[])
{
    // loop through source string
    for (int i = 0; i < strlen(string); ++i)
    {
        // working from the end of the source string
        // and from the start of the destination string
        // building the new string in the array rev
        rev[i] = string[strlen(string) - i - 1];
    }
    
    // add the terminating character to the end of the destination string
    rev[strlen(string)] = '\0';

    // return the destination string
    return rev;
}