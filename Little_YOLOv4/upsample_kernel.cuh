
#ifndef UPSAMPLE_KERNEL
#define UPSAMPLE_KERNEL


#include <cuda_runtime.h>


__global__ void upsample_kernel(
	size_t N,
	float* x,
	int w,
	int h,
	int c,
	int batch,
	int stride,
	int forward,
	float scale,
	float* out);


#endif