
void basket_generate (array_t *v, int n, int w){

sol (v,n,0,0,w);

}





void sol (int *val, int n, int start, int sum,int w){
int i,j;
 if(sum+val[start].weight>w || start>=n)
   return;


  for (i=start; i<n; i++) {
     j=1;
       while(j<=val[i].quantity && sum+val[i].weight<=w){
                sum=sum+val[i].weight;
             j++;

            }
       if(j!=1)
        printf("Code %d Weight %d Quantity %d",val[i].code,val[i].weight,j-1);
  

        sol(val,n,i+1,sum,w);
 
      }


}