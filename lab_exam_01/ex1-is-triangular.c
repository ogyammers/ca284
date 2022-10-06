/*
Program: ex1-is-triangular.c
Author: Jamie Gorman
Date: 06/10/22
Input: one integer from command line
Output: determines whether the input is a triangular number or not
*/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function prototypes */
int is_triangle(int n);

/*
Function: main
Parameters: argc, argv
Desciption: collects our integer n from command line
    drives the function is_triangle
*/
int main(int argc, char *argv[])
{
    /* convert the command line argument to an integer n*/
    int n = atoi(argv[1]);

    /* pass n to the function is_triangle*/
    is_triangle(n);

    return 0;
}

/*
Function: is_triangle
Parameters: an integer n
Desciption: determines if n is triangular
    the rule states that if an integer i exists for which
    it satisfies (i(i + 1)/2) = n then n is a triangular number
*/
int is_triangle(int n)
{
    /* start at and check each i while less than n*/
    for (int i = 0; i < n; ++i)
    {
        /* if our formula is satisfied print the number is triangular
        and return to main*/
        if ((i * (i + 1) / 2) == n)
        {
            printf("%d is a triangular number\n", n);
            return 0;
        }
    }
    /* if the loop completes we know we did not find an i to satisfy to
    formula*/
    printf("%d is not a triangular number\n", n);
}
