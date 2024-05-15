
#include "network.h"
#include "cuda_pull_array.h"


float* get_network_output_layer_gpu(network net, int i)
{
    layer l = net.layers[i];
    cuda_pull_array(l.output_gpu, l.output, l.outputs * l.batch);
    return l.output;
}