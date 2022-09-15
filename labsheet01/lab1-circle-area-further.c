#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char*argv[])
{

    int radius = 3;
    float area = 0.0;
    float PI = 3.14;


    // radius = atoi(argv[1]);
    radius = radius * radius; // circle cannot have a negative radius
    // and if the radius entered is negative, any negative number by itself returns a positive number

    area = radius*PI;

    printf("%.2f\n", area);


    return 0;
}