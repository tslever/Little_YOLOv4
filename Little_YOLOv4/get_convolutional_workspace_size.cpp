
#include "layer.h"
#include "get_workspace_size32.h"


size_t get_convolutional_workspace_size(layer l)
{
    size_t workspace_size = get_workspace_size32(l);
    return workspace_size;
}