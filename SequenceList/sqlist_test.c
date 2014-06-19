#include "sqlist.h"

Status comp(int c1,int c2){
    if(c1==c2*c2)
        return TRUE;
    else
        return FALSE;
}

int main(int argc, const char * argv[]){
    SqList l;
    initial_list(&l);
    printf("finish initial list\n");
    int myarray[5] = {1,2,3,4,9};
    l.elem = myarray;
    l.length = 5;
    print_list(&l);
    insert_list(&l, 2, 100);
    printf("finish insert 100 before 2\n");
    print_list(&l);
    delete_list(&l, 2, 100);
    printf("finish delete 100\n");
    print_list(&l);
    
    if( check_listEmpty(l))
        printf("is empty\n");
    else
        printf("not empty\n");
    
    printf("list length = %d\n",get_listLength(l));
    
    int getelement = get_i_element(l, 3);
    printf("i = 3, get_i_element return: %d\n", getelement);
    
    int getlocal = locate_element(l,3,comp);
    printf("locate_element(l,3,comp) return: %d\n", getlocal);
    
}
