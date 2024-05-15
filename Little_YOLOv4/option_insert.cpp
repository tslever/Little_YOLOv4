
#include "list.h"
#include "kvp.h"
#include "xmalloc.h"
#include "list_insert.h"


void option_insert(list* l, char* key, char* val)
{
    kvp* p = (kvp*)xmalloc(sizeof(kvp));
    p->key = key;
    p->val = val;
    list_insert(l, p);
}