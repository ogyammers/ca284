#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float largest_or_smallest(char req[], int length, float float_arr[]);
void get_arr(int length, char *argv[], float float_arr[]);
float get_largest(int length, float float_arr[]);
float get_smallest(int length, float float_arr[]);


int main(int argc, char * argv[])
{
    int length = argc - 2;
    float float_arr[50];

    char req[10];
    strcpy(req, argv[1]);

    get_arr(length, argv, float_arr);
    printf("%.2f\n", largest_or_smallest(req, length, float_arr));

    return 0;
}

float largest_or_smallest(char req[], int length, float float_arr[])
{
    if (strcmp(req, "largest") == 0)
    {
        return (get_largest(length, float_arr));
    }
    else if (strcmp(req, "smallest") == 0)
    {
        return get_smallest(length, float_arr);

    }
    else
    {
        printf("Error: please enter largest or smallest!\n");
        exit(0);
    }
}

void get_arr(int length, char *argv[], float float_arr[])
{
    for (int i = 0; i < length; ++i)
    {
        float_arr[i] = atof(argv[i + 2]);
    }
}

float get_largest(int length, float float_arr[])
{
    float largest = float_arr[0];
    for (int i = 0; i < length; ++i)
    {
        if (largest < float_arr[i])
        {
            largest = float_arr[i];
        } 
    }
    return largest;
}

float get_smallest(int length, float float_arr[])
{
    float smallest = float_arr[0];
    for (int i = 0; i < length; ++i)
    {
        if (float_arr[i] < smallest)
        {
            smallest = float_arr[i];
        } 
    }
    return smallest;
}