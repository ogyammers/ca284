/*
Program: lab3-is-sorted.c
Author: Jamie Gorman
Input: array of integers
Output: sorted array of integers
*/

// includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
void longest_word(char *token, char *longest, char str[]);

int main(int argc, char *argv[])
{
    char str[strlen(argv[1])];
    char *token;
    char longest[20];

    strcpy(str, argv[1]);

    longest_word(token, longest, str);

    printf("%s\n", longest);

    return 0;
}

void longest_word(char *token, char *longest, char str[])
{
    token = strtok(str, " ");
    strcpy(longest, token);
    while (token != NULL)
    {
        if (strlen(token) > strlen(longest) == 1)
        {
            strcpy(longest, token);
        }
        token = strtok(NULL, " ");
    }
}
