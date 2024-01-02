#include "single_link.h"

LinkedList standard_list_init(){
    LinkedList list;
    list.listHead = malloc(sizeof(slNode));
    list.listHead->next = NULL;
    list.listHead->data = NULL;
    return list;
}

//Insert at head
int standard_list_insert(LinkedList list, void *data){
    //First-time list
    if(list.listHead->data == NULL){
        list.listHead->data = data;
        return SUCCESS;
    }

    slNode *new = malloc(sizeof(slNode));
    if(!new){
        return ERR_NOMEM;
    }
    new->data = list.listHead->data;
    list.listHead->data = data;
    new->next = list.listHead->next;
    list.listHead->next = new;

    return SUCCESS;

}

//Requires comparison function
//The comparison function should return 0 if the items are equal
//And return 1 if they are different
void * standard_list_delete(LinkedList list, void *key, int (*comp_func)(void *a, void *b)){
    if(!list.listHead){
        return ERR_NOLIST2;
    }

    void *usrData = NULL;
    slNode *p = list.listHead;

    if((*comp_func)(p->data, key) == 0){
        usrData = p->data;
        p->data = p->next->data;
        p->next = p->next->next;

        free(p->next);
        return usrData;
    }
    p = p->next;
    slNode *q = list.listHead;
    while(p->next != NULL){
        if((*comp_func)(p->data, key) == 0){
            usrData = p->data;
            q->next = p->next;
            free(p);
            return usrData;
        }
        q = p;
        p = p->next;
    }
    return usrData;
}

int standard_list_search(LinkedList list, void *key, int (*comp_func)(void *a, void *b)){
    slNode *p = list.listHead;
    while(p->next !=NULL){
        if((*comp_func)(key, p->data)){
            return SUCCESS;
        }
        p = p->next;
    }
    return ERR_NOTINLIST;
}

void standard_list_print(LinkedList list, void (*print_func)(void *data)){
    slNode *p = list.listHead;
    while(p != NULL){
        (*print_func)(p->data);
        p = p->next;
    }
}

int standard_list_free(LinkedList list){
    if(!list.listHead){
        return ERR_NOLIST;
    }
    if(list.listHead->next == NULL){
        free(list.listHead);
        return SUCCESS;
    }

    slNode *p = list.listHead->next;
    slNode *q;

    while(p->next != NULL){
        q = p;
        p = p->next;
        free(q);
    }

    free(p);
    free(list.listHead);
    return SUCCESS;
}