
#include "BLOCK.h"
#include "simple_copy_kernel.cuh"
#include "get_cuda_stream.h"
#include "CHECK_CUDA.h"


void simple_copy_ongpu(int size, float* src, float* dst)
{
    const int num_blocks = size / BLOCK + 1;
    simple_copy_kernel<<<num_blocks, BLOCK, 0, get_cuda_stream()>>>(size, src, dst);
    CHECK_CUDA(cudaPeekAtLastError());
}