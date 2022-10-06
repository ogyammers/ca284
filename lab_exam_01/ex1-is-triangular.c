#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_triangle(int n);

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);

    is_triangle(n);

    return 0;
}

int is_triangle(int n)
{
    for (int i = 0; i < n; ++i)
    {
        if ((i * (i + 1) / 2) == n)
        {
            printf("%d is a triangular number\n", n);
            return 0;
        }
    }
    printf("%d is not a triangular number\n", n);
}

