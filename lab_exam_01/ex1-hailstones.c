/*
Program: ex1-hailstones.c
Author: Jamie Gorman
Date: 06/10/22
Input: single command line argument(a positive int)
Output: print numbers in hailstone sequence until the sequence reaches 1
*/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Prototype decalarations */
void print_hailstone_sequnce(int start);

/*
Function: main
Parameters: argc, argv
Desciption: collects starting number from command line argument
    and drives the function print_hailstone_sequence
*/
int main(int argc, char *argv[])
{
    unsigned int start = atoi(argv[1]);
    /* convert from string to int,
    unsigned because we know its positive */

    print_hailstone_sequnce(start);
    /* call function print_hailstone_sequence,
    pass it the starting number */

    return 0;
}

/*
Function: print_hailstone_sequnce
Parameters: start(starting number)
Desciption: prints all the numbers in the hailstone
    sequence until we reach 1
*/
void print_hailstone_sequnce(int start)
{
    /* print the starting number */
    printf("%d ", start);

    /* loop while the number is not 1 */
    while (start != 1)
    {
        /* if the number is even divide by 2 */
        if (start % 2 == 0)
        {
            /* 2 is always the second last number in the sequence
            when 2 becomes 1 we do not want to add a space after
            we want a new line character */
            if (start == 2)
            {
                /* update the number */
                start = start / 2;
                /* print the last number 1 followed by newline */
                printf("%d\n", start);
            }
            /* if not 2 but it is even */
            else
            {
                /* update the number (divide by 2) */
                start = start / 2;
                /* print the number followed by a space */
                printf("%d ", start);
            }
        }
        /* if the number is not even */
        else
        {
            /* apply (3 * n) + 1 to the number */
            start = (3 * start + 1);
            /* print the number followed by a space */
            printf("%d ", start);
        }
    }
}