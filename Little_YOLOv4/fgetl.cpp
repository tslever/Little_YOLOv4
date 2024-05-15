
#include <stdio.h>
#include "xmalloc.h"
#include <stdlib.h>


char* fgetl(FILE* fp)
{
    size_t size = 512;
    char* line = (char*)xmalloc(size * sizeof(char));
    if (!fgets(line, size, fp)) {
        free(line);
        return 0;
    }
    return line;
}