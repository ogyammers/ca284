#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
    int x = 0;
    int y = 0;

    x = atoi(argv[1]);
    y = atoi(argv[2]);

    for (int i = 0; i < y; ++i)
    {
        
        for (int j = 0; j < x; ++j)
        {
            if (i == 0 || i == y - 1)
            {
                printf("*");
            }

            else if (j == 0 || j == x - 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
            

            

        }
        
        printf("\n");

    }

    return 0;

}
