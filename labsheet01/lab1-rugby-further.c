#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int get_score();


int main(int argc, char*argv[])
{
    int try, conv, pen, drop, total_score;

    try = get_score("Number of trys: ");
    conv = get_score("Number of conversions: ");
    pen = get_score("Number of penaltys: ");
    drop = get_score("Number of drop-goals: ");

    total_score = try * 5 + conv * 2 + pen * 3 + drop * 3;

    printf("%d\n", total_score);

    return 0;
}


int get_score(char*score_type)
{
    printf("%s", score_type);
    int score = 0;
    scanf("%d", &score);
    
    while (score < 0)
    {
        printf("Try again, must be a positive number\n%s", score_type);
        scanf("%d", &score);
    }

    return score;
}