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
            
            printf("*");

        }
        
        printf("\n");

    }

    return 0;

}
