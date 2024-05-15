
#ifndef SIZE_PARAMS
#define SIZE_PARAMS


#include "network.h"


typedef struct size_params {
    int batch;
    int inputs;
    int h;
    int w;
    int c;
    int index;
    int time_steps;
    int train;
    network net;
} size_params;


#endif