
#include <stdio.h>
#include <stdlib.h>


void file_error(char* s)
{
    fprintf(stderr, "Couldn't open file: %s\n", s);
    exit(EXIT_FAILURE);
}