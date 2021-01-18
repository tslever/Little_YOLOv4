
#include <device_launch_parameters.h>


__device__ float logistic_activate_kernel(float x) { return 1.f / (1.f + expf(-x)); }


__global__ void activate_array_logistic_kernel(float* x, int n)
{
    int index = blockIdx.x * blockDim.x + threadIdx.x;
    if (index < n) {
        x[index] = logistic_activate_kernel(x[index]);
    }
}
