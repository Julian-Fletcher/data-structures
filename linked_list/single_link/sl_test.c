#include "single_link.h"

void printFunc(void *data){
    printf("%d\n", *((int *)data));
}

int comp(void *a, void *b){
    if(*(int *)a == *(int *)b){
        return 0;
    }
    return 1;
}

int main(){
    int data[] = {1,2,3,4,5,6,7,8,9,10};

    LinkedList list;
    list = standard_list_init();

    //Test insertion
    for(int i = 0; i < 10; i++){
        if(standard_list_insert(list, (void *)(&data[i])) == 0){
            puts("SUCCESS!");
        }
        else{
            puts("FAILURE!");
        }
    }


    //Test display
    puts("Displaying list");
    standard_list_print(list, printFunc);

    //Test deletion
    puts("Deleting 3");
    standard_list_delete(list, (void *)(&data[2]), comp);

    puts("Displaying list");
    standard_list_print(list, printFunc);

    puts("Freeing list");
    standard_list_free(list);

    list = standard_list_init();
    standard_list_insert(list, (void *)&data[0]);
    standard_list_print(list, printFunc);
    standard_list_free(list);
}