#ifndef BINARY_SEARCH_TREE_BST_H
#define BINARY_SEARCH_TREE_BST_H

#endif //BINARY_SEARCH_TREE_BST_H

#include <stdio.h>
#include <stdlib.h>

enum returns{
    SUCCESS = 0,
    ERR_NOTREE = -3,
    ERR_NOMEM = -1
};


typedef struct _node {
    int size;
    void *data;
    struct _node *left;
    struct _node *right;
}Node;

typedef struct {
    Node *root;
}BST;

// Init
BST bstInit();

// Insert
int insertItem(BST tree,void *data, void(*comp_func)(void *data));

// Delete
int deleteItem(BST tree, void *data, void(*comp_func)(void *data));

// Search  - Search for item in O(nLog(n)
int searchBST(BST tree, void *data, void(*comp_func)(void *data));

// Flatten - returns an array of the BST items
void * flattenBST(BST tree);

// In-order Print
int printBST(BST tree, void(*print_func)(void *data));

// Free
int freeBST(BST tree);