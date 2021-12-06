#include <stdio.h>
#include <stdlib.h>
#define DIM 20

int main()
{ int N1,N2,i,j,counter;

   printf("Please insert size of array N1:");
   scanf("%d",&N1);

   int v1[DIM];
   float v2[DIM]={0};

    printf("Please insert constant N2:");
    scanf("%d",&N2);

    if(N2>DIM || N1>DIM)
      fprintf(stderr,"N1 or N2 greater than limit");

      printf("Please insert value of array:\n");
      for(i=0;i<N1;i++)
        scanf("%d",&v1[i]);

      for(i=0;i<N1;i++){
        counter=0;
        if((i>N2)&&(i+N2<N1)){
        for(j=i-N2;j<=(i+N2);j++){
            v2[i]+=v1[j];
            counter++;}
            v2[i]=v2[i]*1.0/counter;
        }

        else if((i>N2)&&(i+N2>=N1)){
        for(j=i-N2;j<N1;j++){
            v2[i]+=v1[j];
            counter++;}
            v2[i]=v2[i]*1.0/counter;
        }

        else if((i<=N2)&&(i+N2<N1)){
        for(j=0;j<=i+N2;j++){
            v2[i]+=v1[j];
            counter++;}
            v2[i]=v2[i]*1.0/counter;
        }

        else if((i<=N2)&&(i+N2>=N1)){
        for(j=0;j<=N1;j++){
            v2[i]+=v1[j];
            counter++;}
            v2[i]=v2[i]*1.0/counter;
        }
      }
    for(i=0;i<N1;i++)
        printf("%.2f\t",v2[i]);
    return 0;
}
