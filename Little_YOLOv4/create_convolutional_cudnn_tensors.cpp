
#include "layer.h"
#include "CHECK_CUDNN.h"


void create_convolutional_cudnn_tensors(layer* l)
{
    CHECK_CUDNN(cudnnCreateTensorDescriptor(&l->srcTensorDesc));
    CHECK_CUDNN(cudnnCreateTensorDescriptor(&l->dstTensorDesc));
    CHECK_CUDNN(cudnnCreateFilterDescriptor(&l->weightDesc));
    CHECK_CUDNN(cudnnCreateConvolutionDescriptor(&l->convDesc));
}