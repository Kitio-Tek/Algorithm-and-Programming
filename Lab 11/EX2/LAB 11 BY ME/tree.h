#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED


#include "st.h"


#define PREORDER -1
#define INORDER 0
#define POSTORDER 1

typedef struct node node_t;

void loadFile(FILE *fp, node_t **root, int *size);
node_t *createEmptyTree();
node_t *TreeInit();
void listBST(node_t *root, int mode, int i);
int listAndBST(link *list, node_t *root);
Item *TREEgetItem(node_t *root);

node_t *insert(node_t *, Item *);
void freeTree(node_t *);

ST *loadST(node_t *,int);
ST *storeBSTinST(node_t *,ST *,int);
void writeFile(FILE *fp,ST *st);
int TREEsearch(link *l, node_t *root, int *level);

#endif // TREE_H_INCLUDED
