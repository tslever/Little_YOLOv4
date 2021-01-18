
#include "layer.h"
#include "network_state.h"
#include "simple_copy_ongpu.cuh"


void forward_route_layer_gpu(const layer l, network_state state)
{
    int i, j;
    int offset = 0;
    for (i = 0; i < l.n; ++i) {
        int index = l.input_layers[i];
        float* input = state.net.layers[index].output_gpu;
        int input_size = l.input_sizes[i];
        int part_input_size = input_size / l.groups;
        for (j = 0; j < l.batch; ++j) {
            simple_copy_ongpu(input_size, input + j * input_size, l.output_gpu + offset + j * l.outputs);
            simple_copy_ongpu(part_input_size, input + j * input_size + part_input_size * l.group_id, l.output_gpu + offset + j * l.outputs);
        }
        offset += part_input_size;
    }
}