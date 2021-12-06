#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#include "tree.h"


int main(int argc, char *argv[])
{ node_t *root;
  FILE *fpr, *fpw;
  int size=0;
  ST *st;
  link **list;


  if(argc != 3){
    printf("Wrong number of parameters");
    exit (-1);
  }

  fpr=fopen(argv[1],"r");
  if(fpr==NULL){
    printf("Opening Fail");
    exit (-1);
  }


  fpw=fopen(argv[2],"w");
  if(fpw==NULL){
    printf("Opening Fail");
    exit (-1);
  }
  //1
  loadFile(fpr,&root,&size);
  //2
  st=loadST(root,size);
  //3
  writeFile(fpw,st);
  //B
  list=listUnique(st);
  //C

  for(int i=0;i<STgetSize(st);i++){
    printf("level %d: ",listAndBST(list[i],root));
    ITEMshow(STgetItem(list,i));}

    fclose(fpw);
    fclose(fpr);
    freeTree(root);

    return 0;
}
