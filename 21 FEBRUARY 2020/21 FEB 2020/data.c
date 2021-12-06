#include "data.h"

int compareValue(Item s1,Item s2){
    if((s1.value)<(s2.value))
        return -1;
    else
        return 0;

}

int product(Item data){
return (data.weight)*(data.availability);
}

void print_Sol(Item data){

printf("%s %d %d %d\n",data.product,data.availability,data.weight,data.value);
}
