
#include "node.h"
#include <stdlib.h>


void free_node(node* n)
{
    node* next;
    while (n) {
        next = n->next;
        free(n);
        n = next;
    }
}