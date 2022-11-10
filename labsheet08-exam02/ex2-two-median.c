/*
Program: ex2-two-median.c
Author: Jamie Gorman
Date: 03/11/22
Input: array of elements from command line
Output: the two middle numbers from the sorted array
Approach: Bubble sort and take the (n // 2) - 1 and (n // 2) values
    we can take these two values as the array is always an even length
*/

/* Includes */
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*Function protypes*/
void get_arr(int *length, int *pNumbers, char *argv[]);
void sort_arr(int *length, int *pNumbers);
void swap(int *a, int *b);
void get_median(int *length, int *pNumbers, int *pMedian);
void print_median(int *pMedian);

/*Main driver function*/
int main(int argc, char *argv[])
{
    int length = argc - 1;

    /*allocate memory to store our array and our two median values*/
    int *pMedian = (int *)malloc(2 * (sizeof(int)));
    int *pNumbers = (int *)malloc((length) * (sizeof(int)));

    if (!pNumbers || !pMedian)
    {
        printf("Failed to allocate memory!\n");
        return 0;
    }

    get_arr(&length, pNumbers, argv);
    sort_arr(&length, pNumbers);
    get_median(&length, pNumbers, pMedian);

    free(pNumbers);
    pNumbers = NULL;

    print_median(pMedian);

    free(pMedian);
    pMedian = NULL;

    return 0;
}

/*Function collects the input from command line*/
void get_arr(int *length, int *pNumbers, char *argv[])
{
    for (int i = 0; i < *length; ++i)
    {
        *(pNumbers + i) = atoi(argv[i + 1]);
    }
}

/*Function uses bubble sort to sort array*/
void sort_arr(int *length, int *pNumbers)
{
    for (int i = 0; i < *length; ++i)
    {
        for (int j = i; j < *length; ++j)
        {
            if (*(pNumbers + i) > *(pNumbers + j))
            {
                swap((pNumbers + i), (pNumbers + j));
            }
        }
    }
}

/*Helper function to swap the values at two addresses */
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/*Function grabs the two middle values from the sorted array*/
void get_median(int *length, int *pNumbers, int *pMedian)
{
    *(pMedian) = *(pNumbers + (*length / 2) - 1);
    *(pMedian + 1) = *(pNumbers + (*length / 2));
}

/*Function prints the two middle values*/
void print_median(int *pMedian)
{
    printf("%d\n%d\n", *(pMedian), *(pMedian + 1));
}