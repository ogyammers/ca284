#include <stdio.h>

int main()
{
    int x = 15000;
    int y = 15000;

    printf("%d\n", x + y);

    x = x + 200000000;
    y = y + 990000000;

    printf("%d\n", x + y);
    return 0;
}