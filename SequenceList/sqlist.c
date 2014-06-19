#include "sqlist.h"

Status initial_list(SqList* list){
    list->elem = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
    if(!list->elem)
        exit(OVERFLOW);
    list->length = 0;
    list->size = LIST_INIT_SIZE;
    return OK;
}//inital list 


Status destroy_list(SqList* list){
    list->length = 0;
    list->size = 0;
    free(list->elem);
    list->elem = NULL;
    return OK;
}//Destroy list


Status clear_list(SqList* list){
    list->length = 0;
    list->size = LIST_INIT_SIZE;
    return OK;
    
}//reset list to be empty


Status check_listEmpty(SqList list){
    if(0 == list.length)
        return TRUE;
    else
        return FALSE;
}//check list is empty or not


int get_listLength(SqList list){
    return list.length;
}//get list length


int get_i_element(SqList list, int i){
    if(i<1||i>list.length+1)
        return ERROR;
    
    return list.elem[i-1];
}//get ith element

int locate_element(SqList list, int element, Status(*compare)(int,int)){
    int *p;
    int i = 1;
    p = list.elem;
    while(i <= list.length && !compare(*p,element)){
        ++p;
        ++i;
    }
    if(i<=list.length)
        return i;
    else
        return 0;
}//return the first one that satisfies compare();
                   
Status insert_list(SqList* list, int i, int element){
    if(i<1||i>list->length+1)
        return ERROR;
    if(list->length>list->size){
        printf("size need to be increased\n");
       int* newbase = (int*)realloc(list->elem, (list->size+LIST_INCREMENT)*sizeof(int));
        if(!newbase)
            exit(1);
        list->elem = newbase;
        list->size += LIST_INCREMENT;
    }
    int *q = &(list->elem[i-1]);
    int *p;
    for(p = &(list->elem[list->length-1]); p>=q;--p){
        *(p+1) = *p;
    }
    *q = element;
    ++list->length;
    return OK;
}

Status delete_list(SqList *list, int i, int element){
    if((i<1)||(i>list->length))
        return -1;
    int *p = &(list->elem[i-1]);
    element = *p;
    int *q = &(list->elem[list->length-1]);
    for(++p;p<=q;++p)
        *(p-1) = *p;
    --list->length;
    return OK;
}

Status print_list(SqList* list){
    int i;
    for(i = 0; i < list->length;i++){
        printf("(%d). %d\n",i+1, list->elem[i]);
    }
    return OK;
}

