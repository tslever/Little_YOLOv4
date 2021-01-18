
#ifndef NETWORK
#define NETWORK


#include "layer.h"


typedef struct network {
    int n;
    int batch;
    layer* layers;
    int h;
    int w;
    int c;
    float* workspace;
    float* input_state_gpu;
    float* input_pinned_cpu;
} network;


#endif