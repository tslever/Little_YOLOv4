
#include <cuda_runtime.h>
#include "BLOCK.h"
#include "math.h"


dim3 cuda_gridsize(size_t n)
{
    size_t k = (n - 1) / BLOCK + 1;
    size_t x = k;
    size_t y = 1;
    if (x > 65535) {
        x = ceil(sqrt(k));
        y = (n - 1) / (x * BLOCK) + 1;
    }

    dim3 d;
    d.x = x;
    d.y = y;
    d.z = 1;
    return d;
}