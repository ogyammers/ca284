/*
Program: lab9-largest-twice.c
Author: Jamie Gorman
Date: 11/11/22
Input: array of integer values
Output: print the largest value which is a
    least twice as much as the last value
*/

/* Includes */
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*Function protypes*/
void get_arr(int *length, char *argv[], int *p_arr);
void selection_sort(int *length, int *p_arr);
void swap_elements(int *a, int *b);
void get_second_largest(int *length, int *p_arr);
void print_result(int *last, int *p_arr);

/*Main driver function*/
int main(int argc, char *argv[])
{
    int length = argc - 1;
    int last = atoi(*(argv + length));
    int *p_arr = (int *)malloc(length * sizeof(int));
    if (!p_arr)
    {
        printf("Error allocating space\n");
        exit(0);
    }

    get_arr(&length, argv, p_arr);
    selection_sort(&length, p_arr);
    print_result(&last, p_arr);

    free(p_arr);
    return 0;
}

void get_arr(int *length, char *argv[], int *p_arr)
{
    for (int i = 0; i < *length; ++i)
    {
        *(p_arr + i) = atof(argv[i + 1]);
    }
}

void selection_sort(int *length, int *p_arr)
{
    int largest;
    for (int i = 0; i < *length; i++)
    {
        largest = i;
        for (int j = i + 1; j < *length; ++j)
        {
            if (*(p_arr + largest) < *(p_arr + j))
            {
                largest = j;
            }
        }
        swap_elements(p_arr + i, p_arr + largest);
    }
}

void swap_elements(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_result(int *last, int *p_arr)
{
    if (*(p_arr) > 2 * *last)
    {
        printf("%d\n", *p_arr);
    }
    else
    {
        printf("0\n");
    }
}