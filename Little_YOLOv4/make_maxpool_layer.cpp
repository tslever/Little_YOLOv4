
#include "layer.h"
#include "forward_maxpool_layer_gpu.cuh"
#include "cuda_make_array.h"
#include <stdio.h>


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
    int train)
{
    layer l = { (LAYER_TYPE)0 };
    l.type = MAXPOOL;
    const int blur_stride_x = stride_x;
    const int blur_stride_y = stride_y;
    l.batch = batch;
    l.h = h;
    l.w = w;
    l.c = c;
    l.pad = padding;
    l.out_w = (w + padding - size) / stride_x + 1;
    l.out_h = (h + padding - size) / stride_y + 1;
    l.out_c = c;
    l.outputs = l.out_h * l.out_w * l.out_c;
    l.size = size;
    l.stride_x = stride_x;
    l.stride_y = stride_y;
    int output_size = l.out_h * l.out_w * l.out_c * batch;
    l.forward_gpu = forward_maxpool_layer_gpu;
    l.output_gpu = cuda_make_array(l.output, output_size);
    l.bflops = (l.size * l.size * l.c * l.out_h * l.out_w) / 1000000000.;
    fprintf(stderr, "max               %2dx%2d/%2d   %4d x%4d x%4d -> %4d x%4d x%4d %5.3f BF\n", size, size, stride_x, w, h, c, l.out_w, l.out_h, l.out_c, l.bflops);
    return l;
}