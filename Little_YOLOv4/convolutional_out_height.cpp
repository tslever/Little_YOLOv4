
#include "layer.h"


int convolutional_out_height(layer l)
{
    return (l.h + 2 * l.pad - l.size) / l.stride_y + 1;
}