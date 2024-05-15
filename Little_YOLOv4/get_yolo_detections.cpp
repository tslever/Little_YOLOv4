
#include "layer.h"
#include "detection.h"
#include "entry_index.h"
#include "get_yolo_box.h"


int get_yolo_detections(
    layer l,
    int w,
    int h,
    int netw,
    int neth,
    float thresh,
    int* map,
    int relative,
    detection* dets)
{
    int i, j, n;
    float* predictions = l.output;
    int count = 0;
    for (i = 0; i < l.w * l.h; ++i) {
        int row = i / l.w;
        int col = i % l.w;
        for (n = 0; n < l.n; ++n) {
            int obj_index = entry_index(l, 0, n * l.w * l.h + i, 4);
            float objectness = predictions[obj_index];
            if (objectness > thresh) {
                int box_index = entry_index(l, 0, n * l.w * l.h + i, 0);
                dets[count].bbox = get_yolo_box(predictions, l.biases, l.mask[n], box_index, col, row, l.w, l.h, netw, neth, l.w * l.h);
                dets[count].objectness = objectness;
                dets[count].classes = l.classes;
                for (j = 0; j < l.classes; ++j) {
                    int class_index = entry_index(l, 0, n * l.w * l.h + i, 4 + 1 + j);
                    float prob = objectness * predictions[class_index];
                    dets[count].prob[j] = (prob > thresh) ? prob : 0;
                }
                ++count;
            }
        }
    }
    return count;
}