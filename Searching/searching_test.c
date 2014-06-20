#include "searching.h"

int main(int argc, const char * argv[]){
    SqList l;
    initial_list(&l);
    printf("finish initial list\n");
    int myarray[10] = {1,2,3,4,9,43,45,55,65,99};
    l.elem = myarray;
    l.length = 10;
    print_list(&l);
    int findvalue = Sequence_Searching(l, 45);
    printf("Sequence Searching: findvalue = %d\n", findvalue);
    int findvalue2 = Binary_Searching(l, 45);
    printf("Binary Searching: findvalue = %d\n\n\n", findvalue2);
    
    
    BiTree dt;
    int i;
    ElemType r[10]={{45,1},{12,2},{53,3},{3,4},{37,5},{24,6},{100,7},{61,8},{90,9},{78,10}};
    dt = NULL;
    for(i=0;i<10;i++)
        BinarySearchTree_Insert(&dt,r[i]);
    
    BinarySearchTree_traverse(dt);
    printf("\n");
    BinarySearchTree_Delete(&dt, r[2]);
    BinarySearchTree_traverse(dt);
    printf("\n");
    BinarySearchTree_Destroy(&dt);
    BinarySearchTree_traverse(dt);
    printf("\n");
}
