
#include "network.h"
#include "cuda_set_device.h"
#include <stdio.h>
#include "file_error.h"
#include "load_convolutional_weights.h"


void load_weights_upto(network* net, char* filename, int cutoff)
{
    cuda_set_device(0);

    fprintf(stderr, "Loading weights from %s...", filename);
    fflush(stdout);
    FILE* fp = fopen(filename, "rb");
    if (!fp) file_error(filename);

    int major;
    int minor;
    int revision;
    fread(&major, sizeof(int), 1, fp);
    fread(&minor, sizeof(int), 1, fp);
    fread(&revision, sizeof(int), 1, fp);

    printf("\n seen 64");
    uint64_t iseen = 0;
    fread(&iseen, sizeof(uint64_t), 1, fp);

    int transpose = (major > 1000) || (minor > 1000);

    int i;
    for (i = 0; i < net->n && i < cutoff; ++i) {
        layer l = net->layers[i];
        if (l.type == CONVOLUTIONAL) {
            load_convolutional_weights(l, fp);
        }
    }
    fprintf(stderr, "Done! Loaded %d layers from weights-file \n", i);
    fclose(fp);
}