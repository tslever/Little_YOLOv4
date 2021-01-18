
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


void error(const char* s)
{
    perror(s);
    assert(0);
    exit(EXIT_FAILURE);
}