/*
Program: ex2-discount.c
Author: Jamie Gorman
Date: 03/11/22
Input: list of shopping items in a cart
Output: print price of the items in the cart
Approach: take items from command line and store them in a
    structure, then find the price and print it
*/

/* Includes */
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Type definitions*/
typedef struct Cart Cart;

/*Structure definitions*/
struct Cart
{
    char item[20];
    unsigned int amount;
    float price;
    bool promotion;
};

/*Function protypes*/
void get_cart(int *n_items, Cart *my_cart, char *argv[]);
void get_cost(int *n_items, Cart *my_cart, float *pCost);
void print_cost(float *pCost);

/*Main driver function*/
int main(int argc, char *argv[])
{
    int n_items = (argc - 1) / 4;

    /*alocate memory for our structues and the total cost*/
    float *pCost = (float *)malloc(1 * sizeof(float));
    Cart *my_cart = malloc(n_items * sizeof(*my_cart));
    if (!my_cart || !pCost)
    {
        printf("Failed to allocate memory!\n");
        return 0;
    }

    get_cart(&n_items, my_cart, argv);
    get_cost(&n_items, my_cart, pCost);

    free(my_cart);
    my_cart = NULL;

    print_cost(pCost);

    free(pCost);
    pCost = NULL;
    

    return 0;
}

/*Function gets items in cart from command line*/
void get_cart(int *n_items, Cart *my_cart, char *argv[])
{
    int count = 0;
    for (int i = 0; i < *n_items; ++i)
    {
        Cart *cptr = &my_cart[i];

        strcpy(cptr->item, argv[++count]);
        cptr->amount = atoi(argv[++count]);
        cptr->price = atof(argv[++count]);
        cptr->promotion = atoi(argv[++count]);
    }
}

/*Function gets the cost of the items in the cart*/
void get_cost(int *n_items, Cart *my_cart, float *pCost)
{
    *(pCost) = 0;
    for (int i = 0; i < *n_items; ++i)
    {
        /*pointer to the i'th item in the cart*/
        Cart *cptr = &my_cart[i];
        if (cptr->promotion == 1)
        {
            *(pCost) += ((cptr->amount / 3) * 2 * cptr->price) + ((cptr->amount % 3) * cptr->price);
        }
        else
        {
            *(pCost) += (cptr->amount * cptr->price);
        }
    }
}

/*Function prints the cost of the items in the cart*/
void print_cost(float *pCost)
{
    printf("%.2f\n", *pCost);
}