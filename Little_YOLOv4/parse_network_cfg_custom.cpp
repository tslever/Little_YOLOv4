
#include "network.h"
#include "list.h"
#include "read_cfg.h"
#include "make_network.h"
#include "size_params.h"
#include "section.h"
#include "parse_net_options.h"
#include "free_section.h"
#include <stdio.h>
#include "string_to_layer_type.h"
#include "parse_convolutional.h"
#include "parse_yolo.h"
#include "parse_maxpool.h"
#include "parse_route.h"
#include "parse_upsample.h"
#include "parse_shortcut.h"
#include "free_list.h"
#include "get_network_input_size.h"
#include "cuda_make_array.h"

// For testing sections.
/*#include "section.h"
#include "kvp.h"
#include <stdio.h>*/


network parse_network_cfg_custom(char* filename, int batch, int time_steps)
{
    list* sections = read_cfg(filename);
    /*node* nodeForSection = sections->front;
    while (nodeForSection) {
        section* presentSection = (section*)nodeForSection->val;
        printf("%s\n", presentSection->type);
        list* options = presentSection->options;
        node* nodeForOption = options->front;
        while (nodeForOption) {
            kvp* keyValuePair = (kvp*)nodeForOption->val;
            char* key = keyValuePair->key;
            char* val = keyValuePair->val;
            printf("\t%s: %s\n", key, val);
            nodeForOption = nodeForOption->next;
        }
        nodeForSection = nodeForSection->next;
    }*/

    node* n = sections->front;
    network net = make_network(sections->size - 1);
    size_params params;
    params.train = 0;

    section* s = (section*)n->val;
    list* options = s->options;
    parse_net_options(options, &net);

    params.h = net.h;
    params.w = net.w;
    params.c = net.c;
    net.batch = batch;
    params.batch = net.batch;
    params.net = net;
    size_t workspace_size = 0;

    n = n->next;
    int count = 0;
    free_section(s);
    fprintf(stderr, "   layer   filters  size/strd(dil)      input                output\n");
    while (n) {
        params.index = count;
        fprintf(stderr, "%4d ", count);
        s = (section*)n->val;
        options = s->options;
        layer l = { (LAYER_TYPE)0 };
        LAYER_TYPE lt = string_to_layer_type(s->type);
        if (lt == CONVOLUTIONAL) {
            l = parse_convolutional(options, params);
        }
        else if (lt == YOLO) {
            l = parse_yolo(options, params);
        }
        else if (lt == MAXPOOL) {
            l = parse_maxpool(options, params);
        }
        else if (lt == ROUTE) {
            l = parse_route(options, params);
        }
        else if (lt == UPSAMPLE) {
            l = parse_upsample(options, params, net);
        }
        else if (lt == SHORTCUT) {
            l = parse_shortcut(options, params, net);
        }

        net.layers[count] = l;
        if (l.workspace_size > workspace_size) workspace_size = l.workspace_size;
        free_section(s);
        n = n->next;
        ++count;
        if (n) {

            params.h = l.out_h;
            params.w = l.out_w;
            params.c = l.out_c;
            params.inputs = l.outputs;
        }
    }
    free_list(sections);

    int size = get_network_input_size(net) * net.batch;
    net.input_state_gpu = cuda_make_array(0, size);
    cudaHostAlloc(&(net.input_pinned_cpu), size * sizeof(float), cudaHostRegisterMapped);
    net.workspace = cuda_make_array(0, workspace_size / sizeof(float) + 1);

    return net;
}