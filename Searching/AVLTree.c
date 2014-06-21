#include "searching.h"
void AVLTree_traverse(BSTree t){
    if(t){
        AVLTree_traverse(t->lchild);
        printf("(%d,%d) ",t->data.value,t->data.order);
        AVLTree_traverse(t->rchild);
    }
}

void Right_Rotate(BSTree *t){
    BSTree newroot;
    newroot = (*t)->lchild;
    (*t)->lchild = newroot->rchild;
    newroot->rchild = *t;
    *t = newroot;
}

void Left_Rotate(BSTree *t){
    BSTree newroot;
    newroot = (*t)->rchild;
    (*t)->rchild = newroot->lchild;
    newroot->lchild = *t;
    *t = newroot;
}

void Left_Balance(BSTree *t){
    BSTree lc,rd;
    lc=(*t)->lchild;
    switch(lc->bf){
        case 1:
            (*t)->bf=lc->bf=0;
            Right_Rotate(t);
            break;
        case -1:
            rd=lc->rchild;
            switch(rd->bf){
            case 1: (*t)->bf=-1;
                lc->bf=0;
                break;
            case 0: (*t)->bf=lc->bf=0;
                break;
            case -1: (*t)->bf=0;
                lc->bf=1;
        }
            rd->bf=0;
            Left_Rotate(&(*t)->lchild);
            Right_Rotate(t);
    }
}

void Right_Balance(BSTree *t){
    BSTree rc,rd;
    rc=(*t)->rchild;
    switch(rc->bf){
        case -1:
            (*t)->bf=rc->bf=0;
            Left_Rotate(t);
            break;
        case 1:
            rd=rc->lchild;
            switch(rd->bf){
                case -1: (*t)->bf=1;
                    rc->bf=0;
                    break;
                case 0: (*t)->bf=rc->bf=0;
                    break;
                case 1: (*t)->bf=0;
                    rc->bf=-1;
        }
            rd->bf=0;
            Right_Rotate(&(*t)->rchild);
            Left_Rotate(t);
    }
}


Status AVLTree_Insert(BSTree *t,ElemType element,Status *taller){
    if(!*t){
        *t=(BSTree)malloc(sizeof(BSTNode));
        (*t)->data=element;
        (*t)->lchild=(*t)->rchild=NULL;
        (*t)->bf=0;
        *taller = TRUE;
    }else{
        if(element.value == (*t)->data.value){
            *taller = FALSE;
            return FALSE;
        }
        if(element.value < (*t)->data.value){
            if(!AVLTree_Insert(&(*t)->lchild,element,taller))
                return FALSE;
            if(*taller)
                switch((*t)->bf){
                    case 1:
                        Left_Balance(t);
                        *taller=FALSE;
                    break;
                    case 0:
                        (*t)->bf=1;
                        *taller=TRUE;
                        break;
                    case -1:
                        (*t)->bf=0;
                        *taller=FALSE;
            }
        }else{
            if(!AVLTree_Insert(&(*t)->rchild,element,taller))
                return FALSE;
            if(*taller)
                switch((*t)->bf){
                    case 1: (*t)->bf=0;
                        *taller=FALSE;
                        break;
                    case 0:
                        (*t)->bf=-1;
                        *taller=TRUE;
                        break;
                    case -1:
                        Right_Balance(t);
                        *taller=FALSE;
            }
        }
    }
    return TRUE;
}
