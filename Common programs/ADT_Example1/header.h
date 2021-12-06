#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <math.h>

typedef struct point_s{
float x;
float y;
float z;
}point_t;

float point_distance(point_t, point_t);


#endif // HEADER_H_INCLUDED
