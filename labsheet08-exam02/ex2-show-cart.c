/*
Program: ex2-show-cart.c
Author: Jamie Gorman
Date: 03/11/22
Input: list of shopping items in a cart
Output: print formatted shopping list
Approach: take items from command line and store them in a
    structure, then print those items
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
void print_cart(int *n_items, Cart *my_cart);

/*Main driver function*/
int main(int argc, char *argv[])
{
    int n_items = (argc - 1) / 4;

    /*alocate memory for our structures*/
    Cart *my_cart = malloc(n_items * sizeof(*my_cart));
    if (!my_cart)
    {
        printf("Failed to allocate memory!\n");
        return 0;
    }

    get_cart(&n_items, my_cart, argv);
    print_cart(&n_items, my_cart);

    free(my_cart);
    my_cart = NULL;

    return 0;
}

/*Function gets items in cart from command line*/
void get_cart(int *n_items, Cart *my_cart, char *argv[])
{
    int count = 0;
    for (int i = 0; i < *n_items; ++i)
    {
        /*pointer to the i'th item in the cart*/
        Cart *cptr = &my_cart[i];

        strcpy(cptr->item, argv[++count]);
        cptr->amount = atoi(argv[++count]);
        cptr->price = atof(argv[++count]);
        cptr->promotion = atoi(argv[++count]);
    }
}

/*Function prints items in cart*/
void print_cart(int *n_items, Cart *my_cart)
{
    for (int i = 0; i < *n_items; ++i)
    {
        Cart *cptr = &my_cart[i];
        char promo[10];
        if (cptr->promotion == 0)
        {
            strcpy(promo, "No Sale");
        }
        else
        {
            strcpy(promo, "On Sale");
        }
        printf("%s,%d,%.2f,%s\n", cptr->item, cptr->amount, cptr->price, promo);
    }
}