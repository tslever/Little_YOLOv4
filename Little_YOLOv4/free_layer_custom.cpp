
#include "layer.h"
#include <stdlib.h>
#include "cuda_free.h"
#include "CHECK_CUDNN.h"


void free_layer_custom(layer l, int keep_cudnn_desc)
{
    if (l.mask)               free(l.mask);
    if (l.input_layers)       free(l.input_layers);
    if (l.input_sizes)        free(l.input_sizes);
    if (l.biases)             free(l.biases), l.biases = NULL;
    if (l.scales)             free(l.scales), l.scales = NULL;
    if (l.weights)            free(l.weights), l.weights = NULL;

    if (l.output && l.output_pinned) {
        cudaFreeHost(l.output);
        l.output = NULL;
    }

    if (l.output)             free(l.output), l.output = NULL;
    if (l.rolling_mean)       free(l.rolling_mean), l.rolling_mean = NULL;
    if (l.rolling_variance)   free(l.rolling_variance), l.rolling_variance = NULL;
    if (l.indexes_gpu)           cuda_free((float*)l.indexes_gpu);
    if (l.weights_gpu)             cuda_free(l.weights_gpu), l.weights_gpu = NULL;
    if (l.biases_gpu)              cuda_free(l.biases_gpu), l.biases_gpu = NULL;
    if (l.input_sizes_gpu)         cuda_free((float*)l.input_sizes_gpu);

    if (l.layers_output_gpu)       cuda_free((float*)l.layers_output_gpu);

    if (!keep_cudnn_desc) {
        if (l.srcTensorDesc) CHECK_CUDNN(cudnnDestroyTensorDescriptor(l.srcTensorDesc));
        if (l.dstTensorDesc) CHECK_CUDNN(cudnnDestroyTensorDescriptor(l.dstTensorDesc));
        if (l.weightDesc) CHECK_CUDNN(cudnnDestroyFilterDescriptor(l.weightDesc));
        if (l.convDesc) CHECK_CUDNN(cudnnDestroyConvolutionDescriptor(l.convDesc));
        if (l.poolingDesc) CHECK_CUDNN(cudnnDestroyPoolingDescriptor(l.poolingDesc));
    }
}