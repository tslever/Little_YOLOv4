
#include <cuda_runtime.h>
#include "cuda_get_device.h"
#include "streamInit.h"
#include "streamsArray.h"
#include <stdio.h>
#include "CHECK_CUDA.h"


cudaStream_t get_cuda_stream() {
    int i = cuda_get_device();
    if (!streamInit[i]) {
        cudaError_t status = cudaStreamCreate(&streamsArray[i]);
        if (status != cudaSuccess) {
            printf(" cudaStreamCreate error: %d \n", status);
            const char* s = cudaGetErrorString(status);
            printf("CUDA Error: %s\n", s);
            status = cudaStreamCreateWithFlags(&streamsArray[i], cudaStreamDefault);
            CHECK_CUDA(status);
        }
        streamInit[i] = 1;
    }
    return streamsArray[i];
}