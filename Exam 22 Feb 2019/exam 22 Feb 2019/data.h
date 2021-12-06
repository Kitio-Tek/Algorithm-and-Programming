#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXC 100

typedef struct data_s data_t;



data_t *readData(FILE *fp,data_t *data);
char *get_museum(data_t *data);
int get_day(data_t *data);
char *get_time(data_t *data);
int get_person(data_t *data);
char *get_client(data_t *data);

#endif // DATA_H_INCLUDED
