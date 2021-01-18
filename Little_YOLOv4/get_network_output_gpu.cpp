
#include "network.h"
#include "get_network_output_layer_gpu.h"


float* get_network_output_gpu(network net)
{
    return get_network_output_layer_gpu(net, net.n - 1);
}