
#ifndef GET_NETWORK_BOXES
#define GET_NETWORK_BOXES


#include "detection.h"
#include "network.h"


detection* get_network_boxes(
	network* net,
	int w,
	int h,
	float thresh,
	int* map,
	int relative,
	int* num);


#endif