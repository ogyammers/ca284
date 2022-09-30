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

//function prototypes
void leap_years(int start, int end);


int main(int argc, char *argv[])
{
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);

    leap_years(start, end);
    //printf("%d - %d\n", start, end);
    return 0;
}

void leap_years(int start, int end)
{
    int year = ((start + 3) / 4) * 4;
    while (year <= end)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                printf("%d\n", year);
            }
        }
        else
        {
            printf("%d\n", year);
        }
        year += 4;
        
    }
    

}