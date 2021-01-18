
#ifndef MAKE_ROUTE_LAYER
#define MAKE_ROUTE_LAYER


#include "layer.h"


layer make_route_layer(
    int batch, int n, int* input_layers, int* input_sizes, int groups, int group_id);


#endif