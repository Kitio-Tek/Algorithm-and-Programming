#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>



int main()
{ FILE *fp;
  int r,c,x,y;
  r=rec(4);
  printf("%d",r);
    return 0;
}
int rec(int n){
int i,res;
if(n==0)
    return 1;
res=0;
for(i=0;i<n;i++)
    res+=rec(i)*rec(n-1-i);
return res;

}
