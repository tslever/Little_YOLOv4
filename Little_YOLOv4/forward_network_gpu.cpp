
#include "network.h"
#include "network_state.h"


void forward_network_gpu(network net, network_state state)
{
    state.workspace = net.workspace;
    for (int i = 0; i < net.n; ++i) {
        layer l = net.layers[i];
        l.forward_gpu(l, state);
        state.input = l.output_gpu;
    }
}