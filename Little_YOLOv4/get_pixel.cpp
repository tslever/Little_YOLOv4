
#include "image.h"


float get_pixel(image m, int x, int y, int c)
{
    return m.data[c * m.h * m.w + y * m.w + x];
}