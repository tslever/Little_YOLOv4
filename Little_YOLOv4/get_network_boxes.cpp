
#include "detection.h"
#include "network.h"
#include "make_network_boxes.h"
#include "fill_network_boxes.h"


detection* get_network_boxes(
	network* net,
	int w,
	int h,
	float thresh,
	int* map,
	int relative,
	int* num)
{
	detection* dets = make_network_boxes(net, thresh, num);
	fill_network_boxes(net, w, h, thresh, map, relative, dets);
	return dets;
}