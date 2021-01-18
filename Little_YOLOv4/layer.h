
#ifndef LAYER
#define LAYER


#include "LAYER_TYPE.h"
#include "ACTIVATION.h"
#include "WEIGHTS_NORMALIZATION.h"
#include "NMS_KIND.h"
#include <cudnn.h>


typedef struct layer {
    LAYER_TYPE type;
    ACTIVATION activation;
    void(*forward_gpu)   (struct layer, struct network_state);
    int batch_normalize;
    int batch;
    int inputs;
    int outputs;
    int nweights;
    int h;
    int w;
    int c;
    int out_h;
    int out_w;
    int out_c;
    int n;
    int groups;
    int group_id;
    int size;
    int stride;
    int stride_x;
    int stride_y;
    int dilation;
    int pad;
    int classes;
    int* mask;
    float bflops;
    float scale;
    int* input_layers;
    int* input_sizes;
    WEIGHTS_NORMALIZATION weights_normalization;
    float* biases;
    float* scales;
    float* weights;
    NMS_KIND nms_kind;
    float beta_nms;
    float* output;
    int output_pinned;
    float* rolling_mean;
    float* rolling_variance;
    size_t workspace_size;
    int* indexes_gpu;
    float* weights_gpu;
    float* biases_gpu;
    float* output_gpu;
    int* input_sizes_gpu;
    float** layers_output_gpu;
    cudnnTensorDescriptor_t srcTensorDesc, dstTensorDesc;
    cudnnFilterDescriptor_t weightDesc;
    cudnnConvolutionDescriptor_t convDesc;
    cudnnConvolutionFwdAlgo_t fw_algo;
    cudnnPoolingDescriptor_t poolingDesc;
} layer;


#endif