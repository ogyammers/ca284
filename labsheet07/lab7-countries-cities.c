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
typedef struct City City;

/*Struct definitions*/
struct City
{
    char name[50];
    float size;
};

struct Country
{
    City city[3];
    char country[50];
};

/*Function prototypes*/
void get_countries(int *n_countries, char *argv[], Country *pCountries);
void print_countries(int *n_countries, Country *pCountries);

/*Main driver function*/
int main(int argc, char *argv[])
{
    int n_countries = ((argc - 1) / 7);
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
    int cities = 3;
    Country *cptr = NULL;
    for (int i = 0; i < *n_countries; ++i)
    {
        /*Pointer to the i'th country in the structure*/
        cptr = &pCountries[i];
        strcpy(cptr->country, argv[++count]);

        for (int j = 0; j < cities; ++j)
        {
            strcpy((pCountries[i]).city[j].name, argv[++count]);
            (pCountries[i]).city[j].size = atof(argv[++count]);
        }
    }
}

/*Function prints city from each country with the biggest size*/
void print_countries(int *n_countries, Country *pCountries)
{
    int cities = 3;
    int biggest = 0;
    for (int i = 0; i < *n_countries; ++i)
    {
        biggest = 0;
        for (int j = 1; j < cities; ++j)
        {
            if ((pCountries[i]).city[j].size > (pCountries[i]).city[biggest].size)
            {
                biggest = j;
            }
        }
        printf("%s: %s\n", pCountries[i].country, (pCountries[i]).city[biggest].name);
    }
}