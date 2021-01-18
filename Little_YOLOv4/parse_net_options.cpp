
#include "list.h"
#include "network.h"
#include "option_find_int.h"


void parse_net_options(list* options, network* net)
{
    net->batch = option_find_int(options, "batch", 1);
    int subdivs = option_find_int(options, "subdivisions", 1);
    net->batch /= subdivs;
    net->h = option_find_int/*_quiet*/(options, "height", 0);
    net->w = option_find_int/*_quiet*/(options, "width", 0);
    net->c = option_find_int/*_quiet*/(options, "channels", 0);
}