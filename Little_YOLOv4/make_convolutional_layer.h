
#ifndef MAKE_CONVOLUTIONAL_LAYER
#define MAKE_CONVOLUTIONAL_LAYER


#include "layer.h"


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
	int train);


#endif