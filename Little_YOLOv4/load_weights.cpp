
#include "network.h"
#include "load_weights_upto.h"


void load_weights(network* net, char* filename)
{
    load_weights_upto(net, filename, net->n);
}