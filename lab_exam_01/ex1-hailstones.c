#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_hailstone_sequnce(int start);

int main(int argc, char *argv[])
{
    unsigned int start = atoi(argv[1]);

    print_hailstone_sequnce(start);

    return 0;
}

void print_hailstone_sequnce(int start)
{
    printf("%d ", start);
    while (start != 1)
    {
        if (start % 2 == 0)
        {
            if (start == 2)
            {
                start = start / 2;
                printf("%d", start);
            }
            else
            {
                start = start / 2;
                printf("%d ", start);
            }
        }
        else
        {
            start = (3 * start + 1);
            printf("%d ", start);
        }
    }
    printf("\n");
}