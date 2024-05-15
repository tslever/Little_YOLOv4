
#include <malloc.h>
#include "calloc_error.h"
#include <string.h>


void* xcalloc(size_t nmemb, size_t size)
{
    void* ptr = calloc(nmemb, size);
    if (!ptr) {
        calloc_error();
    }
    memset(ptr, 0, nmemb * size);
    return ptr;
}