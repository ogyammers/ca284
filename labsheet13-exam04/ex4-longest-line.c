/*
Program: ex4-longest-line.c
Author:Jamie Gorman
Date: 13/12/22
Input: a paragraph and an argument of either shortest or longest
Output: the shortest or longest line in the paragraph
Approach: 
	Split the paragraph on '.' and '?' but if inbetween single quatations
	Allocate each sentence to a node
	Iterate through nodes and find the shortest or longest
*/

/*Includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Type definitions*/
typedef struct Sentence Sentence;

/*Structure definitions*/
struct Sentence
{
	char words[200];
	Sentence *next;
};

/*Function prototypes*/
Sentence *get_paragraph(char *argv);
Sentence *new_sentence();

void longest(Sentence *first, char *sentence);
void shortest(Sentence *first, char *sentence);
void check_indicater(char *indicator, Sentence *first, char *sentence);
void indicated_func(void (*pfun)(Sentence *, char *), Sentence *first, char *sentence);
void print_sentence(char *sentence);

/*Main driver function*/
int main(int argc, char *argv[])
{
	char indicator[strlen(argv[2])];
	strcpy(indicator, argv[2]);

	char *sentence = (char *)calloc(200, sizeof(char));
	if (!sentence)
	{
		printf("Error allocating memory!");
		exit(0);
	}

	Sentence *first = get_paragraph(argv[1]);
	check_indicater(indicator, first, sentence);

	return 0;
}

/*This function splits the paragraph on '.' and '?'
but only if they are not located between single
quotation marks(this solution is linear search and we use ascii 39
to escape the single quatation when checking chars)
each sentence becomes a node in a linked list
we return the head of the list*/
Sentence *get_paragraph(char *argv)
{
	Sentence *curr, *first;
	first = new_sentence();
	curr = first;
	int i = 0;
	int j = i;
	while (argv[i])
	{
		if (argv[i] == 39)
		{
			i += 1;
			while (argv[i] != 39)
			{
				i += 1;
			}
		}

		else if (argv[i] == '.' || argv[i] == '?')
		{
			i += 1;
			strncpy(curr->words, argv + j, i - j);

			if (i < strlen(argv))
			{
				curr->next = new_sentence();
				curr = curr->next;
			}
			else
			{
				curr->next = NULL;
			}

			j = i + 1;
		}
		i += 1;
	}

	return first;
}

/*Helper function to allocate new node*/
Sentence *new_sentence()
{
	Sentence *new = (Sentence *)calloc(1, sizeof(Sentence));
	if (!new)
	{
		printf("Error allocating memory!");
		exit(0);
	}

	return new;
}

/*This function finds the longest sentence and drives the print function*/
void longest(Sentence *first, char *sentence)
{
	int longest_len = 0;

	Sentence *curr;
	curr = first;

	while (curr)
	{
		if (strlen(curr->words) > longest_len)
		{
			longest_len = strlen(curr->words);
			strcpy(sentence, curr->words);
		}
		curr = curr->next;
	}

	print_sentence(sentence);
}

/*This function finds the shortest sentence and drives the print function*/
void shortest(Sentence *first, char *sentence)
{
	int shortest_len = strlen(first->words);
	strcpy(sentence, first->words);

	Sentence *curr;
	curr = first;

	while (curr)
	{
		if (strlen(curr->words) < shortest_len && strlen(curr->words) != 0)
		{
			shortest_len = strlen(curr->words);
			strcpy(sentence, curr->words);
		}
		curr = curr->next;
	}

	print_sentence(sentence);
}

/*This function checks what the indicator is and passes a pointer
to the correct function or prints not valid!*/
void check_indicater(char *indicator, Sentence *first, char *sentence)
{
	void (*pf)(Sentence *, char *) = NULL;

	if (strcmp(indicator, "longest") == 0)
	{
		pf = longest;
		indicated_func(pf, first, sentence);
	}

	else if (strcmp(indicator, "shortest") == 0)
	{
		pf = shortest;
		indicated_func(pf, first, sentence);
	}

	else
	{
		printf("Not valid!\n");
		exit(0);
	}
}

/*This function calls the function being passed to it*/
void indicated_func(void (*pfun)(Sentence *, char *), Sentence *first, char *sentence)
{
	pfun(first, sentence);
}

/*This function prints the length and the sentence itself*/
void print_sentence(char *sentence)
{
	printf("%ld\n%s\n", strlen(sentence), sentence);
}