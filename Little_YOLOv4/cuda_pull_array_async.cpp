
#include <cuda_runtime.h>
#include "get_cuda_stream.h"
#include "check_error.h"


void cuda_pull_array_async(float* x_gpu, float* x, size_t n)
{
    size_t size = sizeof(float) * n;
    cudaError_t status = cudaMemcpyAsync(x, x_gpu, size, cudaMemcpyDefault, get_cuda_stream());
    check_error(status);
}