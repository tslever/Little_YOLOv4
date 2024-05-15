
#include "network.h"
#include "math.h"
#include "free_convolutional_batchnorm.h"
#include "push_convolutional_layer.h"


void fuse_conv_batchnorm(network net)
{
    int j;
    for (j = 0; j < net.n; ++j) {
        layer* l = &net.layers[j];

        if (l->type == CONVOLUTIONAL) {
            if (l->batch_normalize) {

                int f;
                for (f = 0; f < l->n; ++f)
                {
                    l->biases[f] = l->biases[f] - /*(double)*/l->scales[f] * l->rolling_mean[f] / (sqrt(/*(double)*/l->rolling_variance[f] + .00001));

                    const size_t filter_size = l->size * l->size * l->c / l->groups;
                    int i;
                    for (i = 0; i < filter_size; ++i) {
                        int w_index = f * filter_size + i;

                        l->weights[w_index] = /*(double)*/l->weights[w_index] * l->scales[f] / (sqrt(/*(double)*/l->rolling_variance[f] + .00001));
                    }
                }

                free_convolutional_batchnorm(l);
                l->batch_normalize = 0;
                push_convolutional_layer(*l);
            }
        }
    }
}