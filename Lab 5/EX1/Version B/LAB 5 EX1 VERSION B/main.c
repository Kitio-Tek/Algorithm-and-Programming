#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void file_check(FILE *fp);
char **malloc_row(FILE *fpin, int *n);
void string_alloc(FILE *fpin, int n, char **v);
void free_array(char **v, int n);
void alpha_sort(char **v, int n);
void print_array(char **v, int n, FILE *fpout);


int main()
{  FILE *fpin,*fpout;
   char **v;
   int n;

   fpin=fopen("Input.txt","r");
   file_check(fpin);
   v=malloc_row(fpin,&n);

   string_alloc(fpin,n,v);
   fclose(fpin);
   alpha_sort(v,n);

   fpout=fopen("Output.txt","w");
   file_check(fpout);
   print_array(v,n,fpout);
   fclose(fpout);

   free_array(v,n);




    return EXIT_SUCCESS;
}


/*file check*/
void file_check(FILE *fp){
if(fp==NULL){
    fprintf(stderr,"File loading error\n");
    exit(EXIT_FAILURE);
   }
}

//Allocate number of rows
char **malloc_row(FILE *fpin, int *n){

char** v;
fscanf(fpin,"%d",n);

v=(char **)malloc(*n*sizeof(char*));
if(v==NULL){
    fprintf(stderr,"Memory allocation\n");
    exit(EXIT_SUCCESS);
   }
return v;
}

//Allocate memory for each string
void string_alloc(FILE *fpin, int n, char **v){
int i;
char str[100];

for(i=0;i<n;i++){
    fscanf(fpin,"%s",str);
        v[i]=(char*)malloc((strlen(str)+1)*sizeof(char));
        if(v[i]==NULL){
            fprintf(stderr,"Memory allocation\n");
            exit(EXIT_SUCCESS);
        }
    strcpy(v[i],str);
   }

}

//Sort strings alphabetically
void alpha_sort(char **v, int n){
int i,j;
char tmp[100];
 for(i=0;i<n-1;i++)
   for(j=i+1;j<n;j++){
     if(strcmp(v[i],v[j])>0){
       strcpy(tmp,v[i]);
       strcpy(v[i],v[j]);
       strcpy(v[j],tmp);
        }
    }
}


//Print array in fpout
void print_array(char **v, int n, FILE *fpout){
int i;

for(i=0;i<n;i++){
    fprintf(fpout,"%s\n",v[i]);
  }

}

//free array allocated
void free_array(char **v, int n){
 int i;
   for(i=0;i<n;i++)
     free(v[i]);

   free(v);
}



