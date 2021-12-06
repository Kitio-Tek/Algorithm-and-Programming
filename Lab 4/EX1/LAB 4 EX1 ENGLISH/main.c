#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
char *word;
int occurrences;
}index_t;

void readFILE2(FILE *fp2, index_t *v);
void readFILE1_occurrences(FILE *fp1,index_t *v, int n);

int main(int argc, char *argv[])
{ FILE *fp1,*fp2;
  index_t *v;
  int i,n;

  fp2=fopen(argv[2],"r");
  fscanf(fp2,"%d",&n);
  v=malloc(n*sizeof(index_t));

  if(v==NULL){
    fprintf(stderr,"Memory allocation error..\n");
    exit(1);}

    for(i=0;i<n;i++)
        {v[i].word=malloc(21*sizeof(char));
        v[i].occurrences=0;}

    readFILE2(fp2,v);
    fp1=fopen(argv[1],"r");
    readFILE1_occurrences(fp1,v,n);

    for(i=0;i<n;i++)
        printf("%s- %d occurrence(s)\n",v[i].word,v[i].occurrences);

    fclose(fp1);
    fclose(fp2);
    free(v);

    return 0;}

    void readFILE2(FILE *fp2, index_t *v){
    int i=0;
    while(fscanf(fp2,"%s",v[i].word)!=EOF)
        i++;
    }

    void readFILE1_occurrences(FILE *fp1,index_t *v, int n){
    char tmp[20+1];
    int i,j;

    while(fscanf(fp1,"%s",tmp)!=EOF){
        for(j=0;j<strlen(tmp);j++)
            tmp[j]=tolower(tmp[j]);
        for(i=0;i<n;i++)
        {
            if(strcmp(v[i].word,tmp)==0)
              {
                v[i].occurrences++;
                                    }
        }

    }

    }
