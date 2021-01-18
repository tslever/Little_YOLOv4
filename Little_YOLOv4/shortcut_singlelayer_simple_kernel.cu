
#include <device_launch_parameters.h>
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
	WEIGHTS_NORMALIZATION weights_normalization)
{
    const int id = (blockIdx.x + blockIdx.y * gridDim.x) * blockDim.x + threadIdx.x;
    if (id >= size) return;

    int src_id = id;
    const int src_i = src_id % src_outputs;
    src_id /= src_outputs;
    int src_b = src_id;

    float out_val = in[id];

    int add_outputs = outputs_of_layers_gpu[0];
    if (src_i < add_outputs) {
        int add_index = add_outputs * src_b + src_i;

        float* add = layers_output_gpu[0];
        out_val += add[add_index];
    }
    out[id] = out_val;
}