/*
Program: lab3-search-number.c
Author: Jamie Gorman
Input: value to find and an array of integers from command line
Output: find the value in the array
*/

// includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototype
int *get_arr(int length, char *argv[], int *arr);
int search_number(int value, int *int_arr, int length);

/* 
Function: main
Parameters: argc, argv
Desciption: checks if the value was found in the array
*/
int main(int argc, char *argv[])
{
    // store the value that we are searching for
    int value = atoi(argv[1]);
    // length for the array
    int length = argc - 2;

    // temp array to pass to and return from the the get_arr function
    int tmp_arr[50];
    // array to store the return array from the get_arr function
    int *int_arr;

    // variable to store the return value of the search_number function
    int search_index;

    // call the get_arr function and store the return array
    int_arr = get_arr(length, argv, tmp_arr);

    // call the search_number function and store the return value
    search_index = search_number(value, int_arr, length);

    // check if the value was found or not
    // and print the desired result
    if (search_index == length)
    {
        printf("%d not found\n", value);
    }
    else
    {
        printf("Found %d at %d\n", value, search_index);
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
        tmp_arr[i] = atoi(argv[i + 2]);
    }
    //return the new array
    return tmp_arr;
}

/* 
Function: search_number
Parameters: value to find, array to look in and length of array
Desciption: returns either the position of the array at which the
    value resides or the length of the array if the value is not found
*/
int search_number(int value, int *int_arr, int length)
{
    for (int i = 0; i < length; ++i)
    {
        // check if the value is present at each iteration of the array
        if (value == int_arr[i])
        {
            // if found return the index
            return i;
        }
    }
    // if not found return the length of the array
    return length;
}