/*
Program: ex3-product.c
Author: Jamie Gorman
Date: 30/11/22
Input: information on products
Output: list the same products but increase irish products prices by 20%
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
    char code[50];
    char country[50];
    int price;
    Node *next;
};

/* Function prototypeS */
Node *new_node(void);
Node *get_nodes(int *length, char *argv[]);
Node *update_price(Node *head);
void print_nodes(Node *head);

/* Main driver function */
int main(int argc, char *argv[])
{
    int length = (argc - 1) / 3;
    Node *head = get_nodes(&length, argv);
    head = update_price(head);
    print_nodes(head);
    return 0;
}

/*Function creates a new linked list*/
Node *get_nodes(int *length, char *argv[])
{
    Node *head, *current;
    head = new_node();
    current = head;
    int count = 0;
    for (int i = 0; i < *length; ++i)
    {
        current->next = new_node();

        strcpy(current->code, argv[++count]);
        strcpy(current->country, argv[++count]);
        current->price = atoi(argv[++count]);

        current = current->next;
    }
    current->next = NULL;
    return head;
}

/*Function returns a new node*/
Node *new_node()
{
    Node *new = (Node *)calloc(1, sizeof(Node));
    if (!new)
    {
        printf("Error allocating memory!\n");
        exit(0);
    }
    return new;
}

/*Function updates price by 20% if Ireland*/
Node *update_price(Node *head)
{
    Node *current;
    current = head;
    while (current->next)
    {
        if (strcmp(current->country, "Ireland") == 0)
        {
            current->price = current->price * 1.2;
        }
        current = current->next;
    }
    return head;
}

/* Function prints all nodes in the linked list*/
void print_nodes(Node *head)
{
    Node *current;
    current = head;
    while (current->next)
    {
        printf("%s\n", current->code);
        printf("%s\n", current->country);
        printf("%d\n", current->price);
        current = current->next;
    }
}
