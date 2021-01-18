
#include <malloc.h>
#include "malloc_error.h"


void* xmalloc(size_t size) {
    void* ptr = malloc(size);
    if (!ptr) {
        malloc_error();
    }
    return ptr;
}