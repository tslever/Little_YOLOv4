
#include "list.h"
#include "get_labels_custom.h"
#include "image.h"
#include "load_alphabet.h"
#include "network.h"
#include "parse_network_cfg_custom.h"
#include "load_weights.h"
#include "fuse_conv_batchnorm.h"
#include "imread_resize_cvtColor_and_create_image.h"
#include "network_predict.h"
#include "detection.h"
#include "get_network_boxes.h"
#include "diounms_sort.h"
#include "draw_detections_v3.h"
#include "show_image.h"
#include "wait_until_press_key_cv.h"
#include "destroy_all_windows_cv.h"
#include "free_detections.h"
#include "free_image.h"
#include "free_ptrs.h"
#include <stdlib.h>
#include "free_network.h"

// For testing names.
//#include <stdio.h>

// For testing alphabet or im.
//#include <opencv2\opencv.hpp>
//#include "image_to_mat.h"


void test_detector(
    char* pathToNamesFile, char* cfgfile, char* weightfile, char* filename, float thresh)
{
    char** names = get_labels_custom(pathToNamesFile);
    /*for (int i = 0; i < names_size; ++i) {
        printf("'%s'\n", names[i]);
    }*/

    image** alphabet = load_alphabet();
    /*for (int i = 7; i >= 0; --i) {
        image* oneAlphabet = alphabet[i];
        for (int j = 32; j < 127; ++j) {
            image alphabeticCharacterAsImage = oneAlphabet[j];
            cv::Mat alphabeticCharacterAsMat = image_to_mat(alphabeticCharacterAsImage);
            cv::namedWindow("Named Window for Displaying Alphabetic Character", cv::WINDOW_NORMAL);
            cv::imshow("Named Window for Displaying Alphabetic Character", alphabeticCharacterAsMat);
            cv::waitKey(0);
        }
    }*/

    network net = parse_network_cfg_custom(cfgfile, 1, 1);

    load_weights(&net, weightfile);

    fuse_conv_batchnorm(net);

    float nms = 0.45;

    image im = imread_resize_cvtColor_and_create_image(filename, net.w, net.h);
    float* X = im.data;
    /*cv::Mat imAsMat = image_to_mat(im);
    cv::namedWindow("Named Windows for Displaying im", cv::WINDOW_NORMAL);
    cv::imshow("Named Window for Displaying im", imAsMat);
    cv::waitKey(0);*/

    network_predict(net, X);

    int nboxes = 0;
    detection* dets = get_network_boxes(&net, im.w, im.h, thresh, 0, 1, &nboxes);

    layer l = net.layers[net.n - 1];
    diounms_sort(dets, nboxes, l.classes, nms, l.nms_kind, l.beta_nms);

    draw_detections_v3(im, dets, nboxes, thresh, names, alphabet, l.classes);

    show_image(im, "predictions");
    wait_until_press_key_cv();

    destroy_all_windows_cv();
    free_detections(dets, nboxes);
    free_image(im);
    free_ptrs((void**)names, net.layers[net.n - 1].classes);
    int nsize = 8;
    int i;
    for (int j = 0; j < nsize; ++j) {
        for (i = 32; i < 127; ++i) {
            free_image(alphabet[j][i]);
        }
        free(alphabet[j]);
    }
    free(alphabet);
    free_network(net);
}