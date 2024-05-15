
#include "image.h"
#include "xcalloc.h"
#include <stdio.h>
#include "imread_cvtColor_and_create_image.h"


image** load_alphabet()
{
    int i;
    int nsize = 8;
    image** alphabets = (image**)xcalloc(nsize, sizeof(image*));
    for (int j = 0; j < nsize; ++j) {
        alphabets[j] = (image*)xcalloc(128, sizeof(image));
        for (i = 32; i < 127; ++i) {
            char buff[256];
            sprintf(buff, "../data/labels/%d_%d.png", i, j);
            alphabets[j][i] = imread_cvtColor_and_create_image(buff);
        }
    }
    return alphabets;
}