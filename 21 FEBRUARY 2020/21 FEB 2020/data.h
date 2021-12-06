#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXC 50



typedef struct item{
char *product;
int weight,value,availability;
}Item;

int compareValue(Item s1,Item s2);
int product(Item data);
void print_Sol(Item data);

#endif // DATA_H_INCLUDED
