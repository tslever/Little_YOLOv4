
#ifndef ACTIVATE_ARRAY_MISH_KERNEL
#define ACTIVATE_ARRAY_MISH_KERNEL


#include <cuda_runtime.h>


__global__ void activate_array_mish_kernel(
	float* x, int n, float* activation_input, float* output_gpu);


#endif