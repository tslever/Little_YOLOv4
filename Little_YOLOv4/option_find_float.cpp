
#include "list.h"
#include "option_find.h"
#include <stdlib.h>


float option_find_float(list* l, char* key, float def)
{
    char* v = option_find(l, key);
    if (v) return atof(v);
    return def;
}