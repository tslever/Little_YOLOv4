
#include "layer.h"
#include "xcalloc.h"
#include "convolutional_out_height.h"
#include "convolutional_out_width.h"
#include "forward_convolutional_layer_gpu.h"
#include "cuda_make_array.h"
#include "create_convolutional_cudnn_tensors.h"
#include "cudnn_convolutional_setup.h"
#include "get_convolutional_workspace_size.h"
#include <stdio.h>


layer make_convolutional_layer(
	int batch,
	int steps,
	int h,
	int w,
	int c,
	int n,
	int groups,
	int size,
	int stride_x,
	int stride_y,
	int dilation,
	int padding,
	ACTIVATION activation,
	int batch_normalize,
	int binary,
	int xnor,
	int use_bin_output,
	int index,
	int antialiasing,
	layer* share_layer,
	int assisted_excitation,
	int deform,
	int train)
{
    int total_batch = batch * steps;
    int i;
    layer l = { (LAYER_TYPE)0 };
    l.type = CONVOLUTIONAL;
    //l.index = index;
    l.h = h;
    l.w = w;
    l.c = c;
    l.groups = groups;
    l.n = n;
    l.batch = batch;
    l.stride_x = stride_x;
    l.stride_y = stride_y;
    l.dilation = dilation;
    l.size = size;
    l.pad = padding;
    l.batch_normalize = batch_normalize;
    l.nweights = (c / groups) * n * size * size;
    l.weights = (float*)xcalloc(l.nweights, sizeof(float));
    l.biases = (float*)xcalloc(n, sizeof(float));
    int out_h = convolutional_out_height(l);
    int out_w = convolutional_out_width(l);
    l.out_h = out_h;
    l.out_w = out_w;
    l.out_c = n;
    l.outputs = l.out_h * l.out_w * l.out_c;
    l.inputs = l.w * l.h * l.c;
    l.activation = activation;

    if (batch_normalize) {
        l.scales = (float*)xcalloc(n, sizeof(float));
        l.rolling_mean = (float*)xcalloc(n, sizeof(float));
        l.rolling_variance = (float*)xcalloc(n, sizeof(float));
    }

    l.forward_gpu = forward_convolutional_layer_gpu;
    l.weights_gpu = cuda_make_array(l.weights, l.nweights);
    l.biases_gpu = cuda_make_array(l.biases, n);
    l.output_gpu = cuda_make_array(l.output, total_batch * out_h * out_w * n);

    create_convolutional_cudnn_tensors(&l);
    cudnn_convolutional_setup(&l, /*cudnn_fastest=*/0, 0);

    l.workspace_size = get_convolutional_workspace_size(l);

    l.bflops = (2.0 * l.nweights * l.out_h * l.out_w) / 1000000000.;
    fprintf(stderr, "conv  ");
    fprintf(stderr, "%5d      ", n);
    fprintf(stderr, "%2d x%2d/%2d   ", size, size, stride_x);
    fprintf(stderr, "%4d x%4d x%4d -> %4d x%4d x%4d %5.3f BF\n", w, h, c, l.out_w, l.out_h, l.out_c, l.bflops);

    return l;
}