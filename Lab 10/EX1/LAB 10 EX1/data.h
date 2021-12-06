#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXC 60
typedef struct student{
char *firstname;
char *lastname;
char *date;
char *course;
int year,code;
}Student;

int compareStudent(Student, Student);
int compareIDStudent(Student, Student);
int compare(Student, char*,char*);






#endif // DATA_H_INCLUDED
