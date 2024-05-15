
#ifndef CHECK_ERROR_EXTENDED
#define CHECK_ERROR_EXTENDED


#include <cuda_runtime.h>


void check_error_extended(
	cudaError_t status, const char* file, int line, const char* date_time);


#endif