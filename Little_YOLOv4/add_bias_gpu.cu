
#include "get_number_of_blocks.h"
#include "BLOCK.h"
#include "add_bias_kernel.cuh"
#include "get_cuda_stream.h"
#include "CHECK_CUDA.h"


void add_bias_gpu(float* output, float* biases, int batch, int filters, int spatial)
{
    const int current_size = batch * filters * spatial;
    const int num_blocks = get_number_of_blocks(current_size, BLOCK);

    add_bias_kernel<<<num_blocks, BLOCK, 0, get_cuda_stream()>>>
        (output, biases, batch, filters, spatial, current_size);
    CHECK_CUDA(cudaPeekAtLastError());
}