#include "searching.h"
void BinarySearchTree_traverse(BiTree t){
    if(t){
        BinarySearchTree_traverse(t->lchild);
        printf("(%d,%d) ",t->data.value,t->data.order);
        BinarySearchTree_traverse(t->rchild);
    }
}

BiTree BinarySearchTree_Searching(BiTree t, int value){
    if((!t)|| value == t->data.value)
        return t;
    else if(value < t->data.value)
        return BinarySearchTree_Searching(t->lchild, value);
    else
        return BinarySearchTree_Searching(t->rchild,value);
}


void BinarySearchTree_Searching_withpos(BiTree *t,int value,BiTree parent,BiTree *pointer,Status *flag){
    if(!*t){
        *pointer=parent;
        *flag=FALSE;
    }else if (value == (*t)->data.value){
        *pointer=*t;
        *flag=TRUE;
    }else if(value < (*t)->data.value)
        BinarySearchTree_Searching_withpos(&(*t)->lchild,value,*t,pointer,flag);
    else
        BinarySearchTree_Searching_withpos(&(*t)->rchild,value,*t,pointer,flag);
}

Status BinarySearchTree_Insert(BiTree *t, ElemType elem){
    BiTree p,s;
    Status flag;
    BinarySearchTree_Searching_withpos(t,elem.value,NULL,&p,&flag);
    if(!flag){
        s=(BiTree)malloc(sizeof(BiTNode));
        s->data=elem;
        s->lchild=s->rchild=NULL;
        if(!p)
            *t=s;
        else if(elem.value < p->data.value)
            p->lchild=s;
        else
            p->rchild=s;
        return TRUE;
    }
    else
        return FALSE;
}

void Delete_Treenode(BiTree *node){
    if(!(*node)->rchild){
        BiTree temp = *node;
        *node = (*node)->lchild;
        free(temp);
    }else if(!(*node)->lchild){
        BiTree temp = *node;
        *node = (*node)->rchild;
        free(temp);
    }else{
        BiTree temp = *node;
        BiTree ltemp = (*node)->lchild;
        while(ltemp->rchild){
            temp=ltemp;
            ltemp=ltemp->rchild;
        }
        (*node)->data=ltemp->data;
        if(temp!=*node)
            temp->rchild=ltemp->lchild;
        else
            temp->lchild=ltemp->lchild;
        free(ltemp);
    }
}

Status BinarySearchTree_Delete(BiTree *t, ElemType elem){
    if(!t)
        return FALSE;
    else{
        if(elem.value == (*t)->data.value)
            Delete_Treenode(t);
        else if(elem.value < (*t)->data.value)
            BinarySearchTree_Delete(&(*t)->lchild, elem);
        else
            BinarySearchTree_Delete(&(*t)->rchild, elem);
        return TRUE;
    }
}

void BinarySearchTree_Destroy(BiTree *t){
    if(*t){
        if((*t)->lchild)
            BinarySearchTree_Destroy(&(*t)->lchild);
        if((*t)->rchild)
            BinarySearchTree_Destroy(&(*t)->rchild);
        free(*t);
        *t=NULL;
    }
}

