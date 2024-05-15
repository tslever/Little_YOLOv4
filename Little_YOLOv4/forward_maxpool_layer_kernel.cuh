
#ifndef FORWARD_MAXPOOL_LAYER_KERNEL
#define FORWARD_MAXPOOL_LAYER_KERNEL


#include <cuda_runtime.h>


__global__ void forward_maxpool_layer_kernel(
	int n,
	int in_h,
	int in_w,
	int in_c,
	int stride_x,
	int stride_y,
	int size,
	int pad,
	float* input,
	float* output,
	int* indexes);


#endif