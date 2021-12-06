#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX2 4

 typedef struct rect{
 char string[MAX2+1];
 float x1,y1,x2,y2;
 float area,per} rect;


void readfile(FILE *fp1, rect *v,int n);
void AreaPerimeter(rect *v,int n);
void sort(rect *v, int n, char flag);

int main(int argc, char *argv[])
{ FILE *fp1,*fp2,*fp3;
  int i,n;
  rect *v;

   if(argc!=4)
   {
       fprintf(stderr,"Error in the number of arguments\n");
       exit(1);
   }
    else{
        fp1=fopen(argv[1],"r");
        fscanf(fp1,"%d",&n);
        v=malloc(n*sizeof(rect));

        readfile(fp1,v,n);
        AreaPerimeter(v,n);

        fp2=fopen(argv[2],"w");
        fp3=fopen(argv[3],"w");

        sort(v,n,'a');
        for(i=n-1;i>=0;i--)
        {
            fprintf(fp2,"%s %.2f",v[i].string,v[i].area);
            fprintf(fp2,"\n");
        }

        sort(v,n,'p');
        for(i=n-1;i>=0;i--)
        {
            fprintf(fp3,"%s %.2f",v[i].string,v[i].per);
            fprintf(fp3,"\n");
        }

        fclose(fp1);
        fclose(fp2);
        fclose(fp3);
        free(v);
    }



    return 0;}

   void readfile(FILE *fp1, rect *v, int n){
   int i,flag,idx=0;
   float x,y;
   char tmp[MAX2+1];

   while(fscanf(fp1,"%s %f %f",tmp,&x,&y)!=EOF) {
    flag=0;
    for(i=0;i<n;i++){
       if(strcmp(v[i].string,tmp)==0)
       {
           flag=1;
           v[i].x2=x;
           v[i].y2=y;
       }

    }
    if(flag==0){
        strcpy(v[idx].string,tmp);
        puts(v[idx].string);
        v[idx].x1=x;
        v[idx].y1=y;
        idx++;

    } }


    }

    void AreaPerimeter(rect *v,int n){
    int i;
    float x,y;
    for(i=0;i<n;i++){

        x=v[i].x1-v[i].x2;
        y=v[i].y1-v[i].y2;;
        if(x<0)
            x=-x;
        if(y<0)
            y=-y;

        v[i].per=2*x+2*y;
        v[i].area=x*y;
    }


    }



    void sort(rect *v, int n, char flag){
    int i,j;
    rect tmp;
    if(flag=='p'){
        for(i=1;i<n;i++){

            tmp=v[i];
            j=i-1;
            while(j>=0 && tmp.per<v[j].per){
                v[j+1]=v[j];
                j--;
            }

         v[j+1]=tmp;
        }
}

   else if(flag=='a'){
        for(i=1;i<n;i++){

            tmp=v[i];
            j=i-1;
            while(j>=0 && tmp.area<v[j].area){
                v[j+1]=v[j];
                j--;
            }

         v[j+1]=tmp;
        }
}

    }



