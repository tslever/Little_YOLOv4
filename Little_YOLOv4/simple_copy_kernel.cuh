
#ifndef SIMPLE_COPY_KERNEL
#define SIMPLE_COPY_KERNEL


#include <cuda_runtime.h>


__global__ void simple_copy_kernel(int size, float* src, float* dst);


#endif