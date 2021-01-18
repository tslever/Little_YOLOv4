
#ifndef CHECK_CUDNN_H
#define CHECK_CUDNN_H


#include "cudnn_check_error_extended.h"


#define CHECK_CUDNN(X) cudnn_check_error_extended(X, __FILE__ " : " __FUNCTION__, __LINE__,  __DATE__ " - " __TIME__ );


#endif