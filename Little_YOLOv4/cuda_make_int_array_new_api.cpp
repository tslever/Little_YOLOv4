
#include <cuda_runtime.h>
#include "CHECK_CUDA.h"
#include "get_cuda_stream.h"
#include "error.h"


int* cuda_make_int_array_new_api(int* x, size_t n)
{
    int* x_gpu;
    size_t size = sizeof(int) * n;
    cudaError_t status = cudaMalloc((void**)&x_gpu, size);
    CHECK_CUDA(status);
    if (x) {
        cudaError_t status = cudaMemcpyAsync(x_gpu, x, size, cudaMemcpyHostToDevice, get_cuda_stream());
        CHECK_CUDA(status);
    }
    if (!x_gpu) error("Cuda malloc failed\n");
    return x_gpu;
}