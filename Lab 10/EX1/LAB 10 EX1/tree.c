#include "treePublic.h"

struct node{
Student student;
  node_t *left_1;
  node_t *right_1;
  node_t *left_2;
  node_t *right_2;
};

void loadFile(FILE *fp,node_t **root1,node_t **root2){
char lastname[MAXC],firstname[MAXC],date[MAXC],course[MAXC];
Student st;

*root1=createEmptyTree();
*root2=createEmptyTree();

while(fscanf(fp,"%d %s %s %s %s %d",&st.code,lastname,firstname,date,course,&st.year)!=EOF){
 st.firstname=strdup(firstname);
 st.lastname=strdup(lastname);
 st.date=strdup(date);
 st.course=strdup(course);

 *root1=insert_node(*root1,st,1);
 *root2=insert_node(*root2,st,2);


}
/*listBST(*root1);*/
}
static node_t *TreeInit(){
    node_t *root=malloc(sizeof(node_t));
    return root;
}

static void listBST(node_t *root){
if(root==NULL)
    return;
listBST(root->left_1);

printf("%d %s %s %s %s %d\n",root->student.code,root->student.firstname,
    root->student.lastname,root->student.date,root->student.course,root->student.year);
listBST(root->right_1);

  return;
}
node_t *insert_node(node_t *root,Student st, int i){

 if(root==NULL){
    root=TreeInit();
    root->student=st;
    root->left_1 = root->right_1 = root->left_2 = root->right_2 = NULL;
    return root;

 }

 if(i==1){
   if(compareStudent(st,root->student)==0){
    return(root);
   }

   if(compareStudent(st,root->student)<0){
    root->left_1=insert_node(root->left_1,st,1);
   }
   else{
    root->right_1 = insert_node (root->right_1, st,1);
   }

  return(root);}

  else{
    if(compareIDStudent(st,root->student)==0)
        return(root);

    if (compareIDStudent(st, root->student) < 0) {
      root->left_2 = insert_node(root->left_2, st,2);
    }
    else {
      root->right_2 = insert_node(root->right_2, st,2);
    }
    return (root);
  }

  }


node_t *searchByName(node_t *rp, char *lastname, char *firstname){
  if(rp==NULL || compare(rp->student,lastname,firstname)==0)
    return(rp);

  if(compare(rp->student,lastname,firstname)<0)
    return (searchByName(rp->right_1,lastname,firstname));
  else
    return(searchByName(rp->left_1,lastname,firstname));
}

node_t *searchByCode(node_t *rp, int code){
 if(rp==NULL || rp->student.code==code)
    return rp;

 if(rp->student.code-code<0)
    return (searchByCode(rp->right_2,code));
 else
    return (searchByCode(rp->left_2,code));

}

node_t *createEmptyTree (void){
  return (NULL);
}










