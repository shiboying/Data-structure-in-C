#include "sorting.h"

int main(int argc, const char * argv[]){
    recordType d[8]={{49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8}};
    SqList l1,l2,l3,l4,l5,l6,l7,l8,l9;
    int i;
    int dt[3]={5,3,1};
    
    for(i=0;i<8;i++)
        l1.node[i+1]=d[i];
    l1.length=8;
    l2=l1;
    l3=l2;
    l4=l3;
    l5=l4;
    l6=l5;
    l7=l6;
    l8=l7;
    l9=l1;
    printf("Original sequence:\n");
    print(l1);
    Straight_Insert_Sort(&l1);
    printf("After stright insert sort:\n");
    print(l1);
    Binary_Insert_Sort(&l2);
    printf("After binary insert sort:\n");
    print(l2);
    Shell_Sort(&l3,dt,3);
    printf("After shell insert sort:\n");
    print(l3);
    Bubble_Sort(&l4);
    printf("After (quick) bubble sort:\n");
    print(l4);
    Quick_Sort(&l5);
    printf("After quick sort:\n");
    print(l5);
    better_Quick_Sort(&l6);
    printf("After better quick insert sort:\n");
    print(l6);
    Simple_Select_Sort(&l7);
    printf("After simple select sort:\n");
    print(l7);
    Heap_Sort(&l8);
    printf("After (selection) heap sort:\n");
    print(l8);
    Merge_Sort(&l9);
    printf("After merge sort:\n");
    print(l9);

}
