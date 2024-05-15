
#include "layer.h"
#include "forward_route_layer_gpu.h"
#include "cuda_make_array.h"


layer make_route_layer(
    int batch, int n, int* input_layers, int* input_sizes, int groups, int group_id)
{
    layer l = { (LAYER_TYPE)0 };
    l.type = ROUTE;
    l.batch = batch;
    l.n = n;
    l.input_layers = input_layers;
    l.input_sizes = input_sizes;
    l.groups = groups;
    int outputs = 0;
    for (int i = 0; i < n; ++i) {
        outputs += input_sizes[i];
    }
    l.forward_gpu = forward_route_layer_gpu;
    l.output_gpu = cuda_make_array(l.output, outputs * batch);
    return l;
}