/*
Program: lab9-dot-product-two-vector.c
Author: Jamie Gorman
Date: 10/11/22
Input: two vectors
Output: dot product of the two vectors
*/

/* Includes */
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*Function protypes*/
void get_vectors(char *argv[], int *n, int *p_vectorA, int *p_vectorB);
void get_dot_product(int *n, int *p_vectorA, int *p_vectorB, int *p_dot);
void print_dot(int *p_dot);

/*Main driver function*/
int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    int *p_vectorA = (int *)malloc(n * (sizeof(int)));
    int *p_vectorB = (int *)malloc(n * (sizeof(int)));
    int *p_dot = (int *)malloc(n * (sizeof(int)));
    if (!p_vectorA || !p_vectorB || !p_dot)
    {
        printf("Something went wrong here.\n Please try again!\n");
        exit(0);
    }

    get_vectors(argv, &n, p_vectorA, p_vectorB);
    get_dot_product(&n, p_vectorA, p_vectorB, p_dot);

    free(p_vectorA);
    free(p_vectorB);
    
    print_dot(p_dot);

    free(p_dot);

    return 0;
}

void get_vectors(char *argv[], int *n, int *p_vectorA, int *p_vectorB)
{
    for (int i = 0; i < *n * 2; ++i)
    {
        if (i < *n)
        {
            *(p_vectorA + i) = atoi(argv[i + 2]);
        }
        else
        {
            *(p_vectorB + i - *n) = atoi(argv[i + 2]);
        }
    }
}

void get_dot_product(int *n, int *p_vectorA, int *p_vectorB, int *p_dot)
{
    for (int i = 0; i < *n; ++i)
    {
        *(p_dot) += *(p_vectorA + i) * *(p_vectorB + i);
    }
}

void print_dot(int *p_dot)
{
    printf("%d\n", *(p_dot));
}