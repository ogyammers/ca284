/*
Program: ex3-find-frequent.c
Author: Jamie Gorman
Date: 30/11/22
Input: command line integers
Output: the frequent elements sorted in ascending order
Approach: Grab array from command line, sort the array,
    print elements if they are the same as the next element in the sorted array
*/

/*Includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Function prototypes*/
void get_arr(int *size_p_numbers, char *argv[], int *p_numbers);
void get_dups(int *size_p_numbers, int *size_dups, int *p_numbers, int *dups);
void sort_arr(int *size_dups, int *dups);
void swap(int *a, int *b);
void printArray(int *size_dups, int *dups);

/*Main driver function*/
int main(int argc, char *argv[])
{
    int size_p_numbers = 5;
    int *p_numbers = (int *)calloc(size_p_numbers, sizeof(int));
    get_arr(&size_p_numbers, argv, p_numbers);

    int *dups = (int *)calloc(1, sizeof(int));
    int size_dups = 0;
    get_dups(&size_p_numbers, &size_dups, p_numbers, dups);

    sort_arr(&size_dups, dups);
    printArray(&size_dups, dups);
    return 0;
}

/*This function gets the array from command line
enough space for first 5 integers, if there are more than 5
we allocate 1 more space each time*/
void get_arr(int *size, char *argv[], int *p_numbers)
{
    int i = 0;
    while (argv[i + 1])
    {
        if (i == *size)
        {
            *size += 1;
            int *p_tmp = realloc(p_numbers, *size * sizeof(int));
            if (!p_tmp)
            {
                printf("Error allocating memory!");
                free(p_tmp);
                p_tmp = NULL;
                exit(0);
            }
            p_numbers = p_tmp;
        }

        *(p_numbers + i) = atoi(argv[i + 1]);
        i = i + 1;
    }
}
/*This function builds a new array of duplicate numbers*/
void get_dups(int *size_p_numbers, int *size_dups, int *p_numbers, int *dups)
{
    int number;
    for (int i = 0; i < *size_p_numbers; ++i)
    {
        number = 1;
        for (int j = 0; j < *size_p_numbers; ++j)
        {
            if (i != j)
            {
                if (*(p_numbers + i) == *(p_numbers + j))
                {
                    number++;
                }
            }
        }
        if (number > 3)
        {
            *(size_dups) += 1;
            dups = (int *)realloc(dups, *size_dups * sizeof(int));
            *(dups + *size_dups - 1) = *(p_numbers + i);
        }
    }
}

/*This function uses selection sort to sort out array*/
void sort_arr(int *size_dups, int *dups)
{
    for (int i = 0; i < *size_dups; ++i)
    {
        for (int j = i; j < *size_dups; ++j)
        {
            if (*(dups + i) > *(dups + j))
            {
                swap((dups + i), (dups + j));
            }
        }
    }
}

/*Helper function for swapping two elements of an array*/
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void printArray(int *size_dups, int *dups)
{
    for (int i = 0; i < *size_dups; ++i)
    {
        if (*(dups + i) != 0)
        {
            printf("%d\n", *(dups + i));
        }
    }
}