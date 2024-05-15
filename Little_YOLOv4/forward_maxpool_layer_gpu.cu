
#include "layer.h"
#include "network_state.h"
#include "forward_maxpool_layer_kernel.cuh"
#include "cuda_gridsize.h"
#include "BLOCK.h"
#include "get_cuda_stream.h"
#include "CHECK_CUDA.h"


void forward_maxpool_layer_gpu(layer layer, network_state state)
{
    int h = layer.out_h;
    int w = layer.out_w;
    int c = layer.out_c;
    size_t n = h * w * c * layer.batch;
    forward_maxpool_layer_kernel<<<cuda_gridsize(n), BLOCK, 0, get_cuda_stream()>>>
        (n,
         layer.h,
         layer.w,
         layer.c,
         layer.stride_x,
         layer.stride_y,
         layer.size,
         layer.pad,
         state.input,
         layer.output_gpu,
         layer.indexes_gpu);
    CHECK_CUDA(cudaPeekAtLastError());
}