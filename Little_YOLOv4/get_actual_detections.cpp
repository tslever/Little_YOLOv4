
#include "detection_with_class.h"
#include "xcalloc.h"
#include <string.h>


detection_with_class* get_actual_detections(
    detection* dets,
    int dets_num,
    float thresh,
    int* selected_detections_num,
    char** names)
{
    int selected_num = 0;
    detection_with_class* result_arr = (detection_with_class*)xcalloc(dets_num, sizeof(detection_with_class));
    int i;
    for (i = 0; i < dets_num; ++i) {
        int best_class = -1;
        float best_class_prob = thresh;
        int j;
        for (j = 0; j < dets[i].classes; ++j) {
            int show = strncmp(names[j], "dont_show", 9);
            if (dets[i].prob[j] > best_class_prob && show) {
                best_class = j;
                best_class_prob = dets[i].prob[j];
            }
        }
        if (best_class >= 0) {
            result_arr[selected_num].det = dets[i];
            result_arr[selected_num].best_class = best_class;
            ++selected_num;
        }
    }
    if (selected_detections_num)
        *selected_detections_num = selected_num;
    return result_arr;
}