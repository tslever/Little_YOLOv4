
#ifndef DETECTION_WITH_CLASS
#define DETECTION_WITH_CLASS


#include "detection.h"


typedef struct detection_with_class {
	detection det;
	int best_class;
} detection_with_class;


#endif