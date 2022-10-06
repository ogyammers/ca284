/*
Program: ex1-odd-even-array
Author: Jamie Gorman
Date: 06/10/22
Input: set of integer numbers
Output: calculates the sum of the odd elements and
    subtract the 2nd, 3rd etc. even elements from the first even element
*/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Prototype decalarations */
void get_arr(int length, char *argv[], int int_arr[]);
void sum_odd_and_even(int length, int int_arr[]);
int first_even(int length, int int_arr[]);

/*
Function: main
Parameters: argc, argv
Desciption: takes the length of the array
    create an integer array to store the integers
    drive get_arr and sum_odd_and_even
*/
int main(int argc, char *argv[])
{
    /* store length for array*/
    int length = argc - 1;
    /* integer array for the values */
    int int_arr[50];

    /* call the get_arr function*/
    get_arr(length, argv, int_arr);

    /* call the sum_even_and_odd function*/
    sum_odd_and_even(length, int_arr);

    return 0;
}

/*
Function: get_arr
Parameters: length, argv, int_arr
Desciption: collects the integers from the command line
    and stores them in the array int_arr
*/
void get_arr(int length, char *argv[], int int_arr[])
{
    for (int i = 0; i < length; ++i)
    {
        /* convert the argv value from string to integer
        and store it in the integer array*/
        int_arr[i] = atoi(argv[i + 1]);
    }
}

/*
Function: sum_odd_and_even
Parameters: length, int_arr
Desciption: sums the odd elements and
    subtracts the sum of the even elements except for the first
    even element and the subtracts that sum from the first even
    element
*/
void sum_odd_and_even(int length, int int_arr[])
{
    /* variable stores the sum_even initilise it to the first even number
    using function first_even*/
    int sum_even = first_even(length, int_arr);
    /* variable to store the odd sum, init to zero*/
    int sum_odd = 0;

    /* loop through each integer in the array*/
    for (int i = 0; i < length; ++i)
    {
        /* if the number is even subtract it from the current even sum*/
        if (int_arr[i] % 2 == 0)
        {
            sum_even -= int_arr[i];
        }
        /* else if the number is not even add it to the odd sum*/
        else
        {
            sum_odd += int_arr[i];
        }
    }
    /* print the odd sum followed by a newline followed by the even sum*/
    printf("%d\n%d\n", sum_odd, sum_even);
}

/*
Function: first_even
Parameters: length, int_arr
Desciption: finds the first even number if it exists and returns it
    also replaces that index of the array with zero to avoid double
    counting it in our sum_odd_and_even function
*/
int first_even(int length, int int_arr[])
{
    /* variable to store first even number*/
    int first_even = 0;
    for (int i = 0; i < length; ++i)
    {
        /* test if it is even */
        if (int_arr[i] % 2 == 0)
        {
            /* store the value in a variable so we
            can replace the index with zero*/
            first_even = int_arr[i];
            int_arr[i] = 0;
            /* return the value of the first even number*/
            return first_even;
        }
    }
    /* no even number found return zero*/
    return 0;
}