
#include "layer.h"
#include "forward_shortcut_layer_gpu.h"
#include "cuda_make_array.h"
#include "cuda_make_int_array_new_api.h"
#include "cuda_make_array_pointers.h"


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
    int train)
{
    layer l = { (LAYER_TYPE)0 };
    l.type = SHORTCUT;
    l.batch = batch;
    l.activation = activation;
    l.n = n;
    l.input_layers = input_layers;
    l.w = l.out_w = w;
    l.h = l.out_h = h;
    l.c = l.out_c = c;
    l.outputs = w * h * c;
    l.forward_gpu = forward_shortcut_layer_gpu;
    l.output_gpu = cuda_make_array(l.output, l.outputs * batch);
    l.input_sizes_gpu = cuda_make_int_array_new_api(input_sizes, l.n);
    l.layers_output_gpu = (float**)cuda_make_array_pointers((void**)layers_output_gpu, l.n);
    return l;
}