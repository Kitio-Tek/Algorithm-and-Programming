#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ROW_MAX 1000

typedef struct list node;
struct list{
char *str;
int frequency;
node *next;};

node *file_read(node *, char *);
node *newnode();
void file_check(FILE *);
void lower_case(char *);
void file_write(node *,char *);
void free_node(node *head);

int main()
{ node *head=NULL;
  char file1[ROW_MAX],file2[ROW_MAX];

  fprintf(stdout,"Enter Input file name\n");
  scanf("%s", file1);
  fprintf(stdout,"Enter Output file name\n");
  scanf("%s", file2);


  head=file_read(head,file1);
  file_write(head,file2);
  free_node(head);

    return 0;
}

node *file_read(node *head, char *name)
{ FILE *fp;
  node *tmp;
  int flag;

  fp=fopen(name,"r");
  file_check(fp);

  while(fscanf(fp,"%s",name)!=EOF){
     lower_case(name);
     flag=0;
     for(tmp=head;tmp!=NULL;tmp=tmp->next)
       {if(strcmp(tmp->str,name)==0)
        { tmp->frequency++;
          flag=1;
        }}

        if(flag==0)
        { tmp=newnode();
          tmp->str=strdup(name);
          tmp->frequency=1;
          tmp->next=head;
          head=tmp;
        }
}
  fclose(fp);
  return(head);

}
void lower_case(char *str){
     int i=0;
    while(i<strlen(str))
    {
        str[i]=tolower(str[i]);
        i++;

    }

}

node *newnode(){
  node *tmp;
  tmp=(node*)malloc(sizeof(node));
  if(tmp==NULL){
    fprintf(stderr,"Memory allocation error\n");
    EXIT_FAILURE;
  }
tmp->frequency=0;

  return(tmp);
}


void file_check(FILE *fp){
if(fp==NULL){
    fprintf(stderr,"File loading error\n");
    exit(EXIT_FAILURE);
   }
}

void file_write(node *head,char *name){

FILE *fp;
node *tmp;
if(strcmp(name,"stdout")==0)
    fp=stdout;

else{ fp=fopen(name,"w");
      file_check(fp);
    }
tmp=head;
while(tmp!=NULL){
    fprintf(fp,"%s %d\n",tmp->str,tmp->frequency);
    tmp=tmp->next;
}
  if(strcmp(name,"stdout")!=0)
    fclose(fp);
}
void free_node(node *head){
node *tmp;
while(head!=NULL){
    tmp=head;
    head=head->next;
    free(tmp->str);
    free(tmp);
}
}
