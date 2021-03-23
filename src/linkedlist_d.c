#include<stdlib.h>
#include "../include/linkedlist_d.h"


bool InitDLinkedList(DNode **l){
    *l = (DNode *)malloc(sizeof(DNode));
    if(*l == NULL){
        return false;
    }
    (*l)->prior = NULL;
    (*l)->next = NULL;
    return true;
}

bool InsertNextDNode(DNode *p,DNode *s){
    if(p == NULL || s == NULL){
        return false;
    }

    s->next = p->next;
    if(p->next != NULL){ // 如果p是最后一个结点，那它没有下一个结点
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
    return true;
}
