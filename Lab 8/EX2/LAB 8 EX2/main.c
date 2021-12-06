#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXBIT 8
#define MAXCODE 256

int power(int n);
void gray(int code[MAXCODE][MAXBIT],int pos,int nbit);
void gray_wrapper(int code[MAXCODE][MAXBIT],int nbit);
void print_code(int code[MAXCODE][MAXBIT],int nbit);

int main(int argc, char *argv[])
{   int code[MAXCODE][MAXBIT];
    int nbit = atoi(argv[1]);

    if (nbit > MAXBIT) {
      printf("Error - Number of bits should be <= 8\n");
      return 1;
    }


    printf("\nGray1\n");
    gray_wrapper(code,nbit);
    print_code(code, nbit);
    return 0;
}
void gray_wrapper(int code[MAXCODE][MAXBIT],int nbit){
    gray(code,0,nbit);
}
int power(int n){
return 1<<n;
}

void gray(int code[MAXCODE][MAXBIT],int pos,int nbit){
    int i,j,ncode=power(nbit-pos);

    if(pos==nbit)
        return;
    gray(code,pos+1,nbit);

    for(i=0;i<ncode/2;i++){
            code[i][pos]=0;
            code[ncode/2 +i][pos]=1;
            for(j=pos+1;j<nbit;j++)
                code[ncode/2 +i][j]=code[ncode/2-1-i][j];


    }

}
void print_code(int code[MAXCODE][MAXBIT],int nbit){
int i,j,ncode=power(nbit);

for (i=0; i<ncode; i++) {
    for (j=0; j<nbit; j++) {
      printf("%d", code[i][j]);
    }
    printf("\n");
  }

}
