
#include "layer.h"
#include "network_state.h"
#include "simple_copy_ongpu.cuh"
#include "entry_index.h"
#include "activate_array_ongpu.cuh"
#include "cuda_pull_array_async.h"
#include "CHECK_CUDA.h"


void forward_yolo_layer_gpu(const layer l, network_state state)
{
    simple_copy_ongpu(l.batch * l.inputs, state.input, l.output_gpu);
    int b, n;
    for (b = 0; b < l.batch; ++b) {
        for (n = 0; n < l.n; ++n) {
            int index = entry_index(l, b, n * l.w * l.h, 0);
            activate_array_ongpu(l.output_gpu + index, 2 * l.w * l.h, LOGISTIC); // x,y
            index = entry_index(l, b, n * l.w * l.h, 4);
            activate_array_ongpu(l.output_gpu + index, (1 + l.classes) * l.w * l.h, LOGISTIC); // classes and objectness
        }
    }

    cuda_pull_array_async(l.output_gpu, l.output, l.batch * l.outputs);
    CHECK_CUDA(cudaPeekAtLastError());
}