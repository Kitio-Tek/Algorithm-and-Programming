#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX1 100

 int searchh(FILE *fp1);
 int searchv(FILE *fp1);
 int main(int argc, char *argv[])
{ FILE *fp1;
  int h,v;

  fp1=fopen(argv[1],"r");
  if(fp1==NULL)
    printf("Error in the file");
  else{
   h=searchh(fp1);
   rewind(fp1);
   v=searchv(fp1);
   printf("Horizontal Sequence:%d\n",h);
   printf("Vertical Sequence:%d\n",v);

    }

    fclose(fp1);

    return 0; }
int searchh(FILE *fp1){

char *ptr;
int h=0;
char string[MAX1+1];


    while(fscanf(fp1,"%s",string)!=EOF){
        ptr=strstr(string,"hhhhh");
        if(ptr!=NULL)
            h++;
    }


return h;
}

int searchv(FILE *fp1){
int v[MAX1+1]={0},counter=0,i;
char line[MAX1+1];
while(fgets(line,MAX1+1,fp1)!=NULL){
 for(i=0;i<MAX1+1;i++) {
        if(line[i]=='v')
        v[i]++;
        if(line[i]!='v')
        v[i]=0;
        if(v[i]==5){
        counter++;
        v[i]=0;
        }

 }

} return counter;


}
