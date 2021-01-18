
#include "image.h"
#include <opencv2\opencv.hpp>
#include "create_image.h"


image imread_cvtColor_and_create_image(char* filename)
{
	// --------------------------------------------------------------
	// Load image as an OpenCV mat object called mat. Format is NHWC.
	// --------------------------------------------------------------
	cv::Mat mat = cv::imread(filename, cv::IMREAD_COLOR);

	// -----------------------------------------------------------------------------
	// Convert mat from RGB to BGR. This might could be eliminated after retraining.
	// -----------------------------------------------------------------------------
	cv::cvtColor(mat, mat, cv::COLOR_RGB2BGR);

	// ------------------------------------------
	// Create image based on mat. Format is NCHW.
	// ------------------------------------------
	image im;
	create_image(&im, &mat);

	// ----------
	// Return im.
	// ----------
	return im;
}