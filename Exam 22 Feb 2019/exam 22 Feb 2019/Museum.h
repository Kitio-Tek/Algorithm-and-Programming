#ifndef MUSEUM_H_INCLUDED
#define MUSEUM_H_INCLUDED
#define MAX_DAY 365
#define MAX_MS 9+3

#include "data.h"

typedef struct timeslot_s timeslot_t;




typedef struct museum_s museum_t;



museum_t *loadFile(FILE *fp,museum_t *ms);
void file_check(FILE *);
timeslot_t *loadFile_timeslot(FILE *fp,timeslot_t *tmp,int n);
int check_museum(museum_t *ms,data_t *data);
int check_slot(timeslot_t *tmp,data_t *data,int n);

#endif // MUSEUM_H_INCLUDED
