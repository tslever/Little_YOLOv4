
#include "layer.h"
#include "list.h"
#include "size_params.h"
#include "option_find_int.h"
#include "make_upsample_layer.h"
#include "option_find_float.h"


layer parse_upsample(list* options, size_params params, network net)
{

    int stride = option_find_int(options, "stride", 2);
    layer l = make_upsample_layer(params.batch, params.w, params.h, params.c, stride);
    l.scale = option_find_float/*_quiet*/(options, "scale", 1);
    return l;
}