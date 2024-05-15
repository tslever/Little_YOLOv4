
#include "layer.h"
#include "xcalloc.h"
#include "forward_yolo_layer_gpu.h"
#include "cuda_make_array.h"


layer make_yolo_layer(
    int batch, int w, int h, int n, int total, int* mask, int classes, int max_boxes)
{
    int i;
    layer l = { (LAYER_TYPE)0 };
    l.type = YOLO;
    l.n = n;
    //l.total = total;
    l.batch = batch;
    l.h = h;
    l.w = w;
    l.classes = classes;
    l.biases = (float*)xcalloc(total * 2, sizeof(float));
    l.mask = mask;
    l.outputs = h * w * n * (classes + 4 + 1);
    l.inputs = l.outputs;
    l.forward_gpu = forward_yolo_layer_gpu;
    l.output_gpu = cuda_make_array(l.output, batch * l.outputs);
    if (cudaSuccess == cudaHostAlloc(&l.output, batch * l.outputs * sizeof(float), cudaHostRegisterMapped)) l.output_pinned = 1;

    return l;
}