/*
Author: Jamie Gorman
Input: country details from command line
Output: country data
*/

/*Includes*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Type definition*/
typedef struct Country Country;

/*Structure definition*/
struct Country
{
    char country[20];
    char capital[20];
    float population;
    int size;
};

/*Function prototypes*/
void print_country(Country *cptr, int *countries);
void get_countries(int *countries, char *argv[], struct Country country[]);

/*Main driver funtion*/
int main(int argc, char *argv[])
{
    int countries = (argc - 1) / 4;
    Country country[50];

    get_countries(&countries, argv, country);
    print_country(country, &countries);

    return 0;
}

/*Retreives and stroes country information in the array of structures*/
void get_countries(int *countries, char *argv[], struct Country country[])
{
    int count = 0;
    Country *cptr = NULL;
    for (int i = 0; i < *countries; ++i)
    {
        cptr = &country[i];
        strcpy(cptr->country, argv[++count]);
        strcpy(cptr->capital, argv[++count]);
        cptr->population = atof(argv[++count]);
        cptr->size = atoi(argv[++count]);
    }
    return;
}

/*Print out the details of the country*/
void print_country(Country *country, int *countries)
{
    Country *cptr = NULL;
    float tot_pop = 0.0;
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
    for (int i = 0; i < *countries; ++i)
    {
        cptr = &country[i];
        tot_pop += cptr->population;
        printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", cptr->country, cptr->capital, cptr->size, cptr->population);
    }
    printf("Population average: %.2f\n", tot_pop / *countries);
}
