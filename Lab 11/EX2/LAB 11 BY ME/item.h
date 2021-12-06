#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include <stdio.h>
#define MAXST 10
#define MAXC 100

typedef struct item Item;
typedef char Key;

Item *ITEMscan(FILE *fp);
void ITEMshow(Item *data);
int ITEMcheckvoid(Item *data);
Item *ITEMsetvoid();

int KEYcompare(Key *k1, Key *k2);
Key *KEYget(Item *data);
void ITEMwrite(FILE *, Item *);



#endif // ITEM_H_INCLUDED
