
#include "layer.h"
#include "CHECK_CUDNN.h"
#include "cudnn_handle.h"


size_t get_workspace_size32(layer l)
{
    size_t s = 0;
    CHECK_CUDNN(cudnnGetConvolutionForwardWorkspaceSize(
        cudnn_handle(),
        l.srcTensorDesc,
        l.weightDesc,
        l.convDesc,
        l.dstTensorDesc,
        l.fw_algo,
        &s));
    return s;
}