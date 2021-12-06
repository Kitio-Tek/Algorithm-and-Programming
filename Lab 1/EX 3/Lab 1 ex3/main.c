#include <stdio.h>
#include <stdlib.h>
#define R 2
#define C 2

int main()
{ int i,m1[R][C],m2[R][C];
  int fact=1,j,m=1;

  printf("Enter the integer values into m1 array:");
   for(i=0;i<R;i++){
        for(j=0;j<C;j++){
        scanf("%d",&m1[i][j]);

        }
        printf("\n");  }

   for(i=0;i<R;i++)
    for(j=0;j<C;j++)
   {  if(m1[i][j]==0)
       m2[i][j]=0;

      else if(m1[i][j]<0){
        for(m=1;m<=-m1[i][j];m++){
            fact=fact*m;
        } m2[i][j]=fact;
          fact=1;
      }
      else if(m1[i][j]>0){

        while(m1[i][j]%10!=0)
            m1[i][j]++;

        m2[i][j]=m1[i][j];

      }

   }
    printf("The modified matrix is....\n");
   for(i=0;i<R;i++){
        for(j=0;j<C;j++)
         printf("%d\t",m2[i][j]);

        printf("\n");

        }

    return 0;
}
