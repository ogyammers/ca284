/*
Program: lab3-find-longest-word.c
Author: Jamie Gorman
Input: string from command line
Output: longest word in the input string
*/

// includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
void longest_word(char *token, char *longest, char str[]);


/*
Function: main
Parameters: argc, argv
Desciption: calls functions to find the longest word and
    prints the result
*/
int main(int argc, char *argv[])
{
    // array to store the string
    char str[strlen(argv[1])];
    
    char *token;
    char longest[20];

    // copy from argv to str
    strcpy(str, argv[1]);

    // call function longest_word and pass it token, longest and str
    longest_word(token, longest, str);
    
    // print the longest word
    printf("%s\n", longest);

    return 0;
}


/*
Function: longest_word
Parameters: token, longest, str
Desciption: splits the string into tokens and 
    compares it to the current longest word 
*/
void longest_word(char *token, char *longest, char str[])
{
    // first token from str on the delimiter of " " a single space
    token = strtok(str, " ");
    // copy first token to longest
    strcpy(longest, token);
    // while token is not NULL ie, we are still taking slices from the string
    while (token != NULL)
    {
        // compare current token to current longest
        if (strlen(token) > strlen(longest) == 1)
        {
            // if longer copy token to longest
            strcpy(longest, token);
        }
        // take the next token
        token = strtok(NULL, " ");
    }
}
