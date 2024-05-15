
#include "image.h"
#include <stdlib.h>


void free_image(image m)
{
    if (m.data) {
        free(m.data);
    }
}