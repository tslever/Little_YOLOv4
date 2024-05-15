
#include <stdlib.h>


void free_ptrs(void** ptrs, int n)
{
    int i;
    for (i = 0; i < n; ++i) free(ptrs[i]);
    free(ptrs);
}