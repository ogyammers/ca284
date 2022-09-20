#include <stdio.h>
#include <stdlib.h>


int main(int argc, char*argv[])
{
    int n_1, n_2, sum;

    n_1 = atoi(argv[1]);
    n_2 = atoi(argv[2]);

    sum = n_1 + n_2;

    printf("%d\n", sum);
    return 0;
}