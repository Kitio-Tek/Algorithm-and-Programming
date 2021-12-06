#include "queue.h"

struct queue{
Item *A;
int heapsize;
};
int k=-1;
queue_t *loadFile(FILE *fp){
char product[MAXC];
int weight=0,value=0,availability=0;
Item data;

queue_t *pq=QueueInit();


fscanf(fp,"%d",&pq->heapsize);
pq->A=malloc((pq->heapsize)*sizeof(Item));

while(fscanf(fp,"%s %d %d %d",product,&weight,&value,&availability)!=EOF  ){
 data.product=strdup(product);
 data.weight=weight;
 data.value=value;
 data.availability=availability;

 pq=PQinsert(pq,data);
}


return pq;
}

queue_t *PQinsert(queue_t *pq,Item data){

     k=k+1;
    while((k>=1 )&& compareValue(pq->A[PARENT(k)],data)<0){
     pq->A[k]=pq->A[PARENT(k)];
     k=(k-1)/2;
    }
    pq->A[k]=data;

    return pq; }

int bestSolutions(queue_t *pq, int n){
int sum=0;
Item data;


while(sum<=n && pq->heapsize>0){
    data=PQextractMax(pq);
    if(sum+product(data)<=n)
    { sum=sum+product(data);
      print_Sol(data);
    }


}
 if(sum==0)
    return 0;
 else
    return 1;

}
Item PQextractMax(queue_t *pq){
Item data;

swap(pq,0,pq->heapsize-1);
data=pq->A[pq->heapsize-1];
pq->heapsize--;
HEAPIFY(pq,0);

return data;
}
void swap(queue_t *pq,int i,int j){
Item data;
data=pq->A[i];
pq->A[i]=pq->A[j];
pq->A[j]=data;
}

void HEAPIFY(queue_t *pq,int i){
int l,largest,r;
l=LEFT(i);
r=RIGHT(i);
 if(l<pq->heapsize && compareValue(pq->A[i],pq->A[l])<0)
    largest=l;
 else
    largest=i;
 if(r<pq->heapsize && compareValue(pq->A[largest],pq->A[r])<0)
    largest=r;
 if(largest!=i){
   swap(pq,i,largest);
   HEAPIFY(pq,largest);
 }
}
int PARENT(int i){
return ((i-1)/2);
}
int LEFT(int i){
return ((2*i)+1);
}
int RIGHT(int i){
return ((2*i)+2);
}

queue_t *QueueInit(){
  queue_t *pq=malloc(sizeof(queue_t));

  return pq;
}

 void file_check(FILE *fp)
{
    if(fp==NULL)
    {
        fprintf(stderr,"File loading error\n");
        exit(EXIT_FAILURE);
    }
}
        /*void printpq(queue_t *pq){
            int m;
         for(m=0;m<pq->heapsize;m++){
            printf("%s %d %d %d\n",pq->A[m].product,pq->A[m].weight,pq->A[m].value,pq->A[m].availability);
             printf("\t");

         }

        }*/
