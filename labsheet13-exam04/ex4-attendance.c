/*
Program: ex4-attendance.c
Author:Jamie Gorman
Date: 13/12/22
Input: n of attendance records for n students
Output: the attendance status of each student line by line
Approach:
	Create a structure which stores each students attenendance
	Create an array to store the attendance status of each student
	Update the element of the array associated with each student
		with a 1 or 0 according to the question guidelines
	Print the attendance status array line by line
*/

/*Includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Type definitions*/
typedef struct Record Record;

/*Structure definitions*/
struct Record
{
	char record[20];
};

/*Function prototypes*/
void get_attendance(char *argv[], Record *attendance);
void update_record(int *length, Record *attendance, int *abs_check);
void print_record(int *length, int *abs_check);

/*Main driver function*/
int main(int argc, char *argv[])
{
	int length = argc - 1;

	Record *attendance = calloc(length, sizeof(*attendance));
	int *abs_check = (int *)calloc(length, sizeof(int));
	if (!attendance || !abs_check)
	{
		printf("Error allocating memory!\n");
		exit(0);
	}

	get_attendance(argv, attendance);
	update_record(&length, attendance, abs_check);

	free(attendance);
	attendance = NULL;

	print_record(&length, abs_check);

	free(abs_check);
	abs_check = NULL;

	return 0;
}

/*This function gather data from the command line and store it
in the array of structures*/
void get_attendance(char *argv[], Record *attendance)
{
	int i = 0;
	Record *cptr;
	while (argv[i + 1])
	{
		cptr = &attendance[i];
		strcpy(cptr->record, argv[i + 1]);
		++i;
	}
}

/*This function processes each attendance record and keeps a tally of
the total absent counts, if the count for any particular student is
greater than or equal to 3 we set their status to 1, otherwise we set
their status to 0*/
void update_record(int *length, Record *attendance, int *abs_check)
{
	Record *cptr;
	int abs_count = 0;
	for (int i = 0; i < *length; ++i)
	{
		cptr = &attendance[i];
		abs_count = 0;

		for (int j = 0; j < strlen(cptr->record); ++j)
		{
			if (cptr->record[j] == 'A')
			{
				abs_count += 1;
			}
			else if (cptr->record[j] == 'L')
			{
				if (cptr->record[j + 1] == 'L' && cptr->record[j + 2] == 'L')
				{
					abs_count += 1;
					j = j + 2;
				}
			}
		}
		if (abs_count >= 3)
		{
			*(abs_check + i) = 1;
		}
		else
		{
			*(abs_check + i) = 0;
		}
	}
}

/*This function prints the status array line by line*/
void print_record(int *length, int *abs_check)
{
	for (int i = 0; i < *length; ++i)
	{
		printf("%d\n", *(abs_check + i));
	}
}