#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "data.h"


typedef struct queue queue_t;
void printpq(queue_t *pq);

void HEAPIFY(queue_t *pq,int i);
queue_t *loadFile(FILE *fp);
queue_t *QueueInit();
int PARENT(int i);
int LEFT(int i);
int RIGHT(int i);
Item PQextractMax(queue_t *pq);
void swap(queue_t *pq,int i,int j);
queue_t *PQinsert(queue_t *pq,Item data);
void file_check(FILE *fp);

int bestSolutions(queue_t *pq, int n);




#endif // QUEUE_H_INCLUDED
