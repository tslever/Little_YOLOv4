
#ifndef MAKE_MAXPOOL_LAYER
#define MAKE_MAXPOOL_LAYER


#include "layer.h"


layer make_maxpool_layer(
    int batch,
    int h,
    int w,
    int c,
    int size,
    int stride_x,
    int stride_y,
    int padding,
    int maxpool_depth,
    int out_channels,
    int antialiasing,
    int avgpool,
    int train);


#endif