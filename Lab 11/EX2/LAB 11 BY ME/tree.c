#include "tree.h"

#include <stdlib.h>

struct node {
  Item *item;
  node_t *left;
  node_t *right;
};

void loadFile(FILE *fp,node_t **root,int *size){
  Item *item;
  *root=createEmptyTree();

  while(!feof(fp)){
    item=ITEMscan(fp);
    //ITEMshow(item);
    (*size)++;
    *root=insert(*root,item);
  }

 //listBST(*root,INORDER,0);
 /*printf("\n");
 listBST(*root2);*/

  return;
}

int listAndBST (link *list, node_t *root){
    int level=0;
    TREEsearch(list,root,&level);
    return level;
}


int TREEsearch(link *l,node_t *root,int *level){
  if(KEYcompare(KEYget(STgetItemlink(l)),KEYget(TREEgetItem(root)))==0) return *level;

  if (KEYcompare(KEYget(STgetItemlink(l)),KEYget(TREEgetItem(root))) < 0){
    (*level)++;
    return (TREEsearch (l,root->left,level));
  }
  else{
    (*level)++;
    return (TREEsearch (l,root->right,level));
  }
}


ST *loadST(node_t *root,int size){
  ST *st;
  st=STinit(size);
  st=storeBSTinST(root,st,INORDER);
  //STdisplay(st);
  return st;
}


ST *storeBSTinST(node_t *root,ST *st,int mode){
  if(root==NULL) return st;

  if(mode==PREORDER){
    //ITEMshow(root->item);
    STinsert(st,root->item);
  }
  st=storeBSTinST(root->left,st,mode);

 if(mode==INORDER){
    STinsert(st,root->item);
    //ITEMshow(root->item);
  }

  st=storeBSTinST(root->right,st,mode);

  if(mode==POSTORDER){
   //ITEMshow(root->item);
   STinsert(st,root->item);
  }
  return st;
}

void writeFile(FILE *fp,ST *st){
  link *z=NEW (ITEMsetvoid(), NULL);

  for(int i=0;i<STgetSize(st);i++){
   writeItemR(fp,STgetByIndex(st,i),z);
  }

  return;
}

node_t *createEmptyTree (void){
  return (NULL);
}

node_t *TreeInit(){
  node_t *root=malloc(sizeof(*root));
  return root;
}

void listBST(node_t *root,int mode,int i){
  if(root==NULL) return;

  if(mode==PREORDER)
    ITEMshow(root->item);
  listBST(root->left,mode,i+1);
  if(mode==INORDER){
    printf("level %d: ",i);
   ITEMshow(root->item);
  }
  listBST(root->right,mode,i+1);
  if(mode==POSTORDER)
   ITEMshow(root->item);
  return;
}



node_t *insert (node_t *root, Item *item){
  /* Empty Tree: Found Position */

  if (root == NULL) {
    root = TreeInit();
    root->item = item;
    root->left= root->right = NULL;
    return root;
  }
      /* Duplicated Element */
    if (KEYcompare(KEYget(item),KEYget(root->item)) == 0) {
      return (root);
    }

    if (KEYcompare(KEYget(item),KEYget(root->item)) < 0) {
      /* Insert on the left */
      root->left= insert (root->left, item);
    } else {
      /* Insert on the right */
     root->right = insert (root->right, item);
    }
    return (root);
}


Item *TREEgetItem(node_t *root){
  return root->item;
}


void freeTree(node_t *rp)
{
  if (rp == NULL) {return;}
  freeTree (rp->left);
  freeTree (rp->right);
  free (rp);
  return;
}

