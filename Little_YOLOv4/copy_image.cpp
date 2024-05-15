
#include "image.h"
#include "xcalloc.h"
#include <string.h>


image copy_image(image p)
{
    image copy = p;
    copy.data = (float*)xcalloc(p.h * p.w * p.c, sizeof(float));
    memcpy(copy.data, p.data, p.h * p.w * p.c * sizeof(float));
    return copy;
}