
#include "network.h"
#include "xcalloc.h"


network make_network(int n)
{
    network net = { 0 };
    net.n = n;
    net.layers = (layer*)xcalloc(n, sizeof(layer));
    return net;
}