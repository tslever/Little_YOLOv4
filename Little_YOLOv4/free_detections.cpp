
#include "detection.h"
#include <stdlib.h>


void free_detections(detection* dets, int n)
{
    int i;
    for (i = 0; i < n; ++i) {
        free(dets[i].prob);
        if (dets[i].uc) free(dets[i].uc);
        if (dets[i].mask) free(dets[i].mask);
    }
    free(dets);
}