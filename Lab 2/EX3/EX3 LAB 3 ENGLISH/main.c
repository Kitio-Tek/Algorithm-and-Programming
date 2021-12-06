#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

void search(FILE *fp1,FILE *fp2, char argv1[],char argv2[]);

int main(int argc, char *argv[])
{
   FILE *fp1,*fp2;


   if(argc!=5)
    printf("Error,wrong number of arguments");
   else{

    fp1=fopen(argv[2],"r");
      fp2=fopen(argv[4],"w");

          search(fp1,fp2,argv[1],argv[3]);


}      fclose(fp1);
          fclose(fp2);
    return 0;
}

void search(FILE *fp1,FILE *fp2, char argv1[],char argv2[]){
 int idx,j,position;
 char *ptr;
 char string[MAX+1],line,strout[MAX+1];

 while(fscanf(fp1,"%s%c",string,&line)!=EOF){
    idx=0;
    ptr=strstr(string,argv1);
    if(ptr==NULL){
        for(j=0;j<strlen(string);j++){
            strout[idx]=string[j];
            idx++;
        }
    }

    if(ptr!=NULL){
       position=strlen(string)-strlen(ptr);

       for(j=0;j<position;j++){
        strout[idx]=string[j];
        idx++;
       }
       for(j=0;j<strlen(argv2);j++){
        strout[idx]=argv2[j];
        idx++;
       }

       for(j=position+strlen(argv1);j<strlen(string);j++){
        strout[idx]=string[j];
        idx++;
       }

}

        strout[idx]='\0';
        fprintf(fp2,"%s",strout);
        fprintf(fp2," ");
        if(line=='\n')
            fprintf(fp2,"\n");



 }

}

