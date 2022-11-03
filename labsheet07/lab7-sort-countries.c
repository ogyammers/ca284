/*
Author: Jamie Gorman
Program: find_country.c
Input: pCountries of countries with attributes
Output: all countries with size less than 100000km2
*/

/*Includes*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Type definitions*/
typedef struct Country Country;

/*Struct definitions*/
struct Country
{
    char country[50];
    char capital[50];
    float population;
    int size;
};

/*Function prototypes*/
void get_countries(int *n_countries, char *argv[], Country *pCountries);
void sort_countries(int *n_countries, Country *pCountries);
void swap_countries(Country *i, Country *j);
void print_countries(int *n_countries, Country *pCountries);

/*Main driver function*/
int main(int argc, char *argv[])
{
    int n_countries = ((argc - 1) / 4);
    Country countries[5];
    Country *pCountries = countries;

    get_countries(&n_countries, argv, pCountries);
    sort_countries(&n_countries, pCountries);
    print_countries(&n_countries, pCountries);

    return 0;
}

/*Function takes input from command line args and assigns them
to their structures*/
void get_countries(int *n_countries, char *argv[], Country *pCountries)
{
    int count = 0;
    Country *cptr = NULL;
    for (int i = 0; i < *n_countries; ++i)
    {
        /*Pointer to the i'th country in the structure*/
        cptr = &pCountries[i];
        strcpy(cptr->country, argv[++count]);
        strcpy(cptr->capital, argv[++count]);
        cptr->population = atof(argv[++count]);
        cptr->size = atoi(argv[++count]);
    }

    return;
}

/*Function uses bubble sort to sort items*/
void sort_countries(int *n_countries, Country *pCountries)
{

    for (int i = 0; i < *n_countries; ++i)
    {
        for (int j = i; j < *n_countries; ++j)
        {
            if (pCountries[i].population < pCountries[j].population)
            {
                swap_countries(&pCountries[i], &pCountries[j]);
            }
        }
    }
}

// Function swaps the value passed to it from bubble sort
void swap_countries(Country *i, Country *j)
{
    Country tmp = *i;
    *i = *j;
    *j = tmp;
}

/*Function prints the countries if the match the condition*/
void print_countries(int *n_countries, Country *pCountries)
{
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
    Country *cptr = NULL;
    for (int i = 0; i < *n_countries; ++i)
    {
        cptr = &pCountries[i];
        printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", cptr->country, cptr->capital,
               cptr->size, cptr->population);
    }
}