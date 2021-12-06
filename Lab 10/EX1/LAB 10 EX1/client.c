#include "treePublic.h"


int main()
{ node_t *root1,*root2,*tmp;
  int retValue, end=0;
  char row[MAXC];
  FILE *fp=NULL;

    while(end==0){
       fprintf(stdout,"User selection\n");
       fprintf(stdout,"\t1) load file\n\t2) SearchS last first\n\t3) SearchN integer\n");
       fprintf(stdout,"\t4) Save File\n\t5) Quit\n\t>");
       scanf ("%1s", row);

       switch(atoi(row)){
     case 1:
        fprintf(stdout,"Name of file:\n");
        strcpy(row,"lab10-input.txt");
        fp=fopen(row,"r");
        if(fp==NULL) {printf("Opening fail\n"); exit (-1);}

        loadFile(fp,&root1,&root2);
  	     break;

      case 2:
        tmp = searchByName(root1,"Rossi","Mario");
        if(tmp!=NULL) printf("found\n");
        else printf("not found\n");
	      break;

      case 3:
        tmp = searchByCode(root2,177329);
        if(tmp!=NULL) printf("found\n");
        else printf("not found\n");
        break;

	/*tmp = searchI (root1, d);
	if (tmp != NULL) {
	  fprintf (stdout, "Iterative Search: Found -> ");
          writeData (stdout, getData(tmp));
	} else {
	  fprintf (stdout, "Iterative Search: Not Found\n");
        }
	tmp = searchR (root, d);
	if (tmp  != NULL) {
	  fprintf (stdout, "Recursive Search: Found -> ");
          writeData (stdout, getData(tmp));
	} else {
	  fprintf (stdout, "Recursive Search: Not Found\n");
        }
	break;

      case 4:
	writeTree (stdout, root, INORDER);
	break;

      case 5:
	fprintf (stdout, "File Name: ");
	scanf ("%s", row);

        if (strcmp (row, "stdout") == 0) {
          fp = stdout;
        } else {
   	  fp = fopen (row, "w");
        }

        if (fp == NULL) {
         fprintf (stderr, "Error Opening File %s\n", row);
         break;
	}

	writeTree (fp, root, PREORDER);

        if (strcmp (row, "stdout") != 0) {
	  fclose(fp);
	}
	break;

      case 6:
	fprintf (stdout, "File Name: ");
	scanf ("%s", row);

	fp = fopen (row, "r");
	if (fp == NULL) {
	  fprintf (stderr, "Error Opening File %s\n", row);
	} else {
	  freeTree (root);
	  root = readTree (fp);
	}
	break;

      case 7:
        fprintf (stdout, "Tree minimum iterative: ");
        tmp = treeMinI (root);
        writeData (stdout, getData(tmp));
        fprintf (stdout, "Tree minimum recursive: ");
        tmp = treeMinR (root);
        writeData (stdout, getData(tmp));
        fprintf (stdout, "Tree maximum iterative: ");
        tmp = treeMaxI (root);
        writeData (stdout, getData(tmp));
        fprintf (stdout, "Tree maximum recursive: ");
        tmp = treeMaxR (root);
        writeData (stdout, getData(tmp));
	break;*/

      case 8:
	end = 1;
	break;

      default:
	fprintf (stderr, "Unknown Option.\n");
	break;
    }
  }

 // freeTree(root);

  return 0;
}





