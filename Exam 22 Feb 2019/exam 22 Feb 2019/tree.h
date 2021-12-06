#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include "Museum.h"


typedef struct reservation_s node_t;
typedef struct list_s list_t;

node_t *add_reservation(node_t *root,data_t *data);
node_t *TreeInit();
list_t *add_info(list_t *head,data_t *data);
node_t *search(node_t *rp, char *name);


#endif // TREE_H_INCLUDED
