
#ifndef SHORTCUT_MULTILAYER_GPU
#define SHORTCUT_MULTILAYER_GPU


#include "WEIGHTS_NORMALIZATION.h"


void shortcut_multilayer_gpu(
    int src_outputs,
    int batch,
    int n,
    int* outputs_of_layers_gpu,
    float** layers_output_gpu,
    float* out,
    float* in,
    float* weights_gpu,
    int nweights,
    WEIGHTS_NORMALIZATION weights_normalization);


#endif