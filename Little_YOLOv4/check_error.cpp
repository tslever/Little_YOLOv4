
#include <cuda_runtime.h>
#include <stdio.h>
#include "error.h"


void check_error(cudaError_t status)
{
    cudaError_t status2 = cudaGetLastError();
    if (status != cudaSuccess)
    {
        const char* s = cudaGetErrorString(status);
        char buffer[256];
        printf("\n CUDA Error: %s\n", s);
        snprintf(buffer, 256, "CUDA Error: %s", s);
#ifdef WIN32
        getchar();
#endif
        error(buffer);
    }
    if (status2 != cudaSuccess)
    {
        const char* s = cudaGetErrorString(status2);
        char buffer[256];
        printf("\n CUDA Error Prev: %s\n", s);
        snprintf(buffer, 256, "CUDA Error Prev: %s", s);
#ifdef WIN32
        getchar();
#endif
        error(buffer);
    }
}