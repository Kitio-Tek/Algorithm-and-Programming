#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "data.h"

struct data_s
{
char *client_name;
char *museum;
char time[14];
int day;
int person;};

data_t *readData(FILE *fp,data_t *data){
char client_name[MAXC];
char museum[MAXC];
int person, day;
data=malloc(sizeof(data_t));

fscanf(fp,"%s %d %s %d %s",museum,&day,data->time,&person,client_name);

    data->museum= strdup(museum);
    data->day = day;
    data->person = person;
    data->client_name = strdup(client_name);

    fprintf(stdout,"%s %d %s %d %s\n",data->museum,data->day,data->time,data->person,data->client_name);

return data;

}

char *get_museum(data_t *data){
return data->museum;
}

int get_day(data_t *data){
return data->day;
}
char *get_client(data_t *data){
return data->client_name;
}

char *get_time(data_t *data){
return data->time;
}
int get_person(data_t *data){
return data->person;
}
