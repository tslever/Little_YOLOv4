
#include "image.h"
#include "copy_image.h"
#include <opencv2\opencv.hpp>
#include "image_to_mat.h"
#include "free_image.h"


void show_image_cv(image p, const char* name)
{
    image copy = copy_image(p);
    cv::Mat mat = image_to_mat(copy);
    if (mat.channels() == 3) cv::cvtColor(mat, mat, cv::COLOR_RGB2BGR);
    else if (mat.channels() == 4) cv::cvtColor(mat, mat, cv::COLOR_RGBA2BGR);
    cv::namedWindow(name, cv::WINDOW_NORMAL);
    cv::imshow(name, mat);
    free_image(copy);
}