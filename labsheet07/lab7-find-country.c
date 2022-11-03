/*
Author: Jamie Gorman
Program: find_country.c
Input: list of countries with attributes
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
void print_countries(int *n_countries, Country *pCountries);

/*Main driver function*/
int main(int argc, char *argv[])
{
    int n_countries = ((argc - 1) / 4);
    Country countries[5];
    Country *pCountries = countries;

    get_countries(&n_countries, argv, pCountries);
    print_countries(&n_countries, pCountries);

    return 0;
}

/*Function takes input from command line args and assigns them
to their structures*/
void get_countries(int *n_countries, char *argv[], Country *pCountries)
{
    int count = 0;
    for (int i = 0; i < *n_countries; ++i)
    {
        /*Pointer to the i'th country in the structure*/
        Country *cptr = &pCountries[i];
        strcpy(cptr->country, argv[++count]);
        strcpy(cptr->capital, argv[++count]);
        cptr->population = atof(argv[++count]);
        cptr->size = atoi(argv[++count]);
    }
    return;
}

/*Function prints the countries if the match the condition*/
void print_countries(int *n_countries, Country *pCountries)
{
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
    int limit = 100000;
    for (int i = 0; i < *n_countries; ++i)
    {
        Country *cptr = &pCountries[i];
        if (cptr->size < limit)
        {
            printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", cptr->country, cptr->capital,
                   cptr->size, cptr->population);
        }
    }
}