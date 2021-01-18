
#include "list.h"
#include "option_find.h"


char* option_find_str(list* l, char* key, char* def)
{
    char* v = option_find(l, key);
    if (v) return v;
    return def;
}