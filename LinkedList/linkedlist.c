#include "linkedlist.h"

Status Initial_linkedlist(linkedlist *list){
    *list = (linkedlist)malloc(sizeof(struct linknode));
    if(!*list)
        return -1;
    (*list)->next = NULL;
    return OK;
}

Status Destroy_linkedlist(linkedlist *list){
    linkedlist temp;
    while(*list){
        temp = (*list)->next;
        free(*list);
        *list = temp;
    }
    return OK;
}

Status Clear_linkedlist(linkedlist *list){
    linkedlist temp;
    linkedlist new_head;
    
    new_head = (*list)->next;
    while(new_head){
        temp = new_head->next;
        free(temp);
        new_head = temp;
    }
    
    
    (*list)->next = NULL;
    return OK;
}

Boolean Check_list_empty(linkedlist list){
    if(list->next)
        return FALSE;
    else
        return TRUE;
}

int Get_list_length(linkedlist list){
    int i = 0;
    while(list->next){
        i++;
        list->next = list->next->next;
    }
    return i;
}

int Get_element(linkedlist list, int pos){
    int element;
    int p = 1;
    linkedlist pNext = list->next;
    while(pNext && p < pos){
        pNext = pNext->next;
        p++;
    }
    
    if(!pNext || p>pos)
        return ERROR;
    
    element = pNext->data;
    return element;
}

Status Insert_linkedlist(linkedlist list, int pos, int element){
    int find_pos = 0;
    linkedlist p = list;
    while(p && find_pos<pos-1){
        p = p->next;
        find_pos++;
    }
    
    if(!p || find_pos>pos-1){
        return ERROR;
    }
    
    linkedlist new_node = (linkedlist)malloc(sizeof(struct linknode));
    new_node->data = element;
    
    new_node->next = p->next;
    p->next = new_node;
    
    return OK;
}

Status Delete_list_element(linkedlist list, int pos){
    int find_pos = 0;
    linkedlist p = list;

    while(p->next && find_pos<pos-1){
        p = p->next;
        find_pos++;
    }
    
    if(!p->next || find_pos>pos-1){
        return ERROR;
    }
    
    linkedlist delete_node = p->next;
    p->next = delete_node->next;
    free(delete_node);
    
    return OK;
}

Status print_list(linkedlist list){
    linkedlist pNext = list->next;
    while(pNext){
        printf("(%d) ", pNext->data);
        pNext = pNext->next;
    }
    printf("\n");
    return OK;
}
