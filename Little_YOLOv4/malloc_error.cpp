
#include <stdio.h>
#include <stdlib.h>


void malloc_error()
{
    fprintf(stderr, "xMalloc error - possibly out of CPU RAM \n");
    exit(EXIT_FAILURE);
}