/*
Author: Jamie Gorman
Input: country details from command line
Output: the country data
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
void print_country(Country *cptr);

/*Main driver funtion*/
int main(int argc, char *argv[])
{
    Country country;
    Country *cptr = &country;

    strcpy(cptr->country, argv[1]);
    strcpy(cptr->capital, argv[2]);
    cptr->population = atof(argv[3]);
    cptr->size = atoi(argv[4]);

    print_country(cptr);

    return 0;
}

/*Print out the details of the country*/
void print_country(Country *cptr)
{
    printf("%s\n", cptr->country);
    printf("%s\n", cptr->capital);
    printf("%.2f million people\n", cptr->population);
    printf("%d km2\n", cptr->size);
}
