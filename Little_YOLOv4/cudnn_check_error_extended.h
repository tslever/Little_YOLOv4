
#ifndef CUDNN_CHECK_ERROR_EXTENDED
#define CUDNN_CHECK_ERROR_EXTENDED


#include <cudnn.h>


void cudnn_check_error_extended(
	cudnnStatus_t status, const char* file, int line, const char* date_time);


#endif