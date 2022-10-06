/*
Program: ex1-largest-smallest.c
Author: Jamie Gorman
Date: 06/10/22
Input: a requirement and an array of floating point numbers
Output: find the requirement, either the largest or the smallest
    floating point number in the array
*/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Prototype decalarations */
float largest_or_smallest(char req[], int length, float float_arr[]);
void get_arr(int length, char *argv[], float float_arr[]);
float get_largest(int length, float float_arr[]);
float get_smallest(int length, float float_arr[]);

/*
Function: main
Parameters: argc, argv
Desciption: collects the length for the array
    creates a array for our floating points
    creats and array to hold the string requirement(largest or smallest)
    copys the requirement from argv to req
    drives get_arr and largest_or_smallest functions
*/
int main(int argc, char *argv[])
{
    /* length will be argc minus the name of the program
    and minus the requirement*/
    int length = argc - 2;
    /* make array for floats*/
    float float_arr[50];
    /* make array for string*/
    char req[10];
    /* copy requirement to req*/
    strcpy(req, argv[1]);
    /* call get_arr and pass it length, argv, and the floating point array*/
    get_arr(length, argv, float_arr);
    /* call largest_or_smallest and print the return value */
    printf("%.2f\n", largest_or_smallest(req, length, float_arr));

    return 0;
}

/*
Function: largest_or_smallest
Parameters: requirement, length, floating point array
Desciption: determines the requirent and calls the relevent function
*/
float largest_or_smallest(char req[], int length, float float_arr[])
{
    /* if req is largest call the get_largest function*/
    if (strcmp(req, "largest") == 0)
    {
        /* return the results of get_largest to main*/
        return (get_largest(length, float_arr));
    }
    else if (strcmp(req, "smallest") == 0)
    {
        /* return the result of get_smallest to main*/
        return get_smallest(length, float_arr);
    }
    else
    {
        /* if not largest or smallest print error and exit*/
        printf("Error: please enter largest or smallest!\n");
        exit(0);
    }
}

/*
Function: get_arr
Parameters: length, argv, float_arr
Desciption: collects the floating points from argv and stores
    them in a floating point array
*/
void get_arr(int length, char *argv[], float float_arr[])
{
    for (int i = 0; i < length; ++i)
    {
        /* convert the argv value from string to float
        and store it in the floating point array*/
        float_arr[i] = atof(argv[i + 2]);
    }
}

/*
Function: get_largest
Parameters: length and floating point array
Desciption: returns the largest value in the floating point array
*/
float get_largest(int length, float float_arr[])
{
    /* float variable to store the largest number initialise it to
    the first value in the array*/
    float largest = float_arr[0];
    for (int i = 0; i < length; ++i)
    {
        /* if the current largest is less than the value
        at the current index of the array*/
        if (largest < float_arr[i])
        {
            /* update the largest variable*/
            largest = float_arr[i];
        }
    }
    /* loop complete return the largest floating point number*/
    return largest;
}

/*
Function: get_smallest
Parameters: length and floating point array
Desciption: returns the smallest value in the floating point array
*/
float get_smallest(int length, float float_arr[])
{
    /* float variable to store the smallest number initialise it to
    the first value in the array*/
    float smallest = float_arr[0];
    for (int i = 0; i < length; ++i)
    {
        /* if the current smallest is larger than the value
        at the current index of the array*/
        if (float_arr[i] < smallest)
        {
            /* update the smallest variable*/
            smallest = float_arr[i];
        }
    }
    /* loop complete return the smallest floating point number*/
    return smallest;
}