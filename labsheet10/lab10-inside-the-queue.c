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
    int value;
    Node *next, *prev;
};

/* Function prototypeS */
Node *new_node(void);
Node *get_nodes(int *length, int *arr);
void print_nodes(Node *head);
void pop(Node *head);
void push(Node *head, int *value);
void insert_node(Node *head, int *pos, int *val);

/* Main driver function */
int main(int argc, char *argv[])
{
    int pos = atoi(argv[1]);
    int val = atoi(argv[2]);

    int arr[] = {8, 7, 3, 4, 5, 6, 9, 2, 14, 12};
    int *ptr = arr;

    int length = sizeof(arr) / sizeof(arr[0]);

    Node *head = get_nodes(&length, ptr);

    insert_node(head, &pos, &val);

    print_nodes(head);

    return 0;
}

/*Function creates a new linked list*/
Node *get_nodes(int *length, int *arr)
{
    Node *head, *current, *prev;
    head = new_node();
    current = head;
    current->prev = NULL;
    for (int i = 0; i < *length; ++i)
    {
        prev = current;
        current->next = new_node();
        current->value = *(arr + i);

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
void print_nodes(Node *head)
{
    Node *current;
    current = head;
    while (current->next)
    {
        printf("%d\n", current->value);
        current = current->next;
    }

    // while (current->prev)
    // {
    //     current = current->prev;
    //     //printf("%.2f\n", current->value);
    // }
}

/*Function pops the last value of the linked list*/
void pop(Node *head)
{
    Node *current;
    current = head;
    while (current->next)
    {
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);
}

/*Function pushes the value to the end of the linked list*/
void push(Node *head, int *value)
{
    Node *current, *prev;
    current = head;
    while (current->next)
    {
        current = current->next;
    }
    prev = current;

    current->next = new_node();
    current->value = *value;

    current = current->next;
    current->prev = prev;
}

/*Function finds a node and inserts a new value after it*/
void insert_node(Node *head, int *pos, int *val)
{
    Node *current, *tmp;
    current = head;
    while (current->value != *pos)
    {
        current = current->next;
    }
    tmp = current->next;
    current->next = new_node();
    current = current->next;
    current->value = *val;
    current->next = tmp;
}