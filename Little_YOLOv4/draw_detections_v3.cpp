
#include "image.h"
#include "detection.h"
#include "detection_with_class.h"
#include "get_actual_detections.h"
#include <stdio.h>
#include "math.h"
#include "get_color.h"
#include "draw_box_width.h"
#include <string.h>
#include "get_label_v3.h"
#include "draw_weighted_label.h"
#include "free_image.h"
#include "resize_image.h"
#include "embed_image.h"
#include <stdlib.h>


void draw_detections_v3(
    image im,
    detection* dets,
    int num,
    float thresh,
    char** names,
    image** alphabet,
    int classes)
{
    static int frame_id = 0;
    frame_id++;

    int selected_detections_num;
    detection_with_class* selected_detections = get_actual_detections(dets, num, thresh, &selected_detections_num, names);

    int i;
    for (i = 0; i < selected_detections_num; ++i) {
        const int best_class = selected_detections[i].best_class;
        printf("%s: %.0f%%", names[best_class], selected_detections[i].det.prob[best_class] * 100);
        //if (ext_output)
            printf("\t(left_x: %4.0f   top_y: %4.0f   width: %4.0f   height: %4.0f)\n",
                round((selected_detections[i].det.bbox.x - selected_detections[i].det.bbox.w / 2) * im.w),
                round((selected_detections[i].det.bbox.y - selected_detections[i].det.bbox.h / 2) * im.h),
                round(selected_detections[i].det.bbox.w * im.w), round(selected_detections[i].det.bbox.h * im.h));
        //else
        //    printf("\n");
        int j;
        for (j = 0; j < classes; ++j) {
            if (selected_detections[i].det.prob[j] > thresh && j != best_class) {
                printf("%s: %.0f%%", names[j], selected_detections[i].det.prob[j] * 100);

                //if (ext_output)
                    printf("\t(left_x: %4.0f   top_y: %4.0f   width: %4.0f   height: %4.0f)\n",
                        round((selected_detections[i].det.bbox.x - selected_detections[i].det.bbox.w / 2) * im.w),
                        round((selected_detections[i].det.bbox.y - selected_detections[i].det.bbox.h / 2) * im.h),
                        round(selected_detections[i].det.bbox.w * im.w), round(selected_detections[i].det.bbox.h * im.h));
                //else
                //    printf("\n");
            }
        }
    }

    for (i = 0; i < selected_detections_num; ++i) {
        int width = im.h * .002;
        if (width < 1)
            width = 1;

        int offset = selected_detections[i].best_class * 123457 % classes;
        float red = get_color(2, offset, classes);
        float green = get_color(1, offset, classes);
        float blue = get_color(0, offset, classes);
        float rgb[3];

        rgb[0] = red;
        rgb[1] = green;
        rgb[2] = blue;
        box b = selected_detections[i].det.bbox;

        int left = (b.x - b.w / 2.) * im.w;
        int right = (b.x + b.w / 2.) * im.w;
        int top = (b.y - b.h / 2.) * im.h;
        int bot = (b.y + b.h / 2.) * im.h;

        if (left < 0) left = 0;
        if (right > im.w - 1) right = im.w - 1;
        if (top < 0) top = 0;
        if (bot > im.h - 1) bot = im.h - 1;

        draw_box_width(im, left, top, right, bot, width, red, green, blue);
        if (alphabet) {
            char labelstr[4096] = { 0 };
            strcat(labelstr, names[selected_detections[i].best_class]);
            int j;
            for (j = 0; j < classes; ++j) {
                if (selected_detections[i].det.prob[j] > thresh && j != selected_detections[i].best_class) {
                    strcat(labelstr, ", ");
                    strcat(labelstr, names[j]);
                }
            }
            image label = get_label_v3(alphabet, labelstr, (im.h * .02));
            //draw_label(im, top + width, left, label, rgb);
            draw_weighted_label(im, top + width, left, label, rgb, 0.7);
            free_image(label);
        }
        if (selected_detections[i].det.mask) {
            image mask = { 0 };// float_to_image(14, 14, 1, selected_detections[i].det.mask);
            image resized_mask = resize_image(mask, b.w * im.w, b.h * im.h);
            image tmask = { 0 };// threshold_image(resized_mask, .5);
            embed_image(tmask, im, left, top);
            free_image(mask);
            free_image(resized_mask);
            free_image(tmask);
        }
    }
    free(selected_detections);
}