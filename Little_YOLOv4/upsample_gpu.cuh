
#ifndef UPSAMPLE_GPU
#define UPSAMPLE_GPU


void upsample_gpu(
	float* in,
	int w,
	int h,
	int c,
	int batch,
	int stride,
	int forward,
	float scale,
	float* out);


#endif