#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void Swap_With_Temp(int *a, int *b);
void Swap_Without_Temp(int *a, int *b);
void Swap_Without_Temp2(int *a, int *b);

//Sorting methods
void Insert_Sort_Better(int a[], int n);
void Insert_Shell_Sort(int a[], int n);

void Select_Sort(int a[], int n);

void MinHeapFixup(int a[], int i);
void MinHeapAddNumber(int a[], int n, int nNum);
void MinHeapFixdown(int a[], int i, int n);
void MinHeapDeleteNumber(int a[], int n);
void MakeMinHeap(int a[], int n);
void MinheapsortTodescendarray(int a[], int n);


void Bubble_Sort(int a[], int n);
void Bubble_Sort2(int a[], int n);

int Partition(int a[], int l, int r);
void Quick_Sort(int a[], int l, int r);

void merge(int a[], int first, int mid, int last, int temp[]);
void MSort(int a[], int first, int last, int temp[]);
void MergeSort(int a[], int n);
	
#endif

