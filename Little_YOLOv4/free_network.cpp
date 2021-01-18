
#include "network.h"
#include "free_layer.h"
#include <stdlib.h>
#include "cuda_free.h"


void free_network(network net)
{
    int i;
    for (i = 0; i < net.n; ++i) {
        free_layer(net.layers[i]);
    }
    free(net.layers);

    cuda_free(net.workspace);
    if (net.input_state_gpu) cuda_free(net.input_state_gpu);
    cudaFreeHost(net.input_pinned_cpu);
}