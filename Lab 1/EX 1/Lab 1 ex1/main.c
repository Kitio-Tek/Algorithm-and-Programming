#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#define DIM 10

int main()
{ int previous_len=0,start=0,len=0;
  int array[DIM], i;

  printf("Enter the sequence of numbers\n");
  for(i=0;i<DIM;i++)
    scanf("%d",&array[i]);
    printf("\n");

  for(i=0;i<DIM;i++){
    if(array[i+1]>array[i]){
        len++;
        if(len>previous_len){
            previous_len=len;
            start=i+1-len;
        }
    }
    else
        len=0;
  }

   printf("The Longest continuous sequence is...\n");
  for(i=start;i<=start+previous_len;i++)
    printf("%d\t",array[i]);

    return 0;
}
