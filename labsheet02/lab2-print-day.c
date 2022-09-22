/*
Program: lab2-print-day.c
Author: Jamie Gorman
Input: given an integer 1-7
Output: prints day that corresponds to that integer
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int day_num = atoi(argv[1]);

    char *arr[7];
    arr[0] = "Sunday";
    arr[1] = "Monday";
    arr[2] = "Tuesday";
    arr[3] = "Wednesday";
    arr[4] = "Thursday";
    arr[5] = "Friday";
    arr[6] = "Saturday";
    
    printf("%s\n", arr[day_num - 1]);
    return 0;
}