#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_arr(int length, char *argv[], int int_arr[]);
void sum_odd_and_even(int length, int int_arr[]);
int first_even(int length, int int_arr[]);

int main(int argc, char *argv[])
{
    int length = argc - 1;
    int int_arr[50];

    get_arr(length, argv, int_arr);

    sum_odd_and_even(length, int_arr);

    return 0;
}

void get_arr(int length, char *argv[], int int_arr[])
{
    for (int i = 0; i < length; ++i)
    {
        int_arr[i] = atoi(argv[i + 1]);
    }
}

void sum_odd_and_even(int length, int int_arr[])
{
    int sum_even = first_even(length, int_arr);
    int sum_odd = 0;
    
    for (int i = 0; i < length; ++i)
    {
        if (int_arr[i] % 2 == 0)
        {
            sum_even -= int_arr[i];
        }
        else
        {
            sum_odd += int_arr[i];
        }
    }

    printf("%d\n%d\n", sum_odd, sum_even);
}

int first_even(int length, int int_arr[])
{
    int first_even = 0;
    for (int i = 0; i < length; ++i)
    {
        if (int_arr[i] % 2 == 0)
        {
            first_even = int_arr[i];
            int_arr[i] = 0;
            return first_even;
        }
    }
    return 0;
}