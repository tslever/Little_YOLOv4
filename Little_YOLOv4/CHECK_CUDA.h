
#ifndef CHECK_CUDA_H
#define CHECK_CUDA_H


#include "check_error_extended.h"


#define CHECK_CUDA(X) check_error_extended(X, __FILE__ " : " __FUNCTION__, __LINE__,  __DATE__ " - " __TIME__ );


#endif