
#include "network.h"
#include "yolo_num_detections.h"


int num_detections(network* net, float thresh)
{
    int s = 0;
    layer l;
    for (int i = 0; i < net->n; ++i) {
        l = net->layers[i];
        if (l.type == YOLO) {
            s += yolo_num_detections(l, thresh);
        }
    }
    return s;
}