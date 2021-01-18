
#ifndef FILL_NETWORK_BOXES
#define FILL_NETWORK_BOXES


#include "network.h"
#include "detection.h"


void fill_network_boxes(
	network* net,
	int w,
	int h,
	float thresh,
	int* map,
	int relative,
	detection* dets);


#endif