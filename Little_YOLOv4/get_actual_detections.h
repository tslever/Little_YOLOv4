
#ifndef GET_ACTUAL_DETECTIONS
#define GET_ACTUAL_DETECTIONS


#include "detection_with_class.h"


detection_with_class* get_actual_detections(
    detection* dets,
    int dets_num,
    float thresh,
    int* selected_detections_num,
    char** names);


#endif