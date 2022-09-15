#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
    int try, conv, pen, drop, total_score;
    try = atoi(argv[1]);
    conv = atoi(argv[2]);
    pen = atoi(argv[3]);
    drop = atoi(argv[4]);

    total_score = try * 5 + conv * 2 + pen * 3 + drop * 3;

    printf("%d\n", total_score);


    return 0;
}