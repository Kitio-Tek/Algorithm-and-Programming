#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX1 15
#define MAX2 20

void occurrence(FILE *fp1, char str2[][MAX2+1],int counter[]);

int main(int argc, char *argv[])
{ FILE *fp1,*fp2;
  int counter[MAX1]={0},i,j;
  char str2[MAX1][MAX2+1];

  if(argc!=3)
    printf("Wrong number of arguments\n");
  else{
        fp2=fopen(argv[2],"r");

  for(i=0;i<MAX1;i++)
  { fscanf(fp2,"%s",str2[i]);
    j=0;
    while(j<MAX2+1)
    {
        str2[i][j]=tolower(str2[i][j]);
        j++;
    }
  }
    fclose(fp2);
    fp1=fopen(argv[1],"r");
    occurrence(fp1,str2,counter);
    fclose(fp1);

    for(i=0;i<MAX1;i++){
            printf("%s-%d occurence(s):\n",str2[i],counter[i]);

    }


  }


    return 0;
}

 void occurrence(FILE *fp1, char str2[][MAX2+1],int counter[])
 {
     char string[MAX1+1];
     int i,j;

     for(i=0;i<MAX1;i++)
     {   rewind(fp1);
         while(fscanf(fp1,"%s",string)!=EOF){
            for(j=0;j<strlen(string);j++)
                string[j]=tolower(string[j]);
            if(strcmp(string,str2[i])==0)
                counter[i]++;
         }
     }
 }
