#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_symmetric(int length, char str[]);

int main(int argc, char *argv[])
{
    int length = strlen(argv[1]);
    char str[length];

    strcpy(str, argv[1]);

    is_symmetric(length, str);

    return 0;
}

int is_symmetric(int length, char str[])
{
    for (int i = 0; str[i] == str[length - i - 1]; ++i)
    {
        if (i > length / 2 + 1)
        {
            printf("yes\n");
            return 0;
        }
    }
    printf("no\n");
}