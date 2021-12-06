#include <stdio.h>
#include <stdlib.h>
void cover_recur(int *l,int *sol,int n,int k,int pos, int current,int d);
void cover(int *l, int n,int d);
int main()
{ int l[]={2,6}, n=2;
  int d=10;


    cover(l,n,d);
    return 0;
}
void cover(int *l, int n,int d){
int *sol=malloc(sizeof(int));


cover_recur(l,sol,n,1,0,0,d);
}

void cover_recur(int *l,int *sol,int n,int k,int pos, int current,int d){


  if(current>=d){
    if(current==d){
        printf("SEQUENCE FOUND\n");
        for(int j=0;j<pos;j++)
            printf("%d",sol[j]);
            printf("\n");
        }

        return ;
  }
    for(int i=0;i<n;i++){
        sol=realloc(sol,k);
            sol[pos]=l[i];

               //printf("%d\n",l[i]);
               cover_recur(l,sol,n,k+1,pos+1,current+sol[pos],d);

       }


}
