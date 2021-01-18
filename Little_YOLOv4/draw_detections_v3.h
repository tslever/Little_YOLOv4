
#ifndef DRAW_DETECTIONS_V3
#define DRAW_DETECTIONS_V3


#include "image.h"
#include "detection.h"


void draw_detections_v3(
	image im,
	detection* dets,
	int num,
	float thresh,
	char** names,
	image** alphabet,
	int classes);


#endif