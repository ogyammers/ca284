/*
Program: lab9-student.c
Author: Jamie Gorman
Date: 11/11/22
Input: array of students from command line
Output: print the students
*/

/* Includes */
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*Type defintions*/
typedef struct Student Student;

/*Stucture defintions*/
struct Student
{
    char name[20];
    char programme[20];
    float grade;
};

/*Function prototypes*/
void get_students(int *length, char *argv[], Student *students);
void print_students(int *length, Student *students);

/*Main driver function*/
int main(int argc, char *argv[])
{
    int length = 2;
    Student *students = (Student *)calloc(length, sizeof(Student));
    if (!students)
    {
        printf("Error allocating memory\n");
        exit(0);
    }
    get_students(&length, argv, students);

    length = argc / 3;

    Student *tmp = (Student *)realloc(students, length * sizeof(Student));
    if (!tmp)
    {
        printf("Error allocating memory\n");
        free(students);
        students = NULL;
        exit(0);
    }

    students = tmp;

    get_students(&length, argv, students);
    print_students(&length, students);

    free(students);
    students = NULL;
    return 0;
}

void get_students(int *length, char *argv[], Student *students)
{
    int count;
    int i;
    if (*length == 2)
    {
        i = 0;
        count = 0;
    }
    else
    {
        i = 2;
        count = i * 3;
    }
    for (; i < *length; ++i)
    {
        Student *cptr = &students[i];
        strcpy(cptr->name, argv[count + 1]);
        strcpy(cptr->programme, argv[count + 2]);
        cptr->grade = atof(argv[count + 3]);
        count += 3;
    }
}

void print_students(int *length, Student *students)
{
    for (int i = 0; i < *length; ++i)
    {
        Student *cptr = &students[i];
        printf("%s, %s, %.2f\n", cptr->name, cptr->programme, cptr->grade);
    }
}