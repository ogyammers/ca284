#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int cm = 30;
    float inch = cm;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            inch = cm / 2.54;
            printf("%dcm = %.2finches\t", cm, inch);
            cm++;
        }
        printf("\n");
    }
    return 0;

}