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


int better_Partition(SqList* list, int low, int high){
    keyType pivot_value;
    pivot_value = list->node[low].value;
    list->node[0] = list->node[low];
    
    while(low < high){
        while(low < high && list->node[high].value >= pivot_value)
            --high;
        list->node[low] = list->node[high];
        while(low < high && list->node[low].value <= pivot_value)
            ++low;
        list->node[high] = list->node[low];
    }
    return low;
}

void better_QSort(SqList *list, int low, int high){
    int pivot_location;
    if(low < high){
        pivot_location = better_Partition(list, low, high);
        QSort(list, low, pivot_location-1);
        QSort(list,pivot_location+1,high);
    }
}

void better_Quick_Sort(SqList *list){
    QSort(list,1,list->length);
}
//******************  Selection Sorting  ***********************
int minValue(SqList list, int i){
    keyType min;
    int j,pos;
    pos = i;
    min = list.node[i].value;
    for(j = i+1; j<= list.length; ++j){
        if(list.node[j].value < min){
            pos = j;
            min = list.node[j].value;
        }
    }
    return pos;
}

void Simple_Select_Sort(SqList *list){
    int i, j;
    recordType temp;
    for(i = 1; i<list->length; i++){
        j = minValue(*list, i);
        if(i != j){
            temp = list->node[i];
            list->node[i] = list->node[j];
            list->node[j] = temp;
        }
    }
}

void Heap_Adjust(SqList *list, int s, int m){
    recordType rc;
    int j;
    
    rc = list->node[s];
    for(j=2*s; j<=m; j*=2){
        if(j<m && list->node[j].value<list->node[j+1].value)
            ++j;
        if(rc.value >= list->node[j].value)
            break;
        list->node[s] = list->node[j];
        s = j;
    }
    list->node[s] = rc;
}

void Heap_Sort(SqList *list){
    recordType temp;
    int i;
    for(i = list->length/2; i>0; --i)
        Heap_Adjust(list, i, list->length);
    for(i = list->length; i>1; --i){
        temp = list->node[1];
        list->node[1] = list->node[i];
        list->node[i] = temp;
        Heap_Adjust(list, 1, i-1);
    }
}


//******************  Merging Sorting  ***********************
void Merge(recordType s[],recordType t[],int start,int middle,int end){
    int k,l;
    int middle_plus_one = middle+1;
    for(k=start;start<=middle&&middle_plus_one<=end;++k){
        if (s[start].value <= s[middle_plus_one].value){
            t[k]=s[start];
            start++;
        }else{
            t[k]=s[middle_plus_one];
            middle_plus_one++;
        }
    }
    if(start<=middle)
        for(l=0;l<=middle-start;l++)
            t[k+l]=s[start+l];
    
    if(middle_plus_one<=end)
        for(l=0;l<=end-middle_plus_one;l++)
            t[k+l]=s[middle_plus_one+l];
}

//Merge sort s[start...end] to t[start...end]
void MSort(recordType s[], recordType t[], int start, int end){
    int middle;
    recordType t2[MAXSIZE+1];
    if(start==end)
        t[start]=s[start];
    else{
        middle = (start+end)/2;//separate s[start...end] to s[start...middle] and s[middle+1...end]
        MSort(s,t2,start,middle);//merge sort s[start...middle] to t2[start...middle]
        MSort(s,t2,middle+1, end);//merge sort s[middle+1...end] to t2[middle+1...end]
        Merge(t2, t, start, middle, end);//merge t2[start...middle] and t2[middle+1...end] to t[start...end]
    }
}

void Merge_Sort(SqList *list){
    MSort(list->node, list->node, 1, list->length);
}