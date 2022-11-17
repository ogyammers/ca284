/*
Program: lab10-integer-singly-linked-list.c
Author: Jamie Gorman
Date: 17/11/22
Input: n integers
Output: singly linked list implementation
*/

/* Includes */
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Type definitions */
typedef struct Node Node;

/* Stucture definitions */
struct Node
{
    float value;
    Node *next, *prev;
};

/* Function prototypeS */
Node *new_node(void);
Node *get_nodes(int *length, char *argv[]);
void print_nodes(int *length, Node *head);

/* Main driver function */
int main(int argc, char *argv[])
{
    int length = argc - 2;

    Node *head = get_nodes(&length, argv);
    print_nodes(&length, head);
    return 0;
}

/*Function creates a new linked list*/
Node *get_nodes(int *length, char *argv[])
{
    Node *head, *current, *prev;
    head = new_node();
    current = head;
    current->prev = NULL;
    for (int i = 0; i < *length; ++i)
    {
        prev = current;
        current->next = new_node();
        current->value = atof(argv[i + 2]);

        current = current->next;
        current->prev = prev;
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

/* Function prints all nodes in the linked list*/
void print_nodes(int *length, Node *head)
{
    Node *current;
    current = head;
    while (current->next)
    {
        // printf("%d\n", current->value);
        current = current->next;
    }

    while (current->prev)
    {
        current = current->prev;
        printf("%.2f\n", current->value);
    }
}