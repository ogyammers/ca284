/*
Program: lab3-calculator.c
Author: Jamie Gorman
Input: mutiply or divide and two floating points numbers
Output: calculate either division or multiplication
*/

// includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototype decalarations
void calculator(float x, float y, char operation[]);
float multiply(float x, float y);
float divide(float x, float y);

// main function
int main(int argc, char *argv[])
{
    float x = atof(argv[2]); // convert command line arg 2 into a floating point x
    float y = atof(argv[3]); // convert command line arg 2 into a floating point x

    char operation[10];         // create an array to store the operator string
    strcpy(operation, argv[1]); // copy the operator string from argv to the operation array

    calculator(x, y, operation); // call the function calculator and pass it the variable and operator

    return 0;
}

// calculator function, takes x, y and opertor and prints the result
void calculator(float x, float y, char operation[])
{
    if (strcmp(operation, "multiply") == 0)
    // if the operation is multiply call the function multiply
    {
        printf("%f\n", multiply(x, y));
    }

    else if (strcmp(operation, "divide") == 0 && y != 0)
    // if the operation is divide call the function divide
    {
        printf("%f\n", divide(x, y));
    }
    else
    // if neither operation is called or there could be a division by zero error print invalid
    {
        printf("invalid\n");
    }
}

// multiply function takes to floating points numbers and returns the product
float multiply(float x, float y)
{
    float result;
    result = x * y;
    return result;
}

// divide function takes two floating points numbers and returns the results of division
float divide(float x, float y)
{
    float result;
    result = x / y;
    return result;
}