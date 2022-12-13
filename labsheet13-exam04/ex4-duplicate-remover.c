/*
Program: ex4-duplicate-remover.c
Author:Jamie Gorman
Date: 13/12/22
Input: n number of integers
Output: remove all the duplicate numbers
Approach:
	Gather all the elements from command line and store them in array
	Sort all elements that are not duplicates to the beggining of the array
	Length of array after removal of dups will be the number of non duplicate elements
*/

/*Includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Function prototypes*/
void get_arr(int *length, char *argv[], int *arr);
void remove_dups(int *length, int *arr);
void swap_elements(int *a, int *b);
void print_array(int *length, int *arr);

/*Main driver function*/
int main(int argc, char *argv[])
{
	int length = argc - 1;
	int *arr = (int *)calloc(length, sizeof(int));
	if (!arr)
	{
		printf("Error allocating memory!\n");
		exit(0);
	}

	get_arr(&length, argv, arr);
	remove_dups(&length, arr);
	print_array(&length, arr);
	return 0;
}

/*Function stores elements in array*/
void get_arr(int *length, char *argv[], int *arr)
{
	for (int i = 0; i < *length; ++i)
	{
		*(arr + i) = atoi(argv[i + 1]);
		// printf("%d\n", *(arr + i));
	}
}

/*Function removes any duplicate values by swapping dupes
to the end of the array and reducing the array size*/
void remove_dups(int *length, int *arr)
{
	int new_length = 0;
	int count = 0;
	for (int i = 0; i < *length; ++i)
	{
		count = 0;
		for (int j = 0; j < *length; ++j)
		{
			if (*(arr + i) == *(arr + j))
			{
				count++;
			}
		}
		if (count == 1)
		{
			swap_elements(arr + new_length, arr + i);
			new_length++;
		}
	}
	/*all dupes are at the end of the array and are now
	removed by reducing the arrays length*/
	*length = new_length;
}

/*Helper function to swap elements*/
void swap_elements(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/*This function prints our array with its new shortened length*/
void print_array(int *length, int *arr)
{
	for (int i = 0; i < *length; ++i)
	{
		printf("%d\n", *(arr + i));
	}
}