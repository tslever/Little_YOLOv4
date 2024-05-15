
#include "find_float_arg.h"
#include "test_detector.h"

// Allow testing datacfg, cfg, weights, and filename.
//#include <stdio.h>

// Allow testing find_float_arg.
//#include <stdio.h>


void run_detector(int argc, char** argv)
{
    // Define paths to configuration and data files.
    // pathToNamesFile = "..\data\coco.names".
    // cfg = "..\cfg\yolov4.cfg".
    // weights = "..\backup\yolov4.weights".
    // filename = "..\data\Dog.jpg".
    char* pathToNamesFile = argv[3];
    char* cfg = argv[4];
    char* weights = argv[5];
    char* filename = argv[6];
    /*printf("%s\n", datacfg);
    printf("%s\n", cfg);
    printf("%s\n", weights);
    printf("%s\n", filename);*/

    // Define thresh.
    // thresh is a floating-point number used as a threshhold
    // to determine whether a prediction has a sufficiently high objectness score
    // to be counted as a detection.
    // thresh is first used in yolo_num_detections, which is employed
    // to find the number of detections associated with one of three YOLO layers.
    float thresh = find_float_arg(argc, argv, "-thresh", 0.25);
    /*printf("%f\n", thresh);*/

    test_detector(pathToNamesFile, cfg, weights, filename, thresh);
}