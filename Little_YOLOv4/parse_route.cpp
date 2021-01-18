
#include "layer.h"
#include "list.h"
#include "size_params.h"
#include "option_find.h"
#include <string.h>
#include "xcalloc.h"
#include <stdlib.h>
#include "option_find_int.h"
#include "make_route_layer.h"
#include <stdio.h>


layer parse_route(list* options, size_params params)
{
    char* l = option_find(options, "layers");
    int len = strlen(l);
    int n = 1;
    int i;
    for (i = 0; i < len; ++i) {
        if (l[i] == ',') ++n;
    }

    int* layers = (int*)xcalloc(n, sizeof(int));
    int* sizes = (int*)xcalloc(n, sizeof(int));
    for (i = 0; i < n; ++i) {
        int index = atoi(l);
        l = strchr(l, ',') + 1;
        if (index < 0) index = params.index + index;
        layers[i] = index;
        sizes[i] = params.net.layers[index].outputs;
    }
    int batch = params.batch;

    int groups = option_find_int/*_quiet*/(options, "groups", 1);
    int group_id = option_find_int/*_quiet*/(options, "group_id", 0);

    layer route_layer = make_route_layer(batch, n, layers, sizes, groups, group_id);

    layer first = params.net.layers[layers[0]];
    route_layer.out_w = first.out_w;
    route_layer.out_h = first.out_h;
    route_layer.out_c = first.out_c;
    layer next;
    for (i = 1; i < n; ++i) {
        int index = layers[i];
        next = params.net.layers[index];
        route_layer.out_c += next.out_c;
    }

    fprintf(stderr, "route ");
    for (i = 0; i < n; ++i) {
        fprintf(stderr, " %d", layers[i]);
    }
    if (n > 3) fprintf(stderr, " \t    ");
    else if (n > 1) fprintf(stderr, " \t            ");
    else fprintf(stderr, " \t\t            ");
    fprintf(stderr, "           ");
    fprintf(stderr, "   ");
    fprintf(stderr, " -> %4d x%4d x%4d \n", route_layer.out_w, route_layer.out_h, route_layer.out_c);

    return route_layer;
}