#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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

typedef struct linknode{
    int data;
    struct linknode *next;
}linknode, *linkedlist;


Status Initial_linkedlist(linkedlist *list);
Status Destroy_linkedlist(linkedlist *list);
Status Clear_linkedlist(linkedlist *list);
Boolean Check_list_empty(linkedlist list);
int Get_list_length(linkedlist list);
int Get_element(linkedlist list, int pos);
Status Insert_linkedlist(linkedlist list, int pos, int element);
Status Delete_list_element(linkedlist list, int pos);
Status print_list(linkedlist list);

#endif

