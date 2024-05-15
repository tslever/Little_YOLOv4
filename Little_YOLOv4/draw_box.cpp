
#include "image.h"


void draw_box(image a, int x1, int y1, int x2, int y2, float r, float g, float b)
{
    int i;
    if (x1 < 0) x1 = 0;
    if (x1 >= a.w) x1 = a.w - 1;
    if (x2 < 0) x2 = 0;
    if (x2 >= a.w) x2 = a.w - 1;

    if (y1 < 0) y1 = 0;
    if (y1 >= a.h) y1 = a.h - 1;
    if (y2 < 0) y2 = 0;
    if (y2 >= a.h) y2 = a.h - 1;

    for (i = x1; i <= x2; ++i) {
        a.data[i + y1 * a.w + 0 * a.w * a.h] = r;
        a.data[i + y2 * a.w + 0 * a.w * a.h] = r;

        a.data[i + y1 * a.w + 1 * a.w * a.h] = g;
        a.data[i + y2 * a.w + 1 * a.w * a.h] = g;

        a.data[i + y1 * a.w + 2 * a.w * a.h] = b;
        a.data[i + y2 * a.w + 2 * a.w * a.h] = b;
    }
    for (i = y1; i <= y2; ++i) {
        a.data[x1 + i * a.w + 0 * a.w * a.h] = r;
        a.data[x2 + i * a.w + 0 * a.w * a.h] = r;

        a.data[x1 + i * a.w + 1 * a.w * a.h] = g;
        a.data[x2 + i * a.w + 1 * a.w * a.h] = g;

        a.data[x1 + i * a.w + 2 * a.w * a.h] = b;
        a.data[x2 + i * a.w + 2 * a.w * a.h] = b;
    }
}