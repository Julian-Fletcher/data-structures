#include "single_link.h"

/*
 * Initializes an empty singly-linked list
 */
LinkedList standard_list_init(){
    LinkedList list;
    list.listHead = malloc(sizeof(slNode));
    list.listHead->next = NULL;
    list.listHead->data = NULL;
    return list;
}

/*
 * Inserts an item at the head of the list
 * Requires a list and a void pointer to data
 */
int standard_list_insert(LinkedList list, void *data){
    // First-time list
    if(list.listHead->data == NULL){
        list.listHead->data = data;
        return SUCCESS;
    }

    slNode *new = malloc(sizeof(slNode));
    if(!new){
        return ERR_NOMEM;
    }
    // Inserts at the head of the list
    // Swaps the current head with the new data to maintain the user pointer
    new->data = list.listHead->data;
    list.listHead->data = data;
    new->next = list.listHead->next;
    list.listHead->next = new;

    return SUCCESS;

}

/* Deletes an item from the list and returns the data to the calling function
 * Requires comparison function to determine if keys match
 * Comparison function should return 0 if the data matches
 * Also requires a list and a key to search for
 */
void * standard_list_delete(LinkedList list, void *key, int (*comp_func)(void *a, void *b)){
    if(!list.listHead){
        return ERR_NOLIST2;
    }

    void *usrData = NULL;                                   // If the item isn't found, NULL will be returned
    slNode *p = list.listHead;

    //Check if list head contains the item to be deleted
    if((*comp_func)(p->data, key) == 0){
        // "Swaps" the list head with the following node
        // Then deletes the following node and returns the user data
        usrData = p->data;
        p->data = p->next->data;
        p->next = p->next->next;

        free(p->next);
        return usrData;
    }
    p = p->next;
    slNode *q = list.listHead;                              // Create a second pointer to traverse the list
    while(p->next != NULL){
        if((*comp_func)(p->data, key) == 0){
            usrData = p->data;
            q->next = p->next;                              // Link the preceding node of p to p->next and delete p
            free(p);
            return usrData;
        }
        q = p;
        p = p->next;
    }
    return usrData;
}

/*
 * Searches for an item in the list
 * Returns 0 if the item exists in the list
 * Requires a comparison function
 */
int standard_list_search(LinkedList list, void *key, int (*comp_func)(void *a, void *b)){
    slNode *p = list.listHead;
    //Searches the list in O(n)
    while(p->next !=NULL){
        if((*comp_func)(key, p->data)){
            return SUCCESS;
        }
        p = p->next;
    }
    return ERR_NOTINLIST;
}

/*
 * Lists all items present within the linked list
 * Requires a function handle printing the data
 */
void standard_list_print(LinkedList list, void (*print_func)(void *data)){
    slNode *p = list.listHead;
    while(p != NULL){
        (*print_func)(p->data);
        p = p->next;
    }
}

/*
 * Frees all nodes in the list
 */
int standard_list_free(LinkedList list){
    //Checks if the list is empty or is only one item
    if(!list.listHead){
        return ERR_NOLIST;
    }
    if(list.listHead->next == NULL){
        free(list.listHead);
        return SUCCESS;
    }

    slNode *p = list.listHead->next;
    slNode *q;

    //Traverses the list and frees it
    while(p->next != NULL){
        q = p;
        p = p->next;
        free(q);
    }

    free(p);
    free(list.listHead);
    return SUCCESS;
}