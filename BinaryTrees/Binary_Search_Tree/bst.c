#include "bst.h"

// Initialize an empty Binary Search Tree and return it to the user
BST bstInit(){
    BST tree;
    tree.root = malloc(sizeof(Node));
    if(!tree.root){
        //Error handling
    }
    tree.root->left = NULL;
    tree.root->right = NULL;
    tree.root->size = 0;
    return tree;
}

// Insert
int insertItem(BST tree,void *data, void(*comp_func)(void *data)){
    // Error - No tree
    if(!tree.root){
        return ERR_NOTREE;
    }

    // Empty tree
    if(!tree.root->data){
        Node *new = malloc(sizeof(Node));
        if(!new){
            return ERR_NOMEM;
        }
        new->data = data;
        // Traverse and insert here
    }
}

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