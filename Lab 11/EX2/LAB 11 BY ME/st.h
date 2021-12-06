#ifndef ST_H_INCLUDED
#define ST_H_INCLUDED


#include "item.h"

typedef struct symboltable ST;
typedef struct STnode link;

link *NEW(Item *item, link *next);
ST *STinit(int);
void STinsert(ST *, Item *);
Item *STsearch(ST *, Key *);
void STdelete(ST *,Key *);
void STdisplay(ST *);

int STgetSize(ST *);
link *STgetByIndex(ST *st,int i);
void writeItemR(FILE *fp,link *h,link *z);
link **listUnique(ST *st);
Item *STgetItem(link **list, int i);
Item *STgetItemlink(link *l);


#endif // ST_H_INCLUDED
