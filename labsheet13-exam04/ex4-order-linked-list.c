/*
Program: ex4-order-linked-list.c
Author: Jamie Gorman
Date: 13/12/22
Input: n floating point numbers from command line
Output: 1 or 0 if the list is in descending order or not
Approach:
	Grab the args from command line and store them in
		doubly linked list
	Iterate through the list and if we encounter an element that is larger
		than the previous element we immediately return 0 implying that the
		list is not in descending order
	If we manage to exit the loop without tripping the first return case then
		we will return 1 implying that our list is in descending order
*/

/*Includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Type definitions*/
typedef struct Node Node;

/*Structure definitions*/
struct Node
{
	float element;
	Node *next;
	Node *prev;
};

/*Function prototypes*/
Node *get_list(int *length, char *argv[]);
Node *new_node();
int check_order(Node *head, int status);

/*Main driver function*/
int main(int argc, char *argv[])
{
	int length = argc - 1;

	Node *head = get_list(&length, argv);

	int status = check_order(head, status);
	printf("%d\n", status);

	return 0;
}

Node *get_list(int *length, char *argv[])
{
	Node *head, *curr, *prev;
	head = new_node();
	head->prev = NULL;
	curr = head;
	for (int i = 0; i < *length; ++i)
	{
		curr->element = atof(argv[i + 1]);
		if (i >= *length - 1)
		{
			curr->next = NULL;
			curr->prev = prev;
		}
		else
		{
			curr->next = new_node();
			prev = curr;
			curr = curr->next;
			curr->prev = prev;
		}
	}
	return head;
}
Node *new_node()
{
	Node *node = (Node *)calloc(1, sizeof(Node));
	if (!node)
	{
		printf("Error allocating memory!");
		exit(0);
	}
	return node;
}

int check_order(Node *head, int status)
{
	Node *curr = head->next;

	while (curr)
	{
		if (curr->element > curr->prev->element)
		{
			return 0;
		}
		curr = curr->next;
	}

	return 1;
}