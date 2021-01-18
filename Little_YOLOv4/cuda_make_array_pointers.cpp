
#include <cuda_runtime.h>
#include <stdio.h>
#include "CHECK_CUDA.h"
#include "get_cuda_stream.h"
#include "error.h"


void** cuda_make_array_pointers(void** x, size_t n)
{
    void** x_gpu;
    size_t size = sizeof(void*) * n;
    cudaError_t status = cudaMalloc((void**)&x_gpu, size);
    if (status != cudaSuccess) fprintf(stderr, " Try to set subdivisions=64 in your cfg-file. \n");
    CHECK_CUDA(status);
    if (x) {
        status = cudaMemcpyAsync(x_gpu, x, size, cudaMemcpyDefault, get_cuda_stream());
        CHECK_CUDA(status);
    }
    if (!x_gpu) error("Cuda malloc failed\n");
    return x_gpu;
}