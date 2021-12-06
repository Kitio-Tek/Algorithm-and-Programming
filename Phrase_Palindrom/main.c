#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void palindrom_phrase(char *name);
void solveR(int pos,char **val, int n,int k,char *sol, int *found,int *mark);
int palindrom(char *str);
void transform(char *str);
char **readFile(FILE *fp,int *number);

int main()
{
   palindrom_phrase("File.txt");

    return 0;
}

void palindrom_phrase(char *name){
FILE *fp;
int number,i,found=0;


 fp=fopen(name,"r");

  if(fp==NULL)
    {puts("ERROR");
      exit(1);
     }

 char **mat=readFile(fp,&number);

 for(i=number;i>0 && !found;i--){
  char *sol=malloc(((i*10)+1)*sizeof(char));
  int *mark = calloc (number ,sizeof(int));
  sol[0]='\0';
  solveR(0,mat,number,i,sol,&found,mark);

}

if(!found) puts("No longest Palindrom sequence found");


fclose(fp);

}

void solveR(int pos,char **val, int n,int k,char *sol, int *found,int *mark)
 {  int i;

   if(pos>=k){
    if(palindrom(sol)){
      sol[strlen(sol)-1]='\0';
       printf("The longest Palindrom sequence: %s",sol);
       (*found)=1;}
    return;
  }

  for(i=0;i<n && !(*found); i++){
  if(mark[i] == 0){
    mark[i] = 1;

    sol=realloc(sol,strlen(sol)+1+strlen(val[i])+3);
    strcat(sol,val[i]);
    strcat(sol," ");


    solveR(pos+1,val,n,k,sol,found,mark);
    mark[i] = 0;
    sol[strlen(sol)-strlen(" ")]='\0'; // Remove previously added space
    sol[strlen(sol)-strlen(val[i])]='\0'; // Remove previously added String

   }


  }
}

int palindrom(char *str){
  char *tmp=strdup(str);

  transform(tmp); // remove capital letters and space

 for(int i=0;i<strlen(tmp)/2;i++)
  { if(tmp[i]!=tmp[strlen(tmp)-1-i]) //check if we have different characters
      return 0;}

  free(tmp);

  return 1;
}

void transform(char *str){
 int i,j=0;
  for( i=0;i<strlen(str);i++){
    if(str[i]!=' ')
      str[j++]=tolower(str[i]);
  }


 str[j]='\0';


}

char **readFile(FILE *fp,int *number){
   int i=0;
   fscanf(fp,"%d",number);

   char **mat=malloc((*number)*sizeof(char*));

   for(i=0;i<(*number);i++)
    mat[i]=malloc(10*sizeof(char));
    i=0;

  while(fscanf(fp,"%s",mat[i])!=EOF)
          i++;



  return mat;


}
