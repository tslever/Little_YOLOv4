
#ifndef DIOUNMS_SORT
#define DIOUNMS_SORT


#include "detection.h"
#include "NMS_KIND.h"


void diounms_sort(
    detection* dets,
    int total,
    int classes,
    float thresh,
    NMS_KIND nms_kind,
    float beta1);


#endif