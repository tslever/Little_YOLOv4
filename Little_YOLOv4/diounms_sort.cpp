
#include "detection.h"
#include "NMS_KIND.h"
#include <stdlib.h>
#include "nms_comparator_v3.h"
#include "box_iou.h"


void diounms_sort(
    detection* dets,
    int total,
    int classes,
    float thresh,
    NMS_KIND nms_kind,
    float beta1)
{
    int i, j, k;
    k = total - 1;
    for (i = 0; i <= k; ++i) {
        if (dets[i].objectness == 0) {
            detection swap = dets[i];
            dets[i] = dets[k];
            dets[k] = swap;
            --k;
            --i;
        }
    }
    total = k + 1;

    for (k = 0; k < classes; ++k) {
        for (i = 0; i < total; ++i) {
            dets[i].sort_class = k;
        }
        qsort(dets, total, sizeof(detection), nms_comparator_v3);
        for (i = 0; i < total; ++i)
        {
            if (dets[i].prob[k] == 0) continue;
            box a = dets[i].bbox;
            for (j = i + 1; j < total; ++j) {
                box b = dets[j].bbox;
                if (box_iou(a, b) > thresh && nms_kind == GREEDY_NMS) {
                    dets[j].prob[k] = 0;
                }
            }
        }
    }
}