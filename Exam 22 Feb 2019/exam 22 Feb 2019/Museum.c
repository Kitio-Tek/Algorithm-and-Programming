#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Museum.h"

typedef struct timeslot_s {
 char time[12];
 int max_people;
 int day_counter[MAX_DAY];
 }timeslot_t;

 typedef struct museum_s {
 char *museum_name;
 int ntime_slots;
 timeslot_t *slot;
 }museum_t;


 museum_t *loadFile(FILE *fp,museum_t *ms){
 char museum[MAXC];
 ms=malloc(MAX_MS*sizeof(museum_t));

   int ntimeslots,i=0;
    while(fscanf(fp,"%s %d",museum,&ntimeslots)!=EOF)
{
    ms[i].museum_name= strdup(museum);

    ms[i].ntime_slots=ntimeslots;
    fprintf(stdout,"%s %d \n",ms[i].museum_name,ms[i].ntime_slots);

    ms[i].slot=loadFile_timeslot(fp,ms[i].slot,ntimeslots);

    i++;
    }

return ms;
}

int check_museum(museum_t *ms,data_t *data){
char *museum=get_museum(data);
int i;
 for(i=0;i<MAX_MS;i++){
    if(strcmp(ms[i].museum_name,museum)==0)
        return check_slot(ms[i].slot,data,ms[i].ntime_slots);
 }

 return 0;
}

int check_slot(timeslot_t *tmp,data_t *data,int n){
int i;
char *time=get_time(data);
int day=get_day(data);
int person=get_person(data);

 for(i=0;i<n;i++){
    if(strcmp(tmp[i].time,time)==0 && (tmp[i].day_counter[day]+person)<=tmp[i].max_people)
    {  tmp[i].day_counter[day]=tmp[i].day_counter[day]+person;

        return 1;}}


return 0;
}


timeslot_t *loadFile_timeslot(FILE *fp,timeslot_t *tmp,int n){
 tmp=calloc(n,sizeof(timeslot_t));
  int i;
  for(i=0;i<n;i++){
    fscanf(fp,"%s %d",tmp[i].time,&tmp[i].max_people);
    printf("%s %d %d\n",tmp[i].time,tmp[i].max_people,tmp[i].day_counter[0]);
  }
return tmp;
}


 void file_check(FILE *fp)
{
    if(fp==NULL)
    {
        fprintf(stderr,"File loading error\n");
        exit(EXIT_FAILURE);
    }
}
