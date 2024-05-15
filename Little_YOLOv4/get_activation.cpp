
#include "ACTIVATION.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


ACTIVATION get_activation(char* s)
{
    if (strcmp(s, "mish") == 0) return MISH;
    if (strcmp(s, "linear") == 0) return LINEAR;
    if (strcmp(s, "leaky") == 0) return LEAKY;

    fprintf(stderr, "Couldn't find activation function %s, press enter to exit\n", s);
    getchar();
    exit(EXIT_FAILURE);
}