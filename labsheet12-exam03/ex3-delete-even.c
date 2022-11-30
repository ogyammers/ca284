/*
Program: ex3-delete-even.c
Author: Jamie Gorman
Date: 30/11/22
Input: n integers
Output: list all the odd numbers in an array
Approach: Create linked list
    step through it and delete nodes that contain even elements
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
    Node *next, *prev;
};

/* Function prototypeS */
Node *new_node(void);
Node *get_nodes(int *length, char *argv[]);
void print_nodes(int *length, Node *head);
Node *delete_even(Node *head);

/* Main driver function */
int main(int argc, char *argv[])
{
    int length = argc - 1;

    Node *head = get_nodes(&length, argv);
    head = delete_even(head);
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
        current->value = atoi(argv[i + 1]);

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

/* Function prints all nodes in the linked list and their sum*/
void print_nodes(int *length, Node *head)
{
    Node *current;
    current = head;
    int sum = current->value;
    while (current->next)
    {
        printf("%d\n", current->value);
        current = current->next;
        sum += current->value;
    }
    printf("%d\n", sum);
}

/*Function deletes all even nodes from linked list*/
Node *delete_even(Node *head)
{
    Node *current, *prev, *tmp;
    current = head;
    while (current->next)
    {
        if (current->value % 2 == 0)
        {
            if (current == head)
            {
                head = current->next;
                head->prev = NULL;
                current = head;
            }
            else if (current->next == NULL)
            {
                current->prev->next = NULL;
                current = NULL;
            }
            else
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                tmp = current->prev;
                free(current);
                current = tmp;
            }
        }
        else
        {
            current = current->next;
        }
    }
    return head;
}