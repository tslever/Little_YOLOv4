
#include "network.h"
#include "detection.h"
#include "get_yolo_detections.h"
#include <stdio.h>


void fill_network_boxes(
    network* net,
    int w,
    int h,
    float thresh,
    int* map,
    int relative,
    detection* dets)
{
    int prev_classes = -1;
    layer l;
    for (int i = 0; i < net->n; ++i) {
        l = net->layers[i];
        if (l.type == YOLO) {
            int count = get_yolo_detections(l, w, h, net->w, net->h, thresh, map, relative, dets);
            dets += count;
            if (prev_classes < 0) prev_classes = l.classes;
            else if (prev_classes != l.classes) {
                printf(" Error: Different [yolo] layers have different number of classes = %d and %d - check your cfg-file! \n",
                    prev_classes, l.classes);
            }
        }
    }
}