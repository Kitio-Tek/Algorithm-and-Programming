#include "library.h"

int main(int argc,char *argv[])
{ list_t *head=NULL,*tmp=NULL;
  int end=0;
  char row[MAX],ip_address[MAX];


    while(end==0){
       fprintf(stdout,"User selection\n");
       fprintf(stdout,"\t1) load file\n\t2) Search according to IP address\n");
       fprintf(stdout,"\t3) Free data structure\n\t4) Quit\n\t>");
       scanf ("%1s", row);

       switch(atoi(row)){
     case 1:
        fprintf(stdout,"File loaded\n");
        head=readFile("file.txt");
  	     break;

      case 2:
       fprintf(stdout,"Enter IP address:\n");
       scanf("%s",ip_address);
        tmp = search(head,ip_address);

        if(tmp!=NULL)
            {printf("\tIP Found\n");
            print_list(tmp);}

        else printf("\tIP not Found\n");


	      break;
      case 3:
        free_P2list(head);
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





