
#include "image.h"
#include "make_empty_image.h"
#include "tile_images.h"
#include "free_image.h"
#include "border_image.h"


image get_label_v3(image** characters, char* string, int size)
{
    size = size / 10;
    if (size > 7) size = 7;
    image label = make_empty_image(0, 0, 0);
    while (*string) {
        image l = characters[size][(int)*string];
        image n = tile_images(label, l, -size - 1 + (size + 1) / 2);
        free_image(label);
        label = n;
        ++string;
    }
    image b = border_image(label, label.h * .05);
    free_image(label);
    return b;
}