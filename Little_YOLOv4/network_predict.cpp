
#include "network.h"
#include "network_predict_gpu.h"


float* network_predict(network net, float* input)
{
    return network_predict_gpu(net, input);
}