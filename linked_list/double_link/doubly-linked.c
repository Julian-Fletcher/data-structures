#include "doubly-linked.h"


Doubly_LinkedList standard_list_init(){
    Doubly_LinkedList list;
    list.head = malloc(sizeof(dlNode));
    list.head->next = list.head->prev = list.head->data = NULL;
    return list;
}

int doublyL_insert(Doubly_LinkedList list, void *data){

}
void * doublyL_delete(Doubly_LinkedList list, void *key, int (*comp_func)(void *a, void *b));
int doublyL_search(Doubly_LinkedList list, void *key, int (*comp_func)(void *a, void *b));
void doublyL_print(Doubly_LinkedList list, void (*print_func)(void *data));
int doublyL_free(Doubly_LinkedList list);