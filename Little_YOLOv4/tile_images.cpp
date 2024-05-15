
#include "image.h"
#include "copy_image.h"
#include "make_image.h"
#include "fill_cpu.h"
#include "embed_image.h"
#include "composite_image.h"


image tile_images(image a, image b, int dx)
{
    if (a.w == 0) return copy_image(b);
    image c = make_image(a.w + b.w + dx, (a.h > b.h) ? a.h : b.h, (a.c > b.c) ? a.c : b.c);
    fill_cpu(c.w * c.h * c.c, 1, c.data, 1);
    embed_image(a, c, 0, 0);
    composite_image(b, c, a.w + dx, 0);
    return c;
}