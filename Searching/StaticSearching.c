#include "searching.h"

Status initial_list(SqList* list){
    list->elem = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
    if(!list->elem)
        exit(OVERFLOW);
    list->length = 0;
    list->size = LIST_INIT_SIZE;
    return OK;
}//inital list 

Status print_list(SqList* list){
    int i;
    for(i = 0; i < list->length;i++){
        printf("(%d). %d\n",i, list->elem[i]);
    }
    return OK;
}


int Sequence_Searching(SqList list, int value){
    int i;
    for(i=0; i<list.length;i++){
        if(list.elem[i] == value)
            return i;
    }
    return -1;
}


//only for ordered
int Binary_Searching(SqList list, int value){
    int low = 0;
    int high = list.length-1;
    int middle;
    
    while(low <= high){
        middle = (low + high)/2;
        int temp = list.elem[middle];
        if(list.elem[middle] == value)
            return middle;
        else if(value < temp)
            high = middle-1;
        else
            low = middle+1;
    }
    return -1;
}
