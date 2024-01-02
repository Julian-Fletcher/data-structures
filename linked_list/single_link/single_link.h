#ifndef LINKED_LIST_SINGLE_LINK_H
#define LINKED_LIST_SINGLE_LINK_H

#endif //LINKED_LIST_SINGLE_LINK_H

#include "../ll.h"

//Singly-linked
typedef struct _slNode{
    void * data;
    struct _slNode *next;
}slNode;

//Standard List wrapper
typedef struct _sdList {
    slNode *listHead;
}LinkedList;

LinkedList standard_list_init();
int standard_list_insert(LinkedList list, void *data);
void * standard_list_delete(LinkedList list, void *key, int (*comp_func)(void *a, void *b));
int standard_list_search(LinkedList list, void *key, int (*comp_func)(void *a, void *b));
void standard_list_print(LinkedList list, void (*print_func)(void *data));
int standard_list_free(LinkedList list);