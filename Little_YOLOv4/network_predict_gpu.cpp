
#include "network.h"
#include "get_network_input_size.h"
#include "network_state.h"
#include <string.h>
#include "cuda_push_array.h"
#include "forward_network_gpu.h"
#include "get_network_output_gpu.h"


float* network_predict_gpu(network net, float* input)
{
    int size = get_network_input_size(net) * net.batch;
    network_state state;
    state.net = net;
    state.input = net.input_state_gpu;
    memcpy(net.input_pinned_cpu, input, size * sizeof(float));
    cuda_push_array(state.input, net.input_pinned_cpu, size);
    forward_network_gpu(net, state);
    float* out = get_network_output_gpu(net);
    return out;
}