
#include "layer.h"
#include <stdio.h>
#include "push_convolutional_layer.h"


void load_convolutional_weights(layer l, FILE* fp)
{
    int num = l.nweights;
    int read_bytes;
    read_bytes = fread(l.biases, sizeof(float), l.n, fp);
    if (l.batch_normalize) {
        read_bytes = fread(l.scales, sizeof(float), l.n, fp);
        read_bytes = fread(l.rolling_mean, sizeof(float), l.n, fp);
        read_bytes = fread(l.rolling_variance, sizeof(float), l.n, fp);
    }
    read_bytes = fread(l.weights, sizeof(float), num, fp);

    push_convolutional_layer(l);
}