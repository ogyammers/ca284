/*
Program: lab3-findMax.c
Author: Jamie Gorman
Input: array of integers from command line
Output: return the largest element
*/

// includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototype declarations
int findMax(int argc, char *arr[]);

/* 
Function: main
Parameters: int argc(argument count), char *argv(argument vector)
Desciption: passes the array to the findMax function and prints
    the return value
*/
int main(int argc, char *argv[])
{
    // pass argc and argv to the findMax function and print the return 
    printf("%d\n", findMax(argc, argv));
    return 0;
}


/* 
Function: findMax
Parameters: argc, argv
Desciption: return the largest value in the array argv
*/
int findMax(int argc, char *arr[])
{
    // initialise variable max to 0
    int max = 0;

    // loop through the array
    for (int i = 0; i < argc - 1; ++i)
    {
        // if the current max is less than the i'th element of the array
        // update the variable max
        if (max < atoi(arr[i + 1]))
        {
            max = atoi(arr[i + 1]);
        }
    }

    // return the variable max
    return max;
}