
#include "list.h"
#include "xcalloc.h"


void** list_to_array(list* l)
{
    void** a = (void**)xcalloc(l->size, sizeof(void*));
    int count = 0;
    node* n = l->front;
    while (n) {
        a[count++] = n->val;
        n = n->next;
    }
    return a;
}