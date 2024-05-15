
#ifndef MAKE_YOLO_LAYER
#define MAKE_YOLO_LAYER


#include "layer.h"


layer make_yolo_layer(
	int batch, int w, int h, int n, int total, int* mask, int classes, int max_boxes);


#endif