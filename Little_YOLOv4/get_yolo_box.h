
#ifndef GET_YOLO_BOX
#define GET_YOLO_BOX


#include "box.h"


box get_yolo_box(
	float* x,
	float* biases,
	int n,
	int index,
	int i,
	int j,
	int lw,
	int lh,
	int w,
	int h,
	int stride);


#endif