#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *str;
  }string;

void file_check(FILE *fp);
void struct_alloc(FILE *fpin, int *n,string **v);
void string_alloc(FILE *fpin, int n, string *v);
void free_struct(string *v, int n);
void alpha_sort(string *v, int n);
void print_struct(string *v, int n, FILE *fpout);



int main()
{ string *v;
  FILE *fpin,*fpout;
  int n;

  fpin=fopen("Input.txt","r");
  file_check(fpin);

   struct_alloc(fpin,&n,&v);

   string_alloc(fpin,n,v);
   fclose(fpin);
   alpha_sort(v,n);

   fpout=fopen("Output.txt","w");
   file_check(fpout);
   print_struct(v,n,fpout);
   fclose(fpout);

   free_struct(v,n);


  return EXIT_SUCCESS;
}

/*file check*/
void file_check(FILE *fp){
if(fp==NULL){
    fprintf(stderr,"File loading error\n");
    exit(EXIT_FAILURE);
   }
}

//free array allocated
void free_struct(string *v, int n){
 int i;
   for(i=0;i<n;i++)
     free(v[i].str);

   free(v);
}

//Sort strings alphabetically
void alpha_sort(string *v, int n){
int i,j;
char tmp[100];
 for(i=0;i<n-1;i++)
   for(j=i+1;j<n;j++){
     if(strcmp(v[i].str,v[j].str)>0){
       strcpy(tmp,v[i].str);
       strcpy(v[i].str,v[j].str);
       strcpy(v[j].str,tmp);
        }
    }
}

//Print array in fpout
void print_struct(string *v, int n, FILE *fpout){
int i;

for(i=0;i<n;i++){
    fprintf(fpout,"%s\n",v[i].str);
  }

}

//Allocate memory for each string
void string_alloc(FILE *fpin, int n, string *v){
int i=0;
char str[100];

while(i<n && fscanf(fpin,"%s",str)!=EOF){

        v[i].str=(char*)malloc((strlen(str)+1)*sizeof(char));
        if(v[i].str==NULL){
            fprintf(stderr,"Memory allocation\n");
            exit(EXIT_SUCCESS);
        }
    strcpy(v[i].str,str);
    i++;
   }


}

//Allocate number of rows
void  struct_alloc(FILE *fpin, int *n,string **v) {

fscanf(fpin,"%d",n);

*v=malloc(*n*sizeof(char*));
if(*v==NULL){
    fprintf(stderr,"Memory allocation\n");
    exit(EXIT_SUCCESS);
   }

}
