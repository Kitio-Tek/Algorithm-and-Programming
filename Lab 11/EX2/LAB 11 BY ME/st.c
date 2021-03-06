#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "st.h"

struct STnode{
Item *item;
link *next;
};

struct symboltable{
link **heads;
int M;
link *z;
};

link *NEW(Item *item, link *next){
link *x=malloc(sizeof(link));
x->item=item;
x->next=next;
return x;
}

ST *STinit(int maxN){
int i;
ST *st=malloc(sizeof(ST));
st->M=maxN;

st->heads=malloc(st->M*sizeof(link));
st->z=NEW(ITEMsetvoid(),NULL);

for(i=0;i<st->M;i++)
    st->heads[i]=st->z;

return st;
}

int hash(Key *v, int M) {
  int h = 0, base = 127;

  for ( ; *v != '\0'; v++)
    h = (base * h + *v) % M;

  return h;
}

int hashU(Key *v, int M) {
  int h, a = 31415, b = 27183;

  for ( h = 0; *v != '\0'; v++, a = a*b % (M-1))
    h = (a*h + *v) % M;

  return h;}

void STinsert (ST *st, Item *item) {
  int i;

  i = hash (KEYget(item), st->M);
 // fprintf (stdout, "hash index = %d\n", i);
  st->heads[i] = NEW (item, st->heads[i]);
  return;
}

Item *searchST (link *t, Key *k, link *z) {
  if (t == z)
    return ITEMsetvoid();

  if ((KEYcompare(KEYget(t->item), k))==0)
    return t->item;

  return (searchST(t->next, k, z));
}

Item *STsearch(ST *st, Key *k) {
  return searchST(st->heads[hash(k, st->M)], k, st->z);
}

link *deleteR(link *x, Key *k) {
  if ( x == NULL )
    return NULL;

  if ((KEYcompare(KEYget(x->item), k))==0) {
    link *t = x->next;
    free(x);
    return t;
  }

  x->next = deleteR(x->next, k);

  return x;
}

void STdelete(ST *st, Key *k) {
  int i = hash(k, st->M);
  st->heads[i] = deleteR(st->heads[i], k);

  return;
}

void visitR(link *h, link *z) {
  if (h == z)
    return;

  ITEMshow(h->item);
  visitR(h->next, z);

  return;
}

void STdisplay(ST *st)  {
  int i;

  for (i=0; i<st->M; i++) {
    fprintf (stdout, "st->heads[%d]: ", i);
    visitR(st->heads[i], st->z);
    fprintf (stdout, "\n");
  }

  return;
}

int STgetSize(ST *st){
  return st->M;
}

link *STgetByIndex(ST *st,int i){
  return st->heads[i];
}

void writeItemR(FILE *fp,link *h,link *z){
  if(h==z) return;

   if(!ITEMcheckvoid(h->item)){
    //ITEMshow(h->item);
    ITEMwrite(fp,h->item);
    writeItemR(fp,h->next,z);
   }

return;
}

link **listUnique (ST *st){
  link *l;
  int i ,k=0;
  link **list = malloc (STgetSize(st) * sizeof (link));
  for (i=0; i < STgetSize(st); i++)
      list[i] = st->z;

  for(i=0;i< STgetSize(st);i++){
    l=st->heads[i];
     if(!ITEMcheckvoid(l->item)){
        while(l!=st->z){
          list[k++]=l;
          l=l->next;
         }
      }
  }
  //printf("k=%d\n",k);
  return list;
}

Item *STgetItem(link **list,int i){
  return list[i]->item;
}
Item *STgetItemlink(link *l){
  return l->item;
}














