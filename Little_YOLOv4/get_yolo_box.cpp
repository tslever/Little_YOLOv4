
#include "box.h"
#include "math.h"


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
	int stride)
{
	box b;
	b.x = (i + x[index + 0 * stride]) / lw;
	b.y = (j + x[index + 1 * stride]) / lh;
	b.w = exp(x[index + 2 * stride]) * biases[2 * n] / w;
	b.h = exp(x[index + 3 * stride]) * biases[2 * n + 1] / h;
	return b;
}