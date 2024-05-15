
#include <cuda_runtime.h>
#include "CHECK_CUDA.h"


void cuda_free(float* x_gpu)
{
    cudaError_t status = cudaFree(x_gpu);
    CHECK_CUDA(status);
}