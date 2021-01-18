
#include "layer.h"
#include "CHECK_CUDNN.h"
#include "cudnn_handle.h"


void cudnn_convolutional_setup(
    layer* l, int cudnn_preference, size_t workspace_size_specify)
{
    cudnnDataType_t data_type = CUDNN_DATA_FLOAT;
    int forward_algo = CUDNN_CONVOLUTION_FWD_PREFER_FASTEST;
    CHECK_CUDNN(cudnnSetTensor4dDescriptor(l->srcTensorDesc, CUDNN_TENSOR_NCHW, data_type, l->batch, l->c, l->h, l->w));
    CHECK_CUDNN(cudnnSetTensor4dDescriptor(l->dstTensorDesc, CUDNN_TENSOR_NCHW, data_type, l->batch, l->out_c, l->out_h, l->out_w));
    CHECK_CUDNN(cudnnSetFilter4dDescriptor(l->weightDesc, data_type, CUDNN_TENSOR_NCHW, l->n, l->c / l->groups, l->size, l->size));
    CHECK_CUDNN(cudnnSetConvolution2dDescriptor(l->convDesc, l->pad * l->dilation, l->pad * l->dilation, l->stride_y, l->stride_x, l->dilation, l->dilation, CUDNN_CROSS_CORRELATION, CUDNN_DATA_FLOAT));    // cudnn >= 6.0
    CHECK_CUDNN(cudnnGetConvolutionForwardAlgorithm(
        cudnn_handle(),
        l->srcTensorDesc,
        l->weightDesc,
        l->convDesc,
        l->dstTensorDesc,
        (cudnnConvolutionFwdPreference_t)forward_algo,
        workspace_size_specify,
        &l->fw_algo));
}