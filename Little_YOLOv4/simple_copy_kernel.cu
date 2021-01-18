
#include <device_launch_parameters.h>


__global__ void simple_copy_kernel(int size, float* src, float* dst)
{
    int index = blockIdx.x * blockDim.x + threadIdx.x;
    if (index < size)
        dst[index] = src[index];
}