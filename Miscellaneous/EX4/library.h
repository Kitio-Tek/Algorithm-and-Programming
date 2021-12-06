#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct connection link;
typedef struct list list_t;

void print_list (list_t *tmp);
list_t *readFile(char *file);
list_t *add_element(list_t *head,link *list,char *ip_address);
link *link_list(link *head,link *tmp);
void file_check(FILE *);
list_t *search(list_t *head,char *ip_address);
void free_P1list(link *head);
void free_P2list(list_t *head);



#endif // LIBRARY_H_INCLUDED
