/*
Program: lab3-leap-year.c
Author: Jamie Gorman
Input: starting year and ending year
Output: all the leap years from starting year to ending year
*/

// includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
void leap_years(int start, int end);

/*
Function: main
Parameters: argc, argv
Desciption: calls function to find leap years
*/
int main(int argc, char *argv[])
{
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);

    leap_years(start, end);
    // printf("%d - %d\n", start, end);
    return 0;
}

/*
Function: leap_years
Parameters: start year and end year
Desciption: algorithm to print all leap years
*/
void leap_years(int start, int end)
{
    // finds the first leap year that is <= the start year
    int year = ((start + 3) / 4) * 4;
    // loop until year is <= the end year
    while (year <= end)
    {
        // check the edge cases ie centuries
        // if divisible by 100 a leap year must also be divisible by 400
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                printf("%d\n", year);
            }
        }
        // all other cases
        else
        {
            printf("%d\n", year);
        }
        // increment by 4, ie next leap year
        year += 4;
    }
}