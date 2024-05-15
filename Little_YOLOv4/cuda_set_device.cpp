
#include <cuda_runtime.h>
#include "CHECK_CUDA.h"


void cuda_set_device(int n)
{
    cudaError_t status = cudaSetDevice(n);
    if (status != cudaSuccess) CHECK_CUDA(status);
}