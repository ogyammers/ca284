#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char*argv[])
{

    int radius = 0;
    float area = 0.0;
    float PI = 3.1415;


    radius = atoi(argv[1]);
    radius = radius * radius;

    area = radius*PI;

    printf("%.2f\n", area);

    // printf("%9.2f\n", area);

    return 0;
}