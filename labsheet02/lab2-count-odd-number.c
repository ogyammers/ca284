/*
Program: lab2-count-odd-number.c
Author: Jamie Gorman
Input: command line args is an arrary of integers
Output: number of odd integers encountered
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int arr[10];
    int odd_counter = 0;

    for (int i = 0; i < argc - 1; ++i)
    {
        arr[i] = atoi(argv[i + 1]);
        if (arr[i] % 2 == 1)
        {
            ++odd_counter;
        }
    }

    printf("%d\n", odd_counter);

    return 0;
}