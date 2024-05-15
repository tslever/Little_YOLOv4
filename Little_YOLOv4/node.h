
#ifndef NODE
#define NODE


typedef struct node {
    void* val;
    node* next;
    node* prev;
} node;


#endif