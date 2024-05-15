
#include <device_launch_parameters.h>


__global__ void add_bias_kernel(
    float* output, float* biases, int batch, int filters, int spatial, int current_size)
{
    const int index = blockIdx.x * blockDim.x + threadIdx.x;
    if (index >= current_size) return;

    int f = (index / spatial) % filters;
    output[index] += biases[f];
}