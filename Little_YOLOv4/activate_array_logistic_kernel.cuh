
#ifndef ACTIVATE_ARRAY_LOGISTIC_KERNEL
#define ACTIVATE_ARRAY_LOGISTIC_KERNEL


#include <cuda_runtime.h>


__global__ void activate_array_logistic_kernel(float* x, int n);


#endif