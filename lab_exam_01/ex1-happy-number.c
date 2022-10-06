#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void is_happy(int n);
int sum_square_digits(int n, int x);
void print_is_happy(int n);

int main(int argc, char *argv[])
{
    unsigned int n = atoi(argv[1]);

    is_happy(n);

    // printf("%d", n);

    return 0;
}

void is_happy(int n)
{
    int x = 0;
    do
    {
        n = sum_square_digits(n, x);
    } while (n != 1 && n != 4);

    print_is_happy(n);
}

int sum_square_digits(int n, int x)
{
    // printf("%d\n", x);
    if (n < 1)
    {
        return x;
    }
    return sum_square_digits(n / 10, x + (((n % 10) * (n % 10))));
}

void print_is_happy(int n)
{
    if (n == 1)
    {
        printf("is happy\n");
    }
    else
    {
        printf("not happy\n");
    }
}