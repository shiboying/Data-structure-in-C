#ifndef SQLIST_H
#define SQLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define LIST_INIT_SIZE 10
#define LIST_INCREMENT 3

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int Boolean;

typedef struct{
    int *elem;
    int length;//real length
    int size;//list size
}SqList;

Status initial_list(SqList* list);//initial an empty sqlist
Status destroy_list(SqList* list);//Destroy list
Status clear_list(SqList* list);//reset list to be empty
Status check_listEmpty(SqList list);//check list is empty or not
int get_listLength(SqList list);//get list length
int get_i_element(SqList list, int i);//get ith element
int locate_element(SqList list, int element, Status(*compare)(int,int));
Status insert_list(SqList* list, int i, int element);//inisert element before i
Status delete_list(SqList *list, int i, int element);//delete i and element is return element
Status print_list(SqList* list);//printlist

#endif

