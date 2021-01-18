
#include "layer.h"
#include "list.h"
#include "size_params.h"
#include "option_find_int.h"
#include "make_maxpool_layer.h"


layer parse_maxpool(list* options, size_params params)
{
    int stride = option_find_int(options, "stride", 1);
    int stride_x = option_find_int/*_quiet*/(options, "stride_x", stride);
    int stride_y = option_find_int/*_quiet*/(options, "stride_y", stride);
    int size = option_find_int(options, "size", stride);
    int padding = option_find_int/*_quiet*/(options, "padding", size - 1); // set equal to size - 1.
    int maxpool_depth = option_find_int/*_quiet*/(options, "maxpool_depth", 0); // set equal to 0.
    int out_channels = option_find_int/*_quiet*/(options, "out_channels", 1); // set equal to 1.
    int antialiasing = option_find_int/*_quiet*/(options, "antialiasing", 0); // set equal to 0.
    const int avgpool = 0;

    int batch, h, w, c;
    h = params.h;
    w = params.w;
    c = params.c;
    batch = params.batch;

    layer layer = make_maxpool_layer(batch, h, w, c, size, stride_x, stride_y, padding, maxpool_depth, out_channels, antialiasing, avgpool, params.train);
    return layer;
}