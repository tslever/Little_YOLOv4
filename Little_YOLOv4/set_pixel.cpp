
#include "image.h"


void set_pixel(image m, int x, int y, int c, float val)
{
    m.data[c * m.h * m.w + y * m.w + x] = val;
}