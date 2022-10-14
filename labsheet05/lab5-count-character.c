/*
Program: lab5-count-characters.c
Author: Jamie Gorman
Input: a char and a string from command line
Output: the number of occurances of the char in the string
*/

/*Includes*/
#include <stdio.h>
#include <string.h>

/*Function prototypes*/
int char_count(char *str, char *c);

/*Main driver function*/
int main(int argc, char *argv[])
{
    char *c = argv[1];
    char *str = argv[2];

    printf("%d\n", char_count(str, c));

    return 0;
}

/*char_count returns the occurances of a char in a string*/
int char_count(char *str, char *c)
{
    int count = 0;

    while (str = strchr(str, *c))
    {
        count++;
        str++;
    }

    return count;
}
