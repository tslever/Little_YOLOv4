
#include <cuda_runtime.h>


#include "CHECK_CUDA.h"


int cuda_get_device()
{
    int n = 0;
    cudaError_t status = cudaGetDevice(&n);
    CHECK_CUDA(status);
    return n;
}