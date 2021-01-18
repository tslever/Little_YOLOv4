
#include <cudnn.h>
#include <stdio.h>
#include "error.h"


void cudnn_check_error(cudnnStatus_t status)
{
    int cuda_debug_sync = 0;
#if defined(DEBUG) || defined(CUDA_DEBUG)
    cudaDeviceSynchronize();
    cuda_debug_sync = 1;
#endif
    if (cuda_debug_sync) {
        cudaDeviceSynchronize();
    }
    cudnnStatus_t status2 = CUDNN_STATUS_SUCCESS;
#ifdef CUDNN_ERRQUERY_RAWCODE
    cudnnStatus_t status_tmp = cudnnQueryRuntimeError(cudnn_handle(), &status2, CUDNN_ERRQUERY_RAWCODE, NULL);
#endif
    if (status != CUDNN_STATUS_SUCCESS)
    {
        const char* s = cudnnGetErrorString(status);
        char buffer[256];
        printf("\n cuDNN Error: %s\n", s);
        snprintf(buffer, 256, "cuDNN Error: %s", s);
#ifdef WIN32
        getchar();
#endif
        error(buffer);
    }
    if (status2 != CUDNN_STATUS_SUCCESS)
    {
        const char* s = cudnnGetErrorString(status2);
        char buffer[256];
        printf("\n cuDNN Error Prev: %s\n", s);
        snprintf(buffer, 256, "cuDNN Error Prev: %s", s);
#ifdef WIN32
        getchar();
#endif
        error(buffer);
    }
}