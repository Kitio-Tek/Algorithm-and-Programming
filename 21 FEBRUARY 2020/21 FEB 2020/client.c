#include "queue.h"

int main(int argc, char *argv[])
{
  queue_t *pq=NULL;
  int retValue=0;
  int end=0;
  char row[MAXC],command[MAXC];
  FILE *fp=NULL;



       strcpy(row,argv[1]);
        fp=fopen(row,"r");
        file_check(fp);
        pq=loadFile(fp);
        //printpq(pq);

        while(end==0){
       fprintf(stdout,"User selection:\n");
       fprintf(stdout,"\t1) Find best solution:\n");
       fprintf(stdout,"\t2) Quit\n\t>");
       scanf ("%1s", command);

       switch(atoi(command)){


     case 1:
        retValue= bestSolutions(pq,atoi(argv[2]));

        if(retValue==1) printf("Solution Found\n");
        else printf("No solution found, \n");
        end = 1;
        break;

     case 2:
	   end = 1;
       break;

      default:
	fprintf (stderr, "Unknown Option.\n");
	break;

	}}

    return 0;
}
