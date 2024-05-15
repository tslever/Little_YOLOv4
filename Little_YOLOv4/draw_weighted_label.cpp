
#include "image.h"
#include "get_pixel.h"
#include "set_pixel.h"


void draw_weighted_label(
    image a, int r, int c, image label, const float* rgb, const float alpha)
{
    int w = label.w;
    int h = label.h;
    if (r - h >= 0) r = r - h;

    int i, j, k;
    for (j = 0; j < h && j + r < a.h; ++j) {
        for (i = 0; i < w && i + c < a.w; ++i) {
            for (k = 0; k < label.c; ++k) {
                float val1 = get_pixel(label, i, j, k);
                float val2 = get_pixel(a, i + c, j + r, k);
                float val_dst = val1 * rgb[k] * alpha + val2 * (1 - alpha);
                set_pixel(a, i + c, j + r, k, val_dst);
            }
        }
    }
}