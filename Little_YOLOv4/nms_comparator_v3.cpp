
#include "detection.h"


int nms_comparator_v3(const void* pa, const void* pb)
{
    detection a = *(detection*)pa;
    detection b = *(detection*)pb;
    float diff = 0;
    if (b.sort_class >= 0) {
        diff = a.prob[b.sort_class] - b.prob[b.sort_class];
    }
    else {
        diff = a.objectness - b.objectness;
    }
    if (diff < 0) return 1;
    else if (diff > 0) return -1;
    return 0;
}