#include "single_link.h"

void printFunc(void *data){
    printf("Node Data: %d\n", *((int *)data));
}

int comp(void *a, void *b){
    int A = *(int *)a;
    int B = *(int *)b;
    //
    //
    // printf("Comparing %d to %d\n", A, B);
    if(A == B){
        return 0;
    }
    return 1;
}

int main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    LinkedList list;

    /*printf("=========================================\n");
    printf("TESTING WITH UNINITIALIZED LIST \n");
    if (standard_list_insert(list, (void *) &data[2]) != -3) {
        puts("Empty insert does not report error");
    } else puts("Empty insert reported error");

    if (standard_list_delete(list, (void *) &data[2], comp) != -3) {
        puts("Empty delete does not report error");
    } else puts("Empty delete reported error");

    if (standard_list_search(list, (void *) &data[2], comp) != -3) {
        puts("Empty search does not report error");
    } else puts("Empty search reported error");

    if (standard_list_print(list, printFunc) != -3) {
        puts("Empty print does not report error");
    } else puts("Empty print reported error");

    if (standard_list_free(list) != -3) {
        puts("Empty free does not report error");
    } else puts("Empty free reported error");
    printf("=========================================\n");
    */

    puts("Calling standard_init");
    list = standard_list_init();
    //Some error checking for init needed


    printf("=========================================\n");
    puts("Testing Insertion");
    for (int i = 0; i < 10; i++) {
        if (standard_list_insert(list, (void *) (&data[i])) == 0) {
            printf("Successfully inserted %d\n", data[i]);
        } else {
            printf("Insert reported failure for element %d\n", data[i]);
        }
    }
    printf("=========================================\n");


    //Test display
    puts("Testing Display");
    int er;
    er = standard_list_print(list, printFunc);
    if (er == 0) puts("Successful print");
    else puts("Unsuccessful print");
    printf("=========================================\n");



    //Test deletion
    puts("Testing Deletion");
    for(int i = 0; i < 10; i++){
        if(standard_list_delete(list, (void *)(&data[i]), comp) == 0){
            printf("Successfully deleted %d\n", data[i]);
        } else printf("Failed to delete %d\n", data[i]);
    }

    for(int i = 0; i < 3; i++){
        if (standard_list_insert(list, (void *) (&data[i])) == 0) {
            printf("Successfully inserted %d\n", data[i]);
        } else {
            printf("Insert reported failure for element %d\n", data[i]);
        }
    }

    printf("=========================================\n");
    puts("Freeing list");
    standard_list_free(list);
}