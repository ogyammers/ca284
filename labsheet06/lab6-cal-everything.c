/*
Author: Jamie Gorman
Input: two integers from command line
Output: the result of different operations
*/

/*Includes*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*Function prototypes*/
void calc(void (*pCalc)(int *, int *, float *), int *a, int *b, float *result);
void sum(int *a, int *b, float *result);
void difference(int *a, int *b, float *result);
void product(int *a, int *b, float *result);
void division(int *a, int *b, float *result);
void power(int *a, int *b, float *result);
void nat_log(int *a, int *b, float *result);

/*Type definitions*/
typedef void (*calc_func)(int *, int *, float *);

/*Main driver function*/
int main(int argc, char *argv[])
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    float result = 0;

    /*pointer to the specified operator function*/
    void (*pCalc)(int *, int *, float *) = NULL;

    /*array of function pointers*/
    calc_func fparr[6] = {sum, difference, product, division, power, nat_log};

    /*point pCalc to the next opertion and pass it to calculator*/
    for (int i = 0; i < sizeof(fparr) / sizeof(fparr[0]); ++i)
    {
        pCalc = fparr[i];
        calc(pCalc, &a, &b, &result);
        printf("%.2f\n", result);
    }

    return 0;
}

/*Calculator driver, calls the specified operations*/
void calc(void (*pCalc)(int *, int *, float *), int *a, int *b, float *result)
{
    pCalc(a, b, result);
}

void sum(int *a, int *b, float *result)
{
    *result = *a + *b;
}

void difference(int *a, int *b, float *result)
{
    *result = *a - *b;
}

void product(int *a, int *b, float *result)
{
    *result = *a * *b;
}

void division(int *a, int *b, float *result)
{
    *result = *a / *b;
}

void power(int *a, int *b, float *result)
{
    *result = pow(*a, *b);
}

void nat_log(int *a, int *b, float *result)
{
    *result = log(*a) + log(*b);
}