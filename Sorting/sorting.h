#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 20

typedef int Status;
typedef int Boolean;


typedef int keyType;
typedef int infoType;

typedef struct{
    keyType value;
    infoType otherinfo;
}recordType;

typedef struct{
    recordType node[MAXSIZE+1];
    int length;
}SqList;

void print(SqList list);

void Straight_Insert_Sort(SqList* list);//O(n2),spend time on searching position

void Binary_Insert_Sort(SqList* list);//O(n2), only reduce value compare times

void Shell_Insert(SqList*list, int increment);
void Shell_Sort(SqList* list, int dlta[], int t);//Also named Diminishing Increment Sort, Best O(n)

void Bubble_Sort(SqList* list);//O(n2) two for loops

int Partition(SqList* list, int low, int high);
void QSort(SqList *list, int low, int high);
void Quick_Sort(SqList *list);//best

int better_Partition(SqList* list, int low, int high);
void better_QSort(SqList *list, int low, int high);
void better_Quick_Sort(SqList *list);//best

int minValue(SqList list, int i);
void Simple_Select_Sort(SqList *list);

void Heap_Adjust(SqList *list, int s, int m);
void Heap_Sort(SqList *list);//O(nlogn)

void Merge(recordType s[], recordType t[], int start, int middle, int end);
void MSort(recordType s[], recordType t[], int start, int end);
void Merge_Sort(SqList *list);
#endif

