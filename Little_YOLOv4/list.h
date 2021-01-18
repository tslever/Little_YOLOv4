
#ifndef LIST
#define LIST


#include "node.h"


typedef struct list {
    int size;
    node* front;
    node* back;
} list;


#endif