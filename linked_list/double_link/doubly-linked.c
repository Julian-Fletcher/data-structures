#include "doubly-linked.h"


Doubly_LinkedList doublyL_init(){
    Doubly_LinkedList list;
    list.head = malloc(sizeof(dlNode));
    list.head->next = list.head->prev = list.head->data = NULL;
    return list;
}

/*
 * Inserts at the head of the list
 */
int doublyL_insert(Doubly_LinkedList list, void *data){
    //First-time insert
    if(list.head->data == NULL){
        list.head->data = data;
        return SUCCESS;
    }

    dlNode *new = malloc(sizeof(dlNode));
    if(!new){
        return ERR_NOMEM;
    }
    //Insert at "head" after the user list head
    new->data = data;
    new->prev = list.head;
    new->next = list.head->next;
    new->next->prev = new;
    list.head->next = new;

    return SUCCESS;
}


int doublyL_delete(Doubly_LinkedList list, void *key, int (*comp_func)(void *a, void *b)){
    if(!list.head){
        return ERR_NOLIST;
    }
    void * usrData;
    dlNode *p = list.head;
    if((*comp_func)(list.head->data, key) == 0){
        usrData = list.head->data;
        p = list.head->next;
        list.head->data = p->data;

        list.head->next = p->next;
        p->next->prev = list.head;

        free(p);
        return SUCCESS;
    }
    p = p->next;
    dlNode *q = list.head;
    while(p != NULL){

        p = p->next;
    }
}
int doublyL_search(Doubly_LinkedList list, void *key, int (*comp_func)(void *a, void *b));
void doublyL_print(Doubly_LinkedList list, void (*print_func)(void *data));
int doublyL_free(Doubly_LinkedList list);