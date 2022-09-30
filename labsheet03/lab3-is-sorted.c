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

// function prototypes
void get_arr(int length, char *argv[], int arr[]);
void bubble_sort(int arr[], int length);
void print_sorted_arr(int arr[], int length);

/*
Function: main
Parameters: argc, argv
Desciption: calls functions to sort and print array
*/
int main(int argc, char *argv[])
{
    int length = argc - 1;
    int arr[length];

    get_arr(length, argv, arr);
    bubble_sort(arr, length);
    print_sorted_arr(arr, length);

    return 0;
}

/*
Function: get_arr
Parameters: length, argv, arr
Desciption: returns arr, an array of integers from command line
*/
void get_arr(int length, char *argv[], int arr[])
{
    for (int i = 0; i < length; ++i)
    {
        arr[i] = atoi(argv[i + 1]);
    }
}

/*
Function: bubble_sort
Parameters: length and arr(and array of unsorted integers)
Desciption: uses bubble sort to sort arr
*/
void bubble_sort(int arr[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < length - i - 1; ++j)
        {
            // if the j'th value is greater than the j+1'th value
            // swap the values
            if (arr[j + 1] < arr[j])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

/*
Function: print_sorted_arr
Parameters: arr and length
Desciption: prints each element of the sorted array arr
    on a new line
*/
void print_sorted_arr(int arr[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        printf("%d\n", arr[i]);
    }
}