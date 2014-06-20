#ifndef SEARCHING_H
#define SEARCHING_H

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
    int size;
    int length;
}SqList;

typedef struct{
    int value;
    int order;
}ElemType;

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct BSTNode{
    ElemType data;
    int bf;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

Status initial_list(SqList* list);
Status print_list(SqList* list);
//*************** Static searching *****************
int Sequence_Searching(SqList list, int value);
int Binary_Searching(SqList list, int value);

//*************** Dynamic searching *****************
void BinarySearchTree_traverse(BiTree t);
BiTree BinarySearchTree_Searching(BiTree t, int value);
void BinarySearchTree_Searching_withpos(BiTree *t,int value,BiTree parent,BiTree *pointer,Status *flag);
Status BinarySearchTree_Insert(BiTree *t, ElemType elem);
void Delete_Treenode(BiTree *node);
Status BinarySearchTree_Delete(BiTree *t, ElemType elem);
void BinarySearchTree_Destroy(BiTree *t);
#endif

