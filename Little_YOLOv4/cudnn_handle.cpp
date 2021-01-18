
#include <cudnn.h>
#include "cuda_get_device.h"
#include "get_cuda_stream.h"
#include "CHECK_CUDNN.h"


cudnnHandle_t cudnn_handle()
{
    static int init[16] = { 0 };
    static cudnnHandle_t handle[16];
    int i = cuda_get_device();
    if (!init[i]) {
        cudnnCreate(&handle[i]);
        init[i] = 1;
        cudnnStatus_t status = cudnnSetStream(handle[i], get_cuda_stream());
        CHECK_CUDNN(status);
    }
    return handle[i];
}