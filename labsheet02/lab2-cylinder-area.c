/*
Program: lab2-cylinder-area.c
Author: Jamie Gorman
Input: two command line args, radius and height
Output: print out area of cylinder
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("No input given!\n");
        return 1;
    }

    if (argc != 3)
    {
        printf("Two arguments needed!\n");
        return 1;
    }

    int radius = atoi(argv[1]);
    int height = atoi(argv[2]);
    float PI = 3.1415;
    float area;

    if (radius < 0 || height < 0)
    {
        printf("The radious or height cannot be negative!\n");
        return 1;
    }

    area = (2 * PI * radius * height) + (2 * PI * (radius * radius) + .0009);
    printf("%.2f\n", area);

    return 0;
}