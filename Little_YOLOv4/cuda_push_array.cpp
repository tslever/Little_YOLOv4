
#include <cuda_runtime.h>
#include "get_cuda_stream.h"
#include "CHECK_CUDA.h"


void cuda_push_array(float* x_gpu, float* x, size_t n)
{
    size_t size = sizeof(float) * n;
    cudaError_t status = cudaMemcpyAsync(x_gpu, x, size, cudaMemcpyHostToDevice, get_cuda_stream());
    CHECK_CUDA(status);
}