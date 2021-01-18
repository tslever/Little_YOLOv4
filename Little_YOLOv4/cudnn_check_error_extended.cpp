
#include <cudnn.h>
#include <stdio.h>
#include "cudnn_check_error.h"


void cudnn_check_error_extended(
    cudnnStatus_t status, const char* file, int line, const char* date_time)
{
    if (status != CUDNN_STATUS_SUCCESS) {
        printf("\n cuDNN status Error in: file: %s() : line: %d : build time: %s \n", file, line, date_time);
        cudnn_check_error(status);
    }
    int cuda_debug_sync = 0;
#if defined(DEBUG) || defined(CUDA_DEBUG)
    cuda_debug_sync = 1;
#endif
    if (cuda_debug_sync) {
        cudaError_t status = cudaDeviceSynchronize();
        if (status != CUDNN_STATUS_SUCCESS)
            printf("\n cudaError_t status = cudaDeviceSynchronize() Error in: file: %s() : line: %d : build time: %s \n", file, line, date_time);
    }
    cudnn_check_error(status);
}