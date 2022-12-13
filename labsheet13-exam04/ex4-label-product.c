/*
Program: ex4-label-product.c
Author:Jamie Gorman
Date: 13/12/22
Input: list of groceries in a cart
Output: status and country of origin of each item
Approach:
	Grab the items from command line and populate a
		linked list with them
	Find the average sales of all items
	Update each items status if it has greater than or equal to
		average sales or less than average sales
	Print out each items status and its country of origin
*/

/*Includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Type definitions*/
typedef struct Cart Cart;

/*Structure definitions*/
struct Cart
{
	char code[20];
	float price;
	unsigned int sold;
	int status;
	Cart *next;
};

/*Function prototypes*/
Cart *get_cart(int *length, char *argv[]);
Cart *new_item();
float get_avg_sales(int *length, Cart *first_item);
void update_status(float *avg_sales, Cart *first_item);
void print_cart(Cart *first_item);
const char *get_country(char *country_code);

/*Main driver function*/
int main(int argc, char *argv[])
{
	int length = (argc - 1) / 3;

	Cart *first_item = get_cart(&length, argv);
	float avg_sales = get_avg_sales(&length, first_item);

	update_status(&avg_sales, first_item);
	print_cart(first_item);

	return 0;
}

/*Function grabs items from command line and stores them
in our linked list and returns the head of that list*/
Cart *get_cart(int *length, char *argv[])
{
	Cart *first_item, *curr_item;
	first_item = new_item();
	curr_item = first_item;

	int count = 0;
	for (int i = 0; i < *length; ++i)
	{
		strcpy(curr_item->code, argv[++count]);
		curr_item->price = atof(argv[++count]);
		curr_item->sold = atoi(argv[++count]);

		if (*length - 1 <= i)
		{
			curr_item->next = NULL;
		}
		else
		{
			curr_item->next = new_item();
			curr_item = curr_item->next;
		}
	}
	return first_item;
}

/*Helper function to allocate a new node*/
Cart *new_item()
{
	Cart *new_item = (Cart *)calloc(1, sizeof(Cart));
	if (!new_item)
	{
		printf("Error allocating memory!\n");
		exit(0);
	}
	return new_item;
}

/*This function returns the floating point average of
the sales*/
float get_avg_sales(int *length, Cart *first_item)
{
	float sum = 0;
	Cart *curr_item = first_item;
	while (curr_item)
	{
		sum += curr_item->price * curr_item->sold;
		curr_item = curr_item->next;
	}
	return (sum / *length);
}

/*This function updates the status of each item*/
void update_status(float *avg_sales, Cart *first_item)
{
	Cart *curr_item = first_item;
	while (curr_item)
	{
		if (curr_item->price * curr_item->sold >= *avg_sales)
		{
			curr_item->status = 1;
		}
		else
		{
			curr_item->status = 0;
		}
		curr_item = curr_item->next;
	}
}

/*This function prints the status and country of origin
of each item in the cart*/
void print_cart(Cart *first_item)
{
	Cart *curr_item = first_item;
	while (curr_item)
	{
		printf("%d\n", curr_item->status);
		printf("%s\n", get_country(curr_item->code));
		curr_item = curr_item->next;
	}
}

/*This function takes the country code as an arg
and returns the country associated with it*/
const char *get_country(char *country_code)
{
	char code[3];
	strcpy(code, memcpy(code, country_code, 2));
	if (strcmp(code, "IE") == 0)
	{
		return "Ireland";
	}
	else if (strcmp(code, "FR") == 0)
	{
		return "France";
	}
	else if (strcmp(code, "SP") == 0)
	{
		return "Spain";
	}
	else if (strcmp(code, "US") == 0)
	{
		return "USA";
	}
	else
	{
		return "Russia";
	}
}