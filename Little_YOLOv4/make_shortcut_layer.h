
#ifndef MAKE_SHORTCUT_LAYER
#define MAKE_SHORTCUT_LAYER


#include "layer.h"


layer make_shortcut_layer(
    int batch,
    int n,
    int* input_layers,
    int* input_sizes,
    int w,
    int h,
    int c,
    float** layers_output,
    float** layers_delta,
    float** layers_output_gpu,
    float** layers_delta_gpu,
    WEIGHTS_NORMALIZATION weights_normalization,
    ACTIVATION activation,
    int train);


#endif