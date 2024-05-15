
#include "layer.h"
#include "network_state.h"
#include "shortcut_multilayer_gpu.cuh"


void forward_shortcut_layer_gpu(const layer l, network_state state)
{
    shortcut_multilayer_gpu(
        l.outputs,
        l.batch,
        l.n,
        l.input_sizes_gpu,
        l.layers_output_gpu,
        l.output_gpu,
        state.input,
        l.weights_gpu,
        l.nweights,
        l.weights_normalization);
}