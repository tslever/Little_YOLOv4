
#ifndef SHORTCUT_SINGLELAYER_SIMPLE_KERNEL
#define SHORTCUT_SINGLELAYER_SIMPLE_KERNEL


#include <cuda_runtime.h>
#include "WEIGHTS_NORMALIZATION.h"


__global__ void shortcut_singlelayer_simple_kernel(
	int size,
	int src_outputs,
	int batch,
	int n,
	int* outputs_of_layers_gpu,
	float** layers_output_gpu,
	float* out,
	float* in,
	float* weights_gpu,
	int nweights,
	WEIGHTS_NORMALIZATION weights_normalization);


#endif