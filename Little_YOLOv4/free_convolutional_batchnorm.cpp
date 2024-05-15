
#include "layer.h"
#include <stdlib.h>


void free_convolutional_batchnorm(layer* l)
{
    if (l->scales) free(l->scales), l->scales = NULL;
    if (l->rolling_mean) free(l->rolling_mean), l->rolling_mean = NULL;
    if (l->rolling_variance) free(l->rolling_variance), l->rolling_variance = NULL;
}