
#ifndef DETECTION
#define DETECTION


#include "box.h"


typedef struct detection {
    box bbox;
    int classes;
    float* prob;
    float* mask;
    float objectness;
    int sort_class;
    float* uc;
    int points;
} detection;


#endif