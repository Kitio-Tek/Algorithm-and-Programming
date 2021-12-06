#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct producer_s producer_t;
typedef struct product_s product_t;

struct producer_s {
char *name;
producer_t *next;
product_t *right;
};

struct product_s {
char *id;
float price;
product_t *next;
};


void insert(producer_t **head, char *name, char *id,float price);
producer_t *new_producer(producer_t *head, char *name,char *Id,float price);
product_t *new_product(product_t *head,char *Id,float price);
void free_product(product_t *head);
void free_producer(producer_t *head);



 int main(int argc, char  *argv[])
{ producer_t *head=NULL,*tmp;
  product_t *tmp2;

	insert(&head,"Rami","XYY",15);
	insert(&head,"Rami","XYY",17);
    insert(&head,"Alex","Detergent",25);
    insert(&head,"Alex","Milk",45);
    insert(&head,"Alex","XYY",15);
    insert(&head,"Tiger","XuuY",15);

    tmp=head;

    while(tmp!=NULL){
    	printf("name %s \n",tmp->name);
    	 tmp2=tmp->right;
    	while(tmp2!=NULL){


    		printf("Product ID: %s Price:%.2f\n",tmp2->id,tmp2->price);
    		tmp2=tmp2->next;
    	}

     tmp=tmp->next;
    }
	return 0;
}


void insert(producer_t **head, char *name, char *id,float price){
producer_t *tmp;
product_t *tmp2;
int flag2=0,flag1=0;

for(tmp=*head;tmp!=NULL && !flag1;tmp=tmp->next)
{
  if(!strcmp(tmp->name,name)) //if producer is found
{ flag1=1;


for(tmp2=tmp->right;tmp2!=NULL && !flag2;tmp2=tmp2->next){ //iterate on products
  if(!strcmp(id,tmp2->id) && tmp2->price!=price) // if price is different , update
  { tmp2->price=price;
   flag2=1;
 }
if(!strcmp(id,tmp2->id))// product is found
  flag2=1;
}
 if(!flag2) //No product found , add product
  tmp->right=new_product(tmp->right,id,price);
}
 }
if(!flag1) //No producer found, add producer and product
*head=new_producer(*head,name,id,price);


}
producer_t *new_producer(producer_t *head, char *name,char *Id,float price){
producer_t *tmp=malloc(sizeof(producer_t));
if(tmp==NULL)
printf("Error");

tmp->name=strdup(name);
tmp->next=NULL;
tmp->right=new_product(NULL,Id,price);
  if(head==NULL)
  	return tmp;

tmp->next=head;
head=tmp;
return head;
}
product_t *new_product(product_t *head,char *Id,float price){
product_t *tmp=malloc(sizeof(product_t));

if(tmp==NULL)
printf("Error");

tmp->id=strdup(Id);
tmp->price=price;
tmp->next=NULL;
  if(head==NULL)
  	return tmp;

tmp->next=head;
head=tmp;
return head;
}
void free_product(product_t *head){
product_t *tmp;

if(head==NULL)
return;
tmp=head->next;
free(head->id);
free(head);
free_product(tmp);
}
void free_producer(producer_t *head){
producer_t *tmp;
while(head!=NULL)
{ tmp=head;
head=head->next;
free_product(tmp->right);
free(tmp->name);
free(tmp);
}
}

