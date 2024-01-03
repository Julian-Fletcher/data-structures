#ifndef LINKED_LIST_LL_H
#define LINKED_LIST_LL_H

#endif //LINKED_LIST_LL_H

#include <stdio.h>
#include <stdlib.h>

enum returns{
    SUCCESS = 0,
    ERR_NOMEM = -1,
    ERR_INSERT_FAIL = -2,
    ERR_NOLIST = -3,
    ERR_NOTINLIST = -5

};


//Circularly-linked wrapper
typedef struct _clList{
    void *listHead;
    void *listEnd;
    int length;
}CLinkedList;
