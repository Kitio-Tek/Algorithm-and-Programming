#include <stdio.h>
#include <stdlib.h>

int permutate(int pos, int *val, int *sol, int *mark, int n, int count);
int check(int **matrix, int dim);
int fill_matrix(int *sol, int n);
int **matrix;

int main()
{ int n=3, count=0;
 int *sol=calloc(n*n,sizeof(int));
 int *val=malloc(n*n*sizeof(int));
 int *mark=calloc(n*n,sizeof(int));

 for(int i=0;i<n*n;i++)
    val[i]=i+1;

 count=permutate(0,val,sol,mark,n,count);
 printf("\ncount=%d\nend\n",count);



    return 0;
}

int permutate(int pos, int *val, int *sol, int *mark, int n, int count){
int i,j,k=0;
if(pos>=n*n){
    if(fill_matrix(sol,n)==1){ /*If a Magic square has been found*/
        k=0;
 /*printing*/for(i=0;i<n;i++){
              for(j=0;j<n;j++){
                printf("%d",sol[k++]);
            }
            printf("\n");

        }
            printf("\n");
            return count+1;
    }
  return count;
}


//Permutate values
for(i=0;i<n*n;i++){
    if(mark[i]==0){
        mark[i]=1;
        sol[pos]=val[i];

        count=permutate(pos+1,val,sol,mark,n,count);

        mark[i]=0;
    }



}


return count;

}

int fill_matrix(int *sol, int n){
int pos=0,res=0;

matrix=malloc(n*sizeof(int*)); /*matrix creation to get permutated values*/
for(int i=0;i<n;i++)
    matrix[i]=calloc(n,sizeof(int));


for(int i=0;i<n;i++){  /*Insertion of the sequence of Permutated values into the matrix */
    for(int j=0;j<n;j++){
        matrix[i][j]=sol[pos++];
    }
}


res=check(matrix,n);  /*Sending the matrix to check if it is a Magic square*/

for(int i=0;i<n;i++)  /*Free back the created matrix*/
    free(matrix[i]);
    free(matrix);

return res;  /*Return the result of checking the matrix, 1 if magic square, 0 else*/
}


 int check(int **matrix, int dim){
 int i,j,sum,target;

 target=dim*(dim*dim+1)/2;

 /*rows*/
 for(i=0;i<dim;i++){
    sum=0;
    for(j=0;j<dim;j++){
        sum+=matrix[i][j];
    }
    if(sum!=target){
        return 0;
    }
 }

 /*columns*/
 for(j=0;j<dim;j++){
    sum=0;
    for(i=0;i<dim;i++){
        sum+=matrix[i][j];
    }
    if(sum!=target){
        return 0;
    }
 }

  /*diagonals*/

  /*from left to right*/
    sum=0;
    for(i=0;i<dim;i++){
        sum+=matrix[i][i];
    }
    if(sum!=target){
        return 0;
    }

  /*from right to left*/
    sum=0;
    for(i=0;i<dim;i++){
        sum+=matrix[i][dim-1-i];
    }
    if(sum!=target){
        return 0;
    }

  return 1;

 }
