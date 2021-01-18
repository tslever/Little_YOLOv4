
#include "layer.h"


int convolutional_out_width(layer l)
{
    return (l.w + 2 * l.pad - l.size) / l.stride_x + 1;
}