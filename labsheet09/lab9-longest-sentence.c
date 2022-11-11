/*
Program: lab9-longest-sentence.c
Author: Jamie Gorman
Date: 11/11/22
Input: a sentence from command line
Output: print the longest words
*/

/* Includes */
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*Type defintions*/
typedef struct Sentence Sentence;

/*Structure definitions*/
struct Sentence
{
    char word[20];
};

/*Function prototypes*/
void get_words(int *length, char *argv[], Sentence *my_words);
void print_longest(int *longest, int *length, Sentence *my_words);

/*Main driver function*/
int main(int argc, char *argv[])
{
    int length = argc - 1;

    Sentence *my_words = malloc(length * sizeof(*my_words));
    if (!my_words)
    {
        printf("Error allocating memory!\n");
        exit(0);
    }
    get_words(&length, argv, my_words);
    free(my_words);
    return 0;
}

void get_words(int *length, char *argv[], Sentence *my_words)
{
    int longest = 0;
    for (int i = 0; i < *length; ++i)
    {
        Sentence *cptr = &my_words[i];
        strcpy(cptr->word, argv[i + 1]);
        if (strlen(cptr->word) > longest)
        {
            longest = strlen(cptr->word);
        }
    }
    print_longest(&longest, length, my_words);
}

void print_longest(int *longest, int *length, Sentence *my_words)
{
    for (int i = 0; i < *length; ++i)
    {
        Sentence *cptr = &my_words[i];
        if (strlen(cptr->word) == *longest)
        {
            printf("%s\n", cptr->word);
        }
    }
}
