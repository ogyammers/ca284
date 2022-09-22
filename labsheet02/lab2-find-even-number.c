/*
Program: lab2-count-even-number.c
Author: Jamie Gorman
Input: command line args is an arrary of integers
Output: index and value of all even integers
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int arr[10];
    int even_counter = 0;

    for (int i = 0; i < argc - 1; ++i)
    {
        arr[i] = atoi(argv[i + 1]);
        if (arr[i] % 2 == 0)
        {
            printf("%d - %d\n", i, arr[i]);
            even_counter++;
        }
    }
    if (even_counter == 0)
    {
        printf("Not found!\n");
    }

    return 0;
}