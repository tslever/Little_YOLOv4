
#include "ACTIVATION.h"
#include "get_number_of_blocks.h"
#include "BLOCK.h"
#include "activate_array_mish_kernel.cuh"
#include "cuda_gridsize.h"
#include "get_cuda_stream.h"
#include "activate_array_leaky_kernel.cuh"
#include "activate_array_logistic_kernel.cuh"
#include "CHECK_CUDA.h"


void activate_array_ongpu(float* x, int n, ACTIVATION a)
{
    int num_blocks = get_number_of_blocks(n, BLOCK);
    if (a == MISH) activate_array_mish_kernel<<<cuda_gridsize(n), BLOCK, 0, get_cuda_stream()>>>(x, n, nullptr, x);
    else if (a == LEAKY) activate_array_leaky_kernel << <num_blocks, BLOCK, 0, get_cuda_stream() >> > (x, n);
    else if (a == LOGISTIC) activate_array_logistic_kernel << <num_blocks, BLOCK, 0, get_cuda_stream() >> > (x, n);
    CHECK_CUDA(cudaPeekAtLastError());
}