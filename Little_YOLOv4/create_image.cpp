
#include "image.h"
#include <opencv2\opencv.hpp>
#include "xmalloc.h"


void create_image(image* im, cv::Mat* mat)
{
    // Define integers w, h, c as the width, height, and "number of channels"
    // in the cv::Mat object pointed to by mat.
    int w = mat->cols;
    int h = mat->rows;
    int c = mat->channels();

    // Define pointer data as the pointer to the pixel data in the matrix object
    // pointed to by mat.
    unsigned char* data = (unsigned char*)mat->data;

    // Define the width, height, "number of channels", and data properties of im.
    im->w = w;
    im->h = h;
    im->c = c;
    im->data = (float*)xmalloc(w * h * c * sizeof(float));

    // For each channel in im...
    // For each row in im...
    // For each column in im...
    // Define the present pixel in the memory buffer pointed to by im's data pointer as
    // the corresponding pixel in the memory buffer pointed to by mat's data pointer,
    // scaled to between 0 and 1 and
    // converted from an unsigned byte to a 32-bit floating-point number.
    for (int k = 0; k < c; ++k) {
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                im->data[k * w * h + y * w + x] = data[y * w * c + x * c + k] / 255.0;
            }
        }
    }
}