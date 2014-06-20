#include "sorting.h"
void print(SqList list){
    int i;
    for(i=1;i<=list.length;i++)
        printf("(%d,%d)",list.node[i].value,list.node[i].otherinfo);
    printf("\n");
}

//******************  Insert Sorting  ***********************
void Binary_Insert_Sort(SqList* list){
    int i;
    for(i = 2; i < list->length; i++){
        list->node[0] = list->node[i];
        int low = 1;
        int high = i-1;
        while(low <= high){
            int middle = (low + high)/2;
            if(list->node[0].value < list->node[middle].value)
                high = middle - 1;
            else
                low = middle + 1;
        }
        int j;
        for(j = i - 1; j >= high+1; --j)
            list->node[j+1] = list->node[j];
        
        list->node[high + 1] = list->node[0];
    }
}


void Straight_Insert_Sort(SqList* list){
    int i;
    for(i = 2; i <= list->length; i++){
        if(list->node[i].value < list->node[i-1].value){
            list->node[0] = list->node[i];//copy this to sentinel
            list->node[i] = list->node[i-1];
            int j;
            for(j=i-2; list->node[0].value<list->node[j].value; --j){
                list->node[j+1] = list->node[j];
            }
            list->node[j+1] = list->node[0];
        }
    }
}

//compare with straight insert sort
void Shell_Insert(SqList*list, int increment){
    int i,j;
    for( i = increment + 1; i <= list->length; ++i){
        if(list->node[i].value < list->node[i-1].value){
            list->node[0] = list->node[i];
            for(j = i - increment; j>0&&list->node[0].value<list->node[j].value; j-=increment)
                list->node[j+increment] = list->node[j];
            list->node[j+increment] = list->node[0];
        }
    }
}

void Shell_Sort(SqList* list, int dlta[], int t){
    int i;
    for(i = 0; i<t; ++i){
        Shell_Insert(list, dlta[i]);
        printf("No:%d ", i+1);
        print(*list);
    }
}

//******************  Quick Sorting  ***********************
void Bubble_Sort(SqList* list){
    int i, j;
    recordType temp;
    for (i = 0; i <= list->length; i++) {
        for (j = i+1; j <= list->length; j++) {
            if (list->node[i].value > list->node[j].value) {
                temp = list->node[i];
                list->node[i] = list->node[j];
                list->node[j] = temp;
            }
        }
    }
}


//part of quick sort
int Partition(SqList* list, int low, int high){
    recordType temp;
    keyType pivot_value;
    pivot_value = list->node[low].value;
    while(low < high){
        while(low < high && list->node[high].value >= pivot_value)
            --high;
        temp = list->node[low];
        list->node[low] = list->node[high];
        list->node[high] = temp;
        while(low < high && list->node[low].value <= pivot_value)
            ++low;
        temp = list->node[low];
        list->node[low] = list->node[high];
        list->node[high] = temp;
    }
    return low;
}

//part of quick sort
void QSort(SqList *list, int low, int high){
    int pivot_location;
    if(low < high){
        pivot_location = Partition(list, low, high);
        QSort(list, low, pivot_location-1);
        QSort(list,pivot_location+1,high);
    }
}

void Quick_Sort(SqList *list){
     QSort(list,1,list->length);
}
