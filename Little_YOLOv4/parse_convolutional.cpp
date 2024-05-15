
#include "layer.h"
#include "list.h"
#include "size_params.h"
#include "option_find_int.h"
#include "option_find_str.h"
#include "get_activation.h"
#include "option_find_float.h"
#include "make_convolutional_layer.h"


layer parse_convolutional(list* options, size_params params)
{
    int n = option_find_int(options, "filters", 1); // must be specified value in yolov4.cfg.
    int groups = option_find_int/*_quiet*/(options, "groups", 1); // must be default value of 1.
    int size = option_find_int(options, "size", 1); // must be specified value in yolov4.cfg.

    // stride must be specified value in yolov4.cfg.
    int stride = option_find_int/*_quiet*/(options, "stride", 1);
    int stride_x = option_find_int/*_quiet*/(options, "stride_x", -1);
    int stride_y = option_find_int/*_quiet*/(options, "stride_y", -1);
    if (stride_x < 1) stride_x = stride;
    if (stride_y < 1) stride_y = stride;

    int dilation = option_find_int/*_quiet*/(options, "dilation", 1); // must be default value of 1.
    int antialiasing = option_find_int/*_quiet*/(options, "antialiasing", 0); // must be default value of 0.
    int pad = option_find_int/*_quiet*/(options, "pad", 0); // must be specified value in yolov4.cfg of 1.
    int padding = size / 2;

    char* activation_s = option_find_str(options, "activation", "logistic"); // must be specified value in yolov4.cfg of MISH.
    ACTIVATION activation = get_activation(activation_s);

    int assisted_excitation = option_find_float/*_quiet*/(options, "assisted_excitation", 0); // must be default value of 0.

    int share_index = option_find_int/*_quiet*/(options, "share_index", -1000000000); // must be default value of -1000000000.
    layer* share_layer = NULL;

    int h = params.h;
    int w = params.w;
    int c = params.c;
    int batch = params.batch;
    int batch_normalize = option_find_int/*_quiet*/(options, "batch_normalize", 0); // must be specified value in yolov4.cfg of 1.
    int cbn = option_find_int/*_quiet*/(options, "cbn", 0); // must be default value of 0.
    int binary = option_find_int/*_quiet*/(options, "binary", 0); // must be default value of 0.
    int xnor = option_find_int/*_quiet*/(options, "xnor", 0); // must be default value of 0.
    int use_bin_output = option_find_int/*_quiet*/(options, "bin_output", 0); // may be either 0 or 1.
    int sway = option_find_int/*_quiet*/(options, "sway", 0); // must be default value of 0.
    int rotate = option_find_int/*_quiet*/(options, "rotate", 0); // must be default value of 0.
    int stretch = option_find_int/*_quiet*/(options, "stretch", 0); // must be default value of 0.
    int stretch_sway = option_find_int/*_quiet*/(options, "stretch_sway", 0); // must be default value of 0.
    int deform = sway || rotate || stretch || stretch_sway;

    layer l = make_convolutional_layer(batch, 1, h, w, c, n, groups, size, stride_x, stride_y, dilation, padding, activation, batch_normalize, binary, xnor, /*params.net.adam,*/ use_bin_output, params.index, antialiasing, share_layer, assisted_excitation, deform, params.train);

    return l;
}