
#ifndef GET_YOLO_DETECTIONS
#define GET_YOLO_DETECTIONS


#include "layer.h"
#include "detection.h"


int get_yolo_detections(
	layer l,
	int w,
	int h,
	int netw,
	int neth,
	float thresh,
	int* map,
	int relative,
	detection* dets);


#endif