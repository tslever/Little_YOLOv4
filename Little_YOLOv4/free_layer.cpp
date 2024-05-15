
#include "layer.h"
#include "free_layer_custom.h"


void free_layer(layer l)
{
    free_layer_custom(l, 0);
}