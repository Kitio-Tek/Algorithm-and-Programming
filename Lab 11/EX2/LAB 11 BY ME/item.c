#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "item.h"

struct item{
char *registerNumber;
char *lastName;
int numberCreditLoaded, numberCreditPassed;
};

Item *ITEMscan(FILE *fp){
char registerNumber[MAXC];
char lastName[MAXC];
int numberCreditLoaded, numberCreditPassed;

fscanf(fp,"%s %s %d %d",registerNumber,lastName,&numberCreditLoaded,&numberCreditPassed);
Item *tmp=malloc(sizeof(Item));

if(tmp==NULL){
    return ITEMsetvoid();
}else {
    tmp->lastName = strdup(lastName);
    tmp->registerNumber = strdup(registerNumber);
    tmp->numberCreditPassed = numberCreditPassed;
    tmp->numberCreditLoaded = numberCreditLoaded;
  }
  return tmp;

}

void ITEMshow(Item *data){
fprintf(stdout,"%s %s %d %d\n",data->registerNumber,data->lastName,data->numberCreditLoaded,data->numberCreditPassed);
}

int ITEMcheckvoid(Item *data){
Key *k1,*k2="";

k1=KEYget(data);
if(KEYcompare(k1,k2)==0)
    return 1;
else
    return 0;
}

Item *ITEMsetvoid(){
char lastName[MAXC]="";
  char registerNumber[MAXC] ="";

  Item *tmp = malloc(sizeof(Item));
  if (tmp != NULL) {
    tmp->lastName = strdup(lastName);
    tmp->registerNumber = strdup(registerNumber);
    tmp->numberCreditPassed = -1;
    tmp->numberCreditLoaded = -1;
  }
  return tmp;
}

void ITEMwrite(FILE *fp, Item *data){
fprintf(fp,"%s %s %d %d\n",data->registerNumber,data->lastName,data->numberCreditLoaded,data->numberCreditPassed);
}

int KEYcompare(Key *k1,Key *k2){
return strcmp(k1,k2);
}

Key *KEYget(Item *data){
return data->registerNumber;
}



