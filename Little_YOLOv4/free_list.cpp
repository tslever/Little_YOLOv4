
#include "list.h"
#include "free_node.h"
#include <stdlib.h>


void free_list(list* l)
{
    free_node(l->front);
    free(l);
}