
#include "layer.h"
#include "network_state.h"
#include "upsample_gpu.cuh"


void forward_upsample_layer_gpu(const layer l, network_state state)
{
    upsample_gpu(state.input, l.w, l.h, l.c, l.batch, l.stride, 1, l.scale, l.output_gpu);
}