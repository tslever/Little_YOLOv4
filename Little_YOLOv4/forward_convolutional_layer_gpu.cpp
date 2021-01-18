
#include "layer.h"
#include "network_state.h"
#include "CHECK_CUDNN.h"
#include "cudnn_handle.h"
#include "add_bias_gpu.cuh"
#include "activate_array_ongpu.cuh"


void forward_convolutional_layer_gpu(layer l, network_state state)
{
    float alpha = 1;
    float beta = 0;

    CHECK_CUDNN(cudnnConvolutionForward(
        cudnn_handle(),
        &alpha,
        l.srcTensorDesc,
        state.input,
        l.weightDesc,
        l.weights_gpu,
        l.convDesc,
        l.fw_algo,
        state.workspace,
        l.workspace_size,
        &beta,
        l.dstTensorDesc,
        l.output_gpu));

    add_bias_gpu(l.output_gpu, l.biases_gpu, l.batch, l.n, l.out_w * l.out_h);

    activate_array_ongpu(l.output_gpu, l.outputs * l.batch, l.activation);
}