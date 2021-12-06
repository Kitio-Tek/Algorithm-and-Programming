typedef struct list1 list1_t
{ int val;
  list1_t *next;
  int flag;
}
typedef struct list2 list2_t{
int val;
int occurence;
list2_t *next;
}

list2_t *list_compress(list1_t *p1){
list1_t *tmp1,*tmp2,*tmp=NULL,*head=NULL;
int occurrence=0;

for(tmp1=p1;tmp1->next;tmp1!=NULL) //Marking all nodes to true(1)
  tmp1->flag=1;

 
  for(tmp1=p1;tmp1->next;tmp1!=NULL)
   { occurrence=0;
     if(tmp1->flag){             //Node still true
    
        for(tmp2=p1;tmp2!=NULL;tmp2->next){    // traversing each node
           if(tmp1->val==tmp2->val){
             occurrence++;
             tmp2->flag=0;
         }
       }
     
    tmp=newNode(occurrence,tmp1->val);
    head=InsertNode(head,tmp);

    }
  }

return head;

}

list2_t *newNode(int occ,int val)
{ list2_t *tmp=malloc(sizeof(list2_t));
   if(tmp==NULL)
   printf("Error");
   
   tmp->val=val;
   tmp->occurence=occ;
   tmp->next=NULL;

return tmp;
}

list2_t *InsertNode(list2_t *head,list2_t *tmp){
 list2_t *tmp1;
  if(head==NULL)
    return tmp;
 
 for(tmp1=head; tmp1->next!=NULL; tmp1=tmp1->next);   //tail insertion
  tmp1->next=tmp;

return head;
}