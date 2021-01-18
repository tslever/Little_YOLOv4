
#include "WEIGHTS_NORMALIZATION.h"
#include "shortcut_singlelayer_simple_kernel.cuh"
#include "cuda_gridsize.h"
#include "BLOCK.h"
#include "get_cuda_stream.h"
#include "CHECK_CUDA.h"


void shortcut_multilayer_gpu(
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
    int size = batch * src_outputs;
    shortcut_singlelayer_simple_kernel<<<cuda_gridsize(size), BLOCK, 0, get_cuda_stream()>>>
        (size,
         src_outputs,
         batch,
         n,
         outputs_of_layers_gpu,
         layers_output_gpu,
         out,
         in,
         weights_gpu,
         nweights,
         weights_normalization);
    CHECK_CUDA(cudaPeekAtLastError());
}