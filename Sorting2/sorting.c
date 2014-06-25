#include "sorting.h"

void Swap_With_Temp(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Swap_Without_Temp(int *a, int *b){
	if( *a != *b){
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}
}

void Swap_Without_Temp2(int *a, int *b){
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;		
}

//******************  Insert Sorting  ***********************

void Insert_Sort_Better(int a[], int n){
	int i, j;
	for(i = 1; i<n; i++){
		if(a[i]<a[i-1]){
			int temp = a[i];
			for(j = i-1; j>=0&&a[j]>temp; j--){
				a[j+1] = a[j];
			}
			a[j+1] = temp;
		}
	}
}


void Insert_Shell_Sort(int a[], int n){
	int i, j, gap;
	for(gap = n/2; gap>0; gap/= 2){
		for (i = 0; i < gap; i++){  
			for (j = i + gap; j < n; j += gap)   
			if (a[j] < a[j - gap]){ 
				int temp = a[j];  
		        int k = j - gap;  
		        while (k >= 0 && a[k] > temp){  
					a[k + gap] = a[k];  
		            k -= gap;  
				}  
				a[k + gap] = temp;  
			}  
		}  
	}
}
//******************  Select Sorting  ***********************
void Select_Sort(int a[], int n){
	int i,j,min;
	for(i=0; i<n; i++){
		min = i;
		for(j=i+1; j<n; j++){
			if(a[j]<a[min])
				min = j;
		}
		Swap_With_Temp(&a[i],&a[min]);
	}
}

void MinHeapFixup(int a[], int i)  {  
    int j, temp;  
      
    temp = a[i];  
    j = (i - 1) / 2;      //父结点  
    while (j >= 0 && i != 0){  
        if (a[j] <= temp)  
            break;  
          
        a[i] = a[j];     //把较大的子结点往下移动,替换它的子结点  
        i = j;  
        j = (i - 1) / 2;  
    }  
    a[i] = temp;  
}


void MinHeapAddNumber(int a[], int n, int nNum){  
    a[n] = nNum;  
    MinHeapFixup(a, n);  
} 

//  从i节点开始调整,n为节点总数 从0开始计算 i节点的子节点为 2*i+1, 2*i+2  
void MinHeapFixdown(int a[], int i, int n){  
    int j, temp;  
  
    temp = a[i];  
    j = 2 * i + 1;  
    while (j < n)  
    {  
        if (j + 1 < n && a[j + 1] < a[j]) //在左右孩子中找最小的  
            j++;  
  
        if (a[j] >= temp)  
            break;  
  
        a[i] = a[j];     //把较小的子结点往上移动,替换它的父结点  
        i = j;  
        j = 2 * i + 1;  
    }  
    a[i] = temp;  
}  
//在最小堆中删除数  
void MinHeapDeleteNumber(int a[], int n){  
    Swap_With_Temp(&a[0], &a[n - 1]);  
    MinHeapFixdown(a, 0, n - 1);  
} 

//建立最小堆  
void MakeMinHeap(int a[], int n){  
    for (int i = n / 2 - 1; i >= 0; i--)  
        MinHeapFixdown(a, i, n);  
} 

void MinheapsortTodescendarray(int a[], int n){  
    for (int i = n - 1; i >= 1; i--)  
    {  
        Swap_With_Temp(&a[i], &a[0]);  
        MinHeapFixdown(a, 0, i);  
    }  
}
//******************  Quick Sorting  ***********************
void Bubble_Sort(int a[], int n){
    int i, j,temp;
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

//if swap happen, flag = true
//if swap not happen, flag = false, sort finished
void Bubble_Sort2(int a[], int n){
	int j,temp,flag;
	flag = 1;
	while(flag==1){
		flag = -1;
		for(j=1;j<n;j++){
			if(a[j]<a[j-1]){
				temp = a[j-1];
				a[j-1]=a[j];
				a[j] = temp;
				
				flag = 1;
			}
		}
		n--;
	}
}

int Partition(int a[], int l, int r){
	int i = l;
	int j = r;
	int x = a[l];
	while(i<j){
		while(i<j && a[j]>=x)
			j--;
		if(i<j){
			a[i] = a[j];
			i++;
		}
		
		while(i<j && a[i]<x)
			i++;
		if(i<j){
			a[j] = a[i];
			j--;
		}
	}
	a[j] = x;
	return i;
}

void Quick_Sort(int a[], int l, int r){
	if(l<r){
		int i = Partition(a,l,r);
		Quick_Sort(a,l,i-1);
		Quick_Sort(a,i+1,r);
	}
}


//******************  Merge Sorting  *********************
//merge a[] b[] to c[]
void merge(int a[], int first, int mid, int last, int temp[]){  
    int i = first, j = mid + 1;  
    int m = mid,   n = last;  
    int k = 0;  
      
    while (i <= m && j <= n)  
    {  
        if (a[i] <= a[j])  
            temp[k++] = a[i++];  
        else  
            temp[k++] = a[j++];  
    }  
      
    while (i <= m)  
        temp[k++] = a[i++];  
      
    while (j <= n)  
        temp[k++] = a[j++];  
      
    for (i = 0; i < k; i++)  
        a[first + i] = temp[i];  
}  

void MSort(int a[], int first, int last, int temp[]){  
    if(first < last){  
		int mid = (first + last) / 2;  
        MSort(a, first, mid, temp);    //左边有序  
        MSort(a, mid + 1, last, temp); //右边有序  
        merge(a, first, mid, last, temp); //再将二个有序数列合并  
    }  
} 

void MergeSort(int a[], int n){
	int temp[n];
	MSort(a,0,n-1,temp);
}

