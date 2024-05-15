
#include "layer.h"
#include "list.h"
#include "size_params.h"
#include "option_find_str.h"
#include "get_activation.h"
#include "option_find.h"
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include "make_shortcut_layer.h"
#include <stdio.h>


layer parse_shortcut(list* options, size_params params, network net)
{
    char* activation_s = option_find_str(options, "activation", "linear");
    ACTIVATION activation = get_activation(activation_s);

    WEIGHTS_NORMALIZATION weights_normalization = NO_NORMALIZATION;

    char* l = option_find(options, "from");
    int len = strlen(l);
    int n = 1;
    int i;
    for (i = 0; i < len; ++i) {
        if (l[i] == ',') ++n;
    }

    int* layers = (int*)calloc(n, sizeof(int));
    int* sizes = (int*)calloc(n, sizeof(int));
    float** layers_output = (float**)calloc(n, sizeof(float*));
    float** layers_delta = (float**)calloc(n, sizeof(float*));
    float** layers_output_gpu = (float**)calloc(n, sizeof(float*));
    float** layers_delta_gpu = (float**)calloc(n, sizeof(float*));

    for (i = 0; i < n; ++i) {
        int index = atoi(l);
        l = strchr(l, ',') + 1;
        if (index < 0) index = params.index + index;
        layers[i] = index;
        sizes[i] = params.net.layers[index].outputs;
        layers_output[i] = params.net.layers[index].output;
        layers_output_gpu[i] = params.net.layers[layers[i]].output_gpu;
    }

    layer s = make_shortcut_layer(
        params.batch,
        n,
        layers,
        sizes,
        params.w,
        params.h,
        params.c,
        layers_output,
        layers_delta,
        layers_output_gpu,
        layers_delta_gpu,
        weights_normalization,
        activation,
        params.train);

    free(layers_output_gpu);
    free(layers_delta_gpu);

    fprintf(stderr, "Shortcut Layer: ");
    s.bflops = s.out_w * s.out_h * s.out_c * s.n / 1000000000.;
    for (i = 0; i < n; ++i) {
        int index = layers[i];
        fprintf(stderr, "%d, ", layers[i]);
    }
    fprintf(stderr, " wn = %d, outputs:%4d x%4d x%4d %5.3f BF\n",
        weights_normalization, s.out_w, s.out_h, s.out_c, s.bflops);
    for (i = 0; i < n; ++i) {
        int index = layers[i];
        fprintf(stderr, " (%4d x%4d x%4d) + (%4d x%4d x%4d) \n",
            params.w, params.h, params.c, net.layers[index].out_w, net.layers[index].out_h, params.net.layers[index].out_c);
    }

    return s;
}