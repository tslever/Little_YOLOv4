
#include "layer.h"
#include "forward_upsample_layer_gpu.h"
#include "cuda_make_array.h"
#include <stdio.h>


layer make_upsample_layer(int batch, int w, int h, int c, int stride)
{
    layer l = { (LAYER_TYPE)0 };
    l.type = UPSAMPLE;
    l.batch = batch;
    l.w = w;
    l.h = h;
    l.c = c;
    l.out_w = w * stride;
    l.out_h = h * stride;
    l.out_c = c;
    l.stride = stride;
    l.outputs = l.out_w * l.out_h * l.out_c;
    l.forward_gpu = forward_upsample_layer_gpu;
    l.output_gpu = cuda_make_array(l.output, l.outputs * batch);
    fprintf(stderr, "upsample                %2dx  %4d x%4d x%4d -> %4d x%4d x%4d\n", stride, w, h, c, l.out_w, l.out_h, l.out_c);
    return l;
}