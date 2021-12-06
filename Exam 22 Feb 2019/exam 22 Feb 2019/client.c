
#include "tree.h"
#include "Museum.h"
#include "data.h"


int main(int argc,char *argv[])
{ FILE *fp;

  museum_t *ms;


  int retValue;
  node_t *root=NULL,*tmp;
  data_t *d;
  int end=0;
  char row[MAXC];


    while(end==0){
       fprintf(stdout,"User selection:\n");
       fprintf(stdout,"\t1) load file:\n\t2) Add a Reservation:\n\t3) Search a Reservation:\n");
       fprintf(stdout,"\t4) Quit\n\t>");
       scanf ("%1s", row);

       switch(atoi(row)){
     case 1:
        fprintf(stdout,"Name of file:\n");
        strcpy(row,"file.txt");
        fp=fopen(row,"r");
        file_check(fp);

        ms=loadFile(fp,ms);




  	     break;

      case 2:
        fprintf (stdout, "data: ");
         d=readData (stdin, d);
        retValue=check_museum(ms,d);

         if (retValue==0) {
          fprintf (stderr, "Input error\n");
          exit (0);
        }
         else
          printf("%d",retValue);

          root=add_reservation(root,d);
        if(root!=NULL) printf("found\n");
        else printf("not found\n");

         break;


      case 3:
        tmp = search(root,"Smithson_James");
        if(tmp!=NULL) printf("found\n");
        else printf("not found\n");
      break;

      case 4:
	   end = 1;
       break;

      default:
	fprintf (stderr, "Unknown Option.\n");
	break;
	}
}


    return 0;
}
