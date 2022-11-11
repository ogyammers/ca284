/*
Program: lab9-second-largest.c
Author: Jamie Gorman
Date: 11/11/22
Input: array of floating point numbers
Output: print the second largest number in the array
*/

/* Includes */
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*Function protypes*/
void get_arr(int *length, char *argv[], float *p_arr);
void selection_sort(int *length, float *p_arr);
void swap_elements(float *a, float *b);
void get_second_largest(int *length, float *p_arr);
void print_second_largest(float *second_largest);

/*Main driver function*/
int main(int argc, char *argv[])
{
    int length = argc - 1;
    float *p_arr = (float *)malloc(length * sizeof(float));
    if (!p_arr)
    {
        printf("Error allocating space\n");
        exit(0);
    }

    get_arr(&length, argv, p_arr);
    selection_sort(&length, p_arr);
    get_second_largest(&length, p_arr);
    free(p_arr);
    return 0;
}

void get_arr(int *length, char *argv[], float *p_arr)
{
    for (int i = 0; i < *length; ++i)
    {
        *(p_arr + i) = atof(argv[i + 1]);
    }
}

void selection_sort(int *length, float *p_arr)
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

void swap_elements(float *a, float *b)
{
    float tmp = *a;
    *a = *b;
    *b = tmp;
}

void get_second_largest(int *length, float *p_arr)
{
    float tmp = *(p_arr + 0);
    for (int i = 0; i < *length; ++i)
    {
        if (tmp != *(p_arr + i))
        {
            tmp = *(p_arr + i);
            break;
        }
    }
    print_second_largest(&tmp);
}

void print_second_largest(float *tmp)
{
    printf("%.1f\n", *(tmp));
}