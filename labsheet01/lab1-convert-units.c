#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
    int cm = 0;
    float inch = 0;

    cm = atoi(argv[1]);
    inch = cm / 2.54;

    printf("%.2f\n", inch);
    return 0;
}