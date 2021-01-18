
#ifndef ADD_BIAS_KERNEL
#define ADD_BIAS_KERNEL


#include <cuda_runtime.h>


__global__ void add_bias_kernel(
	float* output, float* biases, int batch, int filters, int spatial, int current_size);


#endif