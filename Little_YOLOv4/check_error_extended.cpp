
#include <cuda_runtime.h>
#include <stdio.h>
#include "check_error.h"


void check_error_extended(cudaError_t status, const char* file, int line, const char* date_time)
{
    if (status != cudaSuccess) {
        printf("CUDA status Error: file: %s() : line: %d : build time: %s \n", file, line, date_time);
        check_error(status);
    }
    int cuda_debug_sync = 0;
#if defined(DEBUG) || defined(CUDA_DEBUG)
    cuda_debug_sync = 1;
#endif
    if (cuda_debug_sync) {
        status = cudaDeviceSynchronize();
        if (status != cudaSuccess)
            printf("CUDA status = cudaDeviceSynchronize() Error: file: %s() : line: %d : build time: %s \n", file, line, date_time);
    }
    check_error(status);
}