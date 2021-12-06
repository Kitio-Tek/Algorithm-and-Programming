#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tree.h"


 struct reservation_s  {
 node_t *left;
 node_t *right;
 char *client_name;
 list_t *link;
 };

 struct list_s{
 char *museum;
 int day;
 char *time;
 int number_of_person;
 list_t *next;
 };

 node_t *add_reservation(node_t *root,data_t *data){
  char *client_name=get_client(data);

  if (root == NULL) {
    root = TreeInit();

    root->client_name=strdup(client_name);
    root->link=add_info(NULL,data);
    root->left= root->right = NULL;
    return root;
  }
      /* Duplicated Element */
    if (strcmp(root->client_name,client_name)==0) {
       root->link=add_info(root->link,data);

      return (root);
    }

    if (strcmp(root->client_name,client_name) < 0) {
      /* Insert on the left */
      root->right= add_reservation(root->right, data);
    } else {
      /* Insert on the right */
     root->left = add_reservation(root->left, data);
    }
    return (root);
}
node_t *TreeInit(){
  node_t *root=malloc(sizeof(node_t));
  return root;
}

list_t *add_info(list_t *head,data_t *data){
list_t *tmp=malloc(sizeof(list_t));

tmp->day=get_day(data);
tmp->number_of_person=get_person(data);
tmp->museum=strdup(get_museum(data));
tmp->time=strdup(get_time(data));

tmp->next=head;
return tmp;
}

node_t *search(node_t *rp, char *name){
  if(rp==NULL || strcmp(rp->client_name,name)==0)
    return(rp);

  if(strcmp(rp->client_name,name)<0)
    return (search(rp->right,name));

  else
    return(search(rp->left,name));
}

