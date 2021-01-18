
#include "layer.h"
#include "list.h"
#include "size_params.h"
#include "option_find_int.h"
#include "option_find_str.h"
#include "parse_yolo_mask.h"
#include "make_yolo_layer.h"
#include "option_find_str.h"
#include <stdio.h>
#include "option_find_float.h"
#include <string.h>
#include <stdlib.h>


layer parse_yolo(list* options, size_params params)
{
    int classes = option_find_int(options, "classes", 20);
    int total = option_find_int(options, "num", 1);
    int num = 0;
    char* a = option_find_str(options, "mask", 0);
    int* mask = parse_yolo_mask(a, &num);
    int max_boxes = option_find_int/*_quiet*/(options, "max", 200);

    layer l = make_yolo_layer(params.batch, params.w, params.h, num, total, mask, classes, max_boxes);

    char* iou_loss = option_find_str/*_quiet*/(options, "iou_loss", "mse");
    fprintf(stderr, "yolo\n");
    fprintf(stderr, "[yolo] params: iou loss: %s\n",
        iou_loss);

    char* iou_thresh_kind_str = option_find_str/*_quiet*/(options, "iou_thresh_kind", "iou");

    l.beta_nms = option_find_float/*_quiet*/(options, "beta_nms", 0.6);
    char* nms_kind = option_find_str/*_quiet*/(options, "nms_kind", "default");

    a = option_find_str(options, "anchors", 0);
    if (a) {
        int len = strlen(a);
        int n = 1;
        int i;
        for (i = 0; i < len; ++i) {
            if (a[i] == '#') break;
            if (a[i] == ',') ++n;
        }
        for (i = 0; i < n && i < total * 2; ++i) {
            float bias = atof(a);
            l.biases[i] = bias;
            a = strchr(a, ',') + 1;
        }
    }
    return l;
}