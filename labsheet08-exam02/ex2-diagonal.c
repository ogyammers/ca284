/*
Program: ex2-diagonal.c
Author: Jamie Gorman
Date: 03/11/22
Input: n - the size of a square array followed by its elements
Output: the sum of the anti-diagonal
Approach: step through the array taking only the anti diagonal
    elements and add them to a running sum
*/

/* Includes */
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*Function protypes*/
void get_arr(int *length, char *argv[], int *pArr);
void sum_diagonal(int *n, int *pArr, int *pSum);
void print_sum(int *pSum);

/*Main driver function*/
int main(int argc, char *argv[])
{
    int length = argc - 2;
    int n = atoi(argv[1]);

    /*allocate memory to store our array and our two median values*/
    int *pSum = (int *)malloc(1 * (sizeof(int)));
    int *pArr = (int *)malloc((n * n) * (sizeof(int)));
    if (!pArr || !pSum)
    {
        printf("Failed to allocated memory!");
        return 0;
    }

    get_arr(&length, argv, pArr);
    sum_diagonal(&n, pArr, pSum);

    free(pArr);
    pArr = NULL;

    print_sum(pSum);

    free(pSum);
    pSum = NULL;

    return 0;
}

/*Function grabs the values from command line*/
void get_arr(int *length, char *argv[], int *pArr)
{
    for (int i = 0; i < *length; ++i)
    {
        *(pArr + i) = atoi(argv[i + 2]);
    }
}

/*Function takes the values from the antidiagonal and adds to running sum*/
void sum_diagonal(int *n, int *pArr, int *pSum)
{
    *(pSum) = 0;
    /*pos keeps track of the position we want to visit*/
    int pos = *n - 1;
    for (int i = 0; i < *n; ++i)
    {
        *(pSum) += *(pArr + pos);
        pos += *n - 1;
    }
}

/*Function prints the sum of the antidiagonal*/
void print_sum(int *pSum)
{
    printf("%d\n", *(pSum));
}