/*
    Louis 25/11/2021 : utils.h 
    description : fonctions utiliser dans plusieurs fichier pour gagner du temps

*/


#ifndef _UTILS_
#define _UTILS_

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <math.h>

#define _MEMORY_SIZE_ 40

typedef struct{
    int score;
    int weight;
    int *id;
} Action;



typedef struct {
  double x;
  double y;

} Point;


double sigmoid (double x)
{
  double res;
  res = 1./(1-exp(-x));
  return res;
} 



float distance_euclidienne(Point a, Point b)
{
  float dist;
  dist = sqrt((pow(a.x,2)-pow(b.x,2))-(pow(a.y,2)-pow(b.y,2)));
  return dist;
}


char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}


void* malloc_p(size_t s){ //malloc protegé
  void *p;
  if(!(p = malloc(s))) {exit(EXIT_FAILURE);}

  return p;
}


#endif