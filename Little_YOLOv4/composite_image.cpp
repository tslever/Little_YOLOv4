
#include "image.h"
#include "get_pixel.h"
#include "get_pixel_extend.h"
#include "set_pixel.h"


void composite_image(image source, image dest, int dx, int dy)
{
    int x, y, k;
    for (k = 0; k < source.c; ++k) {
        for (y = 0; y < source.h; ++y) {
            for (x = 0; x < source.w; ++x) {
                float val = get_pixel(source, x, y, k);
                float val2 = get_pixel_extend(dest, dx + x, dy + y, k);
                set_pixel(dest, dx + x, dy + y, k, val * val2);
            }
        }
    }
}