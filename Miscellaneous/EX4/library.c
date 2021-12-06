#include "library.h"

struct connection{
char *name;
char *date;
char *source;
char *access;
int state;
link *next;
};
struct list{
char *ip_address;
list_t *next;
link *link;
};

void file_check(FILE *fp)
{
    if(fp==NULL)
    {
        fprintf(stderr,"File loading error\n");
        exit(EXIT_FAILURE);
    }
}
list_t *search(list_t *head,char *ip_address){
list_t *tmp;
for(tmp=head;tmp!=NULL;tmp=tmp->next){
        if(strcmp(ip_address,tmp->ip_address)==0){
           return tmp;
        }
    }
return NULL;
}

list_t *readFile(char *file){
char ip_address[MAX],name[MAX],date[MAX],source[MAX],access[MAX];
int flag=0,state=0;
list_t *tmp=NULL,*tmp1;
link *list;
FILE *fp;
fp=fopen(file,"r");
file_check(fp);


while(fscanf(fp,"%s %s %s %s %s %d",ip_address,name,date,access,source,&state)!=EOF)
{
    flag=0;
    list=malloc(sizeof(link));
    list->name=strdup(name);
    list->date=strdup(date);
    list->source=strdup(source);
    list->access=strdup(access);
    list->state=state;

    for(tmp1=tmp;tmp1!=NULL;tmp1=tmp1->next){
        if(strcmp(ip_address,tmp1->ip_address)==0){
            tmp1->link=link_list(tmp1->link,list);
            flag=1;
        }
    }

    if(flag==0)
        tmp=add_element(tmp,list,ip_address);


}

fclose(fp);
return tmp;
}
list_t *add_element(list_t *head,link *list,char *ip_address){
list_t *tmp=(list_t*)malloc(sizeof(list_t));

  if(tmp==NULL){
    fprintf(stderr,"Memory allocation error\n");
        EXIT_SUCCESS;}

  tmp->link=list;
  tmp->link->next=NULL;
  tmp->ip_address=strdup(ip_address);
  tmp->next=head;
  if(head==NULL)
   return tmp;

  head=tmp;
  return head;
}
void print_list (list_t *tmp){
link *tmp1;
        printf("\t List of accesses:\n");
        for(tmp1=tmp->link;tmp1!=NULL;tmp1=tmp1->next)
        printf("\t %s %s %s %s %d\n",tmp1->name,tmp1->date,tmp1->access,tmp1->source,tmp1->state);

return;

}

link *link_list(link *head,link *tmp){
link *tmp1;
  tmp1=(link*)malloc(sizeof(link));
  tmp1=tmp;

  if(tmp1==NULL){
    fprintf(stderr,"Memory allocation error\n");
        EXIT_SUCCESS;
  }
  if(head==NULL)
  {tmp1->next=head;
   return tmp1;
   }

tmp1->next=head;
head=tmp1;
return head;
}

void free_P2list(list_t *head){
list_t *tmp;

while(head!=NULL){
    tmp=head;
    head=head->next;

    free_P1list(tmp->link);
    free(tmp->ip_address);
    free(tmp);}
}
void free_P1list(link *head){
link *tmp;
if(head==NULL)
    return;
tmp=head->next;
free(head->name);
free(head->date);
free(head->source);
free(head->access);
free(head);

free_P1list(tmp);

}
