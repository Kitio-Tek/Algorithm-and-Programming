#ifndef TREEPUBLIC_H_INCLUDED
#define TREEPUBLIC_H_INCLUDED

#include "data.h"
#define PREORDER -1
#define INORDER 0
#define POSTORDER 1

typedef struct node node_t;

void loadFile(FILE *fp,node_t **,node_t **);
static node_t *createEmptyTree();
static node_t *TreeInit();
node_t *searchByName(node_t*, char *, char*);
node_t *searchByCode(node_t*, int);

node_t *insert_node(node_t*, Student,int);
static void listBST(node_t *);





#endif // TREEPUBLIC_H_INCLUDED
