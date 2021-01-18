
#include "image.h"
#include "make_image.h"
#include "get_pixel_extend.h"
#include "set_pixel.h"


image border_image(image a, int border)
{
    image b = make_image(a.w + 2 * border, a.h + 2 * border, a.c);
    int x, y, k;
    for (k = 0; k < b.c; ++k) {
        for (y = 0; y < b.h; ++y) {
            for (x = 0; x < b.w; ++x) {
                float val = get_pixel_extend(a, x - border, y - border, k);
                if (x - border < 0 || x - border >= a.w || y - border < 0 || y - border >= a.h) val = 1;
                set_pixel(b, x, y, k, val);
            }
        }
    }
    return b;
}