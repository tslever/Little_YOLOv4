
#include <device_launch_parameters.h>


__device__ float leaky_activate_kernel(float x) { return (x > 0) ? x : .1f * x; }


__global__ void activate_array_leaky_kernel(float* x, int n)
{
    int index = blockIdx.x * blockDim.x + threadIdx.x;
    if (index < n) {
        x[index] = leaky_activate_kernel(x[index]);
    }
}