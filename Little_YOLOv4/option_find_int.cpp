
#include "list.h"
#include "option_find.h"
#include <stdlib.h>


int option_find_int(list* l, char* key, int def)
{
    char* v = option_find(l, key);
    if (v) return atoi(v);
    return def;
}