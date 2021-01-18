
#include <opencv2\opencv.hpp>
#include "image.h"


cv::Mat image_to_mat(image img)
{
    int c = img.c;
    int w = img.w;
    int h = img.h;

    cv::Mat mat = cv::Mat(h, w, CV_8UC(c));

    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            for (int k = 0; k < c; ++k) {

                mat.data[y * w * c + x * c + k] =
                    (unsigned char)(img.data[k * h * w + y * w + x] * 255.0);

            }
        }
    }

    return mat;
}