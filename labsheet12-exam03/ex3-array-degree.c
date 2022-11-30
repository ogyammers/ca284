/*
Program: ex3-array-degree.c
Author: Jamie Gorman
Date: 30/11/22
Input: n integers
Output: find the degree of the integers
Approach: grab integers from command line
	make linked list
	keep a rolling count of the most viewed element
*/

/* Includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Type definitions */
typedef struct Node Node;

/* Stucture definitions */
struct Node
{
	int value;
	Node *next;
};

/* Function prototypes */
Node *new_node(void);
Node *get_nodes(int *length, char *argv[]);
int get_degree(int *length, Node *head);

/* Main driver function */
int main(int argc, char *argv[])
{
	int length = argc - 1;

	Node *head = get_nodes(&length, argv);
	int degree = get_degree(&length, head);
	printf("%d\n", degree);
	return 0;
}

/*Function creates a new linked list*/
Node *get_nodes(int *length, char *argv[])
{
	Node *head, *current;
	head = new_node();
	current = head;
	for (int i = 0; i < *length; ++i)
	{
		current->next = new_node();
		current->value = atoi(argv[i + 1]);

		current = current->next;
	}
	current->next = NULL;
	return head;
}

/*Function returns a new node*/
Node *new_node()
{
	Node *new = (Node *)calloc(1, sizeof(Node *));
	if (!new)
	{
		printf("Error allocating memory!\n");
		exit(0);
	}
	return new;
}

/* Function returns the degree of the linked list*/
int get_degree(int *length, Node *head)
{
	Node *current, *inner_current;
	current = head;
	int degree = 0, count = 0;
	while (current->next)
	{
		inner_current = head;
		count = 0;
		while (inner_current->next)
		{
			if (current->value == inner_current->value)
			{
				count += 1;
			}
			inner_current = inner_current->next;
		}
		if (count > degree)
		{
			degree = count;
		}
		current = current->next;
	}
	return degree;
}