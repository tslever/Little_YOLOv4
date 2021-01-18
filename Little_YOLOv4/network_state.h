
#ifndef NETWORK_STATE
#define NETWORK_STATE


#include "network.h"


typedef struct network_state {
    float* input;
    float* workspace;
    network net;
} network_state;


#endif