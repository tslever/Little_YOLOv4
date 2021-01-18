
#include "image.h"
#include <opencv2\opencv.hpp>
#include "create_image.h"


image imread_resize_cvtColor_and_create_image(char* filename, int w, int h)
{
	// --------------------------------------------------------------
	// Load image as an OpenCV mat object called mat. Format is NHWC.
	// --------------------------------------------------------------
	cv::Mat mat = cv::imread(filename, cv::IMREAD_COLOR);

	// ------------------------
	// Resize mat to w x h x 3.
	// ------------------------
	cv::resize(mat, mat, cv::Size(w, h), 0, 0, cv::INTER_LINEAR);

	// -----------------------------------------------------------------------------
	// Convert mat from RGB to BGR. This might could be eliminated after retraining.
	// -----------------------------------------------------------------------------
	cv::cvtColor(mat, mat, cv::COLOR_RGB2BGR);

	// --------------------------
	// Create image based on mat.
	// --------------------------
	image im;
	create_image(&im, &mat);

	// ----------
	// Return im.
	// ----------
	return im;
}