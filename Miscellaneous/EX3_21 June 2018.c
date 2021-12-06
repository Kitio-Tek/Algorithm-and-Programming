void subsequences (char*s, int k){
char *sol=malloc((k+1)*sizeof(char));

comb (s, sol, k,0,0);
}

void  sequence(char *val, char *sol, int k, int start, int pos){
int i, j;

  if (pos >= k) {
          sol[pos]='\0';
            if(Alphabetic(sol)){
               
            printf("Solution %s\n", sol);
            return;
       }
    }
     
   
 for (i=start; i<strlen(val); i++) {
           sol[pos] = val[i];
       sequence(val,sol,k,i+1,pos+1);
     }
 
}

int Alphabetic(char *sol){

 for(int i=1;i<strlen(sol);i++){
    if(str[i]<str[i-1])
      return 0;
   }
return 1;
}