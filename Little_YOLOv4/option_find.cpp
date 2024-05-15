
#include "list.h"
#include "kvp.h"
#include <string.h>


char* option_find(list* l, char* key)
{
    node* n = l->front;
    while (n) {
        kvp* p = (kvp*)n->val;
        if (strcmp(p->key, key) == 0) {
            return p->val;
        }
        n = n->next;
    }
    return 0;
}