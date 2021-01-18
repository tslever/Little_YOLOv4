
#include "image.h"
#include "get_pixel.h"


float get_pixel_extend(image m, int x, int y, int c)
{
    if (x < 0 || x >= m.w || y < 0 || y >= m.h) return 0;
    if (c < 0 || c >= m.c) return 0;
    return get_pixel(m, x, y, c);
}