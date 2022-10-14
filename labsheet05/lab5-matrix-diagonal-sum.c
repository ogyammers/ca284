/*
Program: lab5-matric-diagonal.c
Author: Jamie Gorman
Input: a string from command line
Output: sum of the matrix diagonal
*/

/*Includes*/
#include <stdio.h>
#include <stdlib.h>

/*Function prototypes*/
void get_arr(int *pArr, char *argv[], int *plegnth);
void get_sum(int *pArr, int *pLength, int *pSum);

/*Main driver function*/
int main(int argc, char *argv[])
{
    int length = atoi(argv[1]);
    int *pLength = &length;

    int arr[*pLength];
    int *pArr = arr;

    int sum = 0;
    int *pSum = &sum;

    get_arr(pArr, argv, pLength);
    get_sum(pArr, pLength, pSum);

    printf("%d\n", sum);

    return 0;
}

/*Fuction grabs the diagonal components of an n*n array only*/
void get_arr(int *pArr, char *argv[], int *pLength)
{

    for (int i = 0, j = 2; i < *pLength; ++i, j += *pLength)
    {
        *(pArr + i) = atoi(argv[i + j]);
    }
}

/*Function updates sum with the sum of the array*/
void get_sum(int *pArr, int *pLength, int *pSum)
{
    for (int i = 0; i < *pLength; ++i)
    {
        *(pSum) += *(pArr + i);
    }
}
