
#include "detection.h"
#include "network.h"
#include "num_detections.h"
#include "xcalloc.h"


detection* make_network_boxes(network* net, float thresh, int* num)
{
    layer l = net->layers[net->n - 1];
    int i;
    int nboxes = num_detections(net, thresh);
    if (num) *num = nboxes;
    detection* dets = (detection*)xcalloc(nboxes, sizeof(detection));
    for (i = 0; i < nboxes; ++i) {
        dets[i].prob = (float*)xcalloc(l.classes, sizeof(float));
        dets[i].uc = NULL;
        dets[i].mask = NULL;
    }
    return dets;
}