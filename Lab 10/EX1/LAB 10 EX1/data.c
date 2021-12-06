#include "data.h"

int compareStudent(Student st1,Student st2){
char namest1[2*MAXC];
char namest2[2*MAXC];

sprintf(namest1,"%s %s",st1.lastname,st1.firstname);
sprintf(namest2,"%s %s",st2.lastname,st2.firstname);

return(strcmp(namest1,namest2));
}


int compare(Student st,char *lastname,char *firstname){
char namest1[2*MAXC];
char namest2[2*MAXC];

sprintf(namest1,"%s %s",st.lastname,st.firstname);
sprintf(namest2,"%s %s",lastname,firstname);

return(strcmp(namest1,namest2));
}

int compareIDStudent(Student st1,Student st2){

return(st1.code-st2.code);
}
