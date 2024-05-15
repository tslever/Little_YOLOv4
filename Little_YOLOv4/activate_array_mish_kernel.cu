
#include "device_launch_parameters.h"


__device__ float mish_yashas(float x)
{
    float e = __expf(x);
    if (x <= -18.0f)
        return x * e;

    float n = e * e + 2 * e;
    if (x <= -5.0f)
        return x * __fdividef(n, n + 2);

    return x - 2 * __fdividef(x, n + 2);
}


__global__ void activate_array_mish_kernel(
    float* x, int n, float* activation_input, float* output_gpu)
{
    int i = (blockIdx.x + blockIdx.y * gridDim.x) * blockDim.x + threadIdx.x;
    if (i < n) {
        const float MISH_THRESHOLD = 20;
        float x_val = x[i];
        output_gpu[i] = mish_yashas(x_val);
    }
}