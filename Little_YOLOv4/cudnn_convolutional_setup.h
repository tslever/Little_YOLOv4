
#ifndef CUDNN_CONVOLUTIONAL_SETUP
#define CUDNN_CONVOLUTIONAL_SETUP


#include "layer.h"


void cudnn_convolutional_setup(
	layer* l, int cudnn_preference, size_t workspace_size_specify);


#endif