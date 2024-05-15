
#include "list.h"
#include "xmalloc.h"


void list_insert(list* l, void* val)
{
    node* newnode = (node*)xmalloc(sizeof(node));
    newnode->val = val;
    newnode->next = 0;

    if (!l->back) {
        l->front = newnode;
        newnode->prev = 0;
    }
    else {
        l->back->next = newnode;
        newnode->prev = l->back;
    }
    l->back = newnode;
    ++l->size;
}