
#include "image.h"
#include "make_empty_image.h"
#include "xcalloc.h"


image make_image(int w, int h, int c)
{
    image out = make_empty_image(w, h, c);
    out.data = (float*)xcalloc(h * w * c, sizeof(float));
    return out;
}