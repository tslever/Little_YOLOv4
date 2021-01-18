
#include <string.h>
#include "xcalloc.h"
#include <stdlib.h>


int* parse_yolo_mask(char* a, int* num)
{
    int* mask = 0;
    if (a) {
        int len = strlen(a);
        int n = 1;
        int i;
        for (i = 0; i < len; ++i) {
            if (a[i] == '#') break;
            if (a[i] == ',') ++n;
        }
        mask = (int*)xcalloc(n, sizeof(int));
        for (i = 0; i < n; ++i) {
            int val = atoi(a);
            mask[i] = val;
            a = strchr(a, ',') + 1;
        }
        *num = n;
    }
    return mask;
}