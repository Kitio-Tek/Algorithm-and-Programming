#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct list_p2 product_list;
struct list_p2{
char *prodName;
int  price;
product_list *next;
};


typedef struct list_p1 producer_list;
struct list_p1{
char *CompName;
char *Id;
producer_list *next;
product_list *link;
};

void free_P2list(producer_list *head);
void free_P1list(product_list *head);
void file_check(FILE *);
producer_list *readFile(producer_list *head, char *file1, char *file2);
producer_list *new_producer(producer_list *head, char *producer_Name, char *Id);
product_list *new_product(product_list *head, char *prodName, int price);

int main(int argc , char *argv[])
{ producer_list *head=NULL;

 head=readFile(head, argv[1],argv[2]);


    return 0;
}

producer_list *readFile(producer_list *head, char *file1, char *file2){
FILE *fp1,*fp2;
producer_list *tmp=head, *tmp1;
char CompName[MAX],Id[MAX],productName[MAX];
int price;
fp1=fopen(file1,"r");
fp2=fopen(file2,"r");
file_check(fp1);
file_check(fp2);

while(fscanf(fp1,"%s %s",CompName,Id)!=EOF){
    tmp=new_producer(tmp,CompName,Id);

    }

 while(fscanf(fp2,"%s %s %d",Id,productName,&price)!=EOF) {

    for(tmp1=tmp;tmp1!=NULL;tmp1=tmp1->next){
        if(strcmp(Id,tmp1->Id)==0)
        {
            tmp1->link=new_product(tmp1->link,productName,price);
            printf("Manufacturer:%s  Product ID:%s Product Name:%s Price:%d\n",tmp1->CompName,tmp1->Id,tmp1->link->prodName,tmp1->link->price);

        }
    }
 }


 fclose(fp1);
 fclose(fp2);
 return tmp;
 }

 producer_list *new_producer(producer_list *head, char *producer_Name, char *Id){
  producer_list *tmp;
  tmp=(producer_list*)malloc(sizeof(producer_list));

  if(tmp==NULL){
    fprintf(stderr,"Memory allocation error\n");
        EXIT_SUCCESS;
  }
  tmp->CompName=strdup(producer_Name);
  tmp->Id=strdup(Id);
  tmp->link=NULL;

  tmp->next=head;
  head=tmp;
  return head;
 }

product_list *new_product(product_list *head, char *prodName, int price){

  product_list *tmp;
  tmp=(product_list*)malloc(sizeof(product_list));

  if(tmp==NULL){
    fprintf(stderr,"Memory allocation error\n");
        EXIT_SUCCESS;
  }
  tmp->prodName=strdup(prodName);
  tmp->price=price;

  tmp->next=head;
  head=tmp;
  return head;
 }
 void file_check(FILE *fp)
{
    if(fp==NULL)
    {
        fprintf(stderr,"File loading error\n");
        exit(EXIT_FAILURE);
    }
}

void free_P2list(producer_list *head){
producer_list *tmp;

while(head!=NULL){
    tmp=head;
    head=head->next;

    free_P1list(tmp->link);
    free(tmp->CompName);
    free(tmp->Id);


    free(tmp);
}
}
void free_P1list(product_list *head){
product_list *tmp;
if(head==NULL)
    return;
tmp=head->next;
free(head->prodName);
free(head);

free_P1list(tmp);

}

