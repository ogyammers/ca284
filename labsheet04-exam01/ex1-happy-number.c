/*
Program: ex1-happy-number.c
Author: Jamie Gorman
Date: 06/10/22
Input: single command line argument(a positive int)
Output: is a happy number or not a happy number
*/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Prototype decalarations */
void is_happy(int n);
int recursive_sum_square_digits(int n, int x);
void print_is_happy(int n);

/*
Function: main
Parameters: argc, argv
Desciption: collects starting number from command line argument
    and drives the function is_happy
*/
int main(int argc, char *argv[])
{
    unsigned int n = atoi(argv[1]);
    /* convert from string to int,
    unsigned because we know its positive */

    is_happy(n);
    /* call the function is_happy and pass it
    the number n */

    return 0;
}

/*
Function: is_happy
Parameters: a positive integer n
Desciption: loops while n != 1 (is happy)
    and n != 4 (is not happy)
    calls the function recursive_sum_square_digits
    which returns the sum of the square of each digit in the number
    calls the function print_is_happy and passes it n
*/
void is_happy(int n)
{
    /* x is here to pass to the recursive function
    it will keep track of the number to be returned*/
    int x = 0;
    do
    {
        /* assign the return integer from the function
        recursive_sum_square_digits which itself is passed the
        current value of n and x*/
        n = recursive_sum_square_digits(n, x);
    } while (n != 1 && n != 4); /* do while n does not equal 1 or 4*/

    /* pass n to print_is_happy */
    print_is_happy(n);
}

/*
Function: recursive_sum_square_digits
Parameters: n and x
Desciption: our base case for n is less than one
    we divide n by 10 each time we call the function which knocks the last digit off
    n remainder(modulus) after division by 10 will give us that last digit
    square that digit and add it to the current x(which is the sum)
    when we reach our base case we should have squared each last digit and summed them up
    now we return x, which should be the sum of the square of all the digits
*/
int recursive_sum_square_digits(int n, int x)
{
    /* base case if n is less than 1 */
    if (n < 1)
    {
        /* return x the sum of all the squared digits*/
        return x;
    }
    /* keep recursively calling the function until we reach our base case
    we pass two numbers (n divided by 10 and x + (n mod 10 squared))*/
    return recursive_sum_square_digits(n / 10, x + (((n % 10) * (n % 10))));
}

/*
Function: print_is_happy
Parameters: n which should be either 1 or 4
Desciption: prints either is happy or is not happy
*/
void print_is_happy(int n)
{
    /* if n is 1 print is happy*/
    if (n == 1)
    {
        printf("is happy\n");
    }
    /* if not print not happy*/
    else
    {
        printf("not happy\n");
    }
}