
#ifndef ACTIVATE_ARRAY_LEAKY_KERNEL
#define ACTIVATE_ARRAY_LEAKY_KERNEL


#include <cuda_runtime.h>


__global__ void activate_array_leaky_kernel(float* x, int n);


#endif