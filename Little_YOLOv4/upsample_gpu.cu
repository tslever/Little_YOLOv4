
#include "upsample_kernel.cuh"
#include "cuda_gridsize.h"
#include "BLOCK.h"
#include "get_cuda_stream.h"
#include "CHECK_CUDA.h"


void upsample_gpu(
	float* in,
	int w,
	int h,
	int c,
	int batch,
	int stride,
	int forward,
	float scale,
	float* out)
{
	size_t size = w * h * c * batch * stride * stride;
	upsample_kernel<<<cuda_gridsize(size), BLOCK, 0, get_cuda_stream()>>>
		(size, in, w, h, c, batch, stride, forward, scale, out);
	CHECK_CUDA(cudaPeekAtLastError());
}