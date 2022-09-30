/*
Program: lab3-duplicated-number.c
Author: Jamie Gorman
Input: array of integers from command line
Output: find the duplicated value in the array
*/

// includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototype
int *get_arr(int length, char *argv[], int *arr);
int search_dup_number(int *int_arr, int length);

/*
Function: main
Parameters: argc, argv
Desciption: checks if the there are any duplicates in the array
*/
int main(int argc, char *argv[])
{
    // length for the array
    int length = argc - 1;

    // temp array to pass to and return from the the get_arr function
    int tmp_arr[50];
    
    // array to store the return array from the get_arr function
    int *int_arr;

    // variable to store the return value of the search__dup_number function
    int n;

    // call the get_arr function and store the return array
    int_arr = get_arr(length, argv, tmp_arr);

    // call the search_dup_number function and store the return value
    n = search_dup_number(int_arr, length);

    // check if there was a duplicated number
    // and print the desired result
    if (n == length)
    {
        printf("no duplicated number\n");
    }
    else
    {
        printf("%d\n", n);
    }

    return 0;
}

/*
Function: get_arr
Parameters: length of array, array and destination array
Desciption: takes the argv input from command line and returns a new
    array of integers in tmp_arr
*/
int *get_arr(int length, char *argv[], int *tmp_arr)
{
    for (int i = 0; i < length; ++i)
    {
        // store the integer values
        tmp_arr[i] = atoi(argv[i + 1]);
    }
    // return the new array
    return tmp_arr;
}

/*
Function: search__dup_number
Parameters: array to look in and length of array
Desciption: returns either the number if there was duplicate
    or the length of the array
*/
int search_dup_number(int *int_arr, int length)
{
    // loop through the array
    for (int i = 0; i < length; ++i)
    {
        // loop through the array
        for (int j = 0; j < length; ++j)
        {
            // check if for every j'th value of the array if it is a
            // duplicate of the current i'th value   
            if (int_arr[j] == int_arr[i] && i != j)
            {
                // if duplicate return the value
                return int_arr[j];
            }
        }
    }
    // if not duplicate return the length of array
    return length;
}