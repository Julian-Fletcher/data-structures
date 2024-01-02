#ifndef LINKED_LIST_DOUBLY_LINKED_H
#define LINKED_LIST_DOUBLY_LINKED_H

#endif //LINKED_LIST_DOUBLY_LINKED_H

#include "../ll.h"

//Doubly-linked
typedef struct _dlNode{
    void *data;
    struct _dlNode *prev;
    struct _dlNode *next;
}dlNode;

typedef struct {
    dlNode *head;
}Doubly_LinkedList;

Doubly_LinkedList standard_list_init();
int doublyL_insert(Doubly_LinkedList list, void *data);
void * doublyL_delete(Doubly_LinkedList list, void *key, int (*comp_func)(void *a, void *b));
int doublyL_search(Doubly_LinkedList list, void *key, int (*comp_func)(void *a, void *b));
void doublyL_print(Doubly_LinkedList list, void (*print_func)(void *data));
int doublyL_free(Doubly_LinkedList list);