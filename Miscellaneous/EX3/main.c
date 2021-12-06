#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void circularPermutation(char *str);
void permutate(char *str,char *sol,int position,int *mark,int n);
int main()
{ char str[MAX];
  printf("Enter a word\n");
  scanf("%s",str);

  circularPermutation(str);



    return 0;
}
void circularPermutation(char *str){

char *sol=malloc((strlen(str)+1)*sizeof(char));
int *mark=calloc(strlen(str),sizeof(int));
sol[0]=str[0];
mark[0]=1;

printf("The Circular Permutations are:\n");
permutate(str,sol,1,mark,strlen(str));

free(sol);
free(mark);
return;
}
void permutate(char *str,char *sol,int position,int *mark,int n){
if(position>=n){
    sol[n]='\0';
    printf("%s",sol);
    printf("\n");
    return;
}


 for(int i=1;i<n;i++){
    if(mark[i]==0){
        mark[i]=1;
        sol[position]=str[i];
        permutate(str,sol,position+1,mark,n);
        mark[i]=0; //backtrack
    }
 }


return;
}

