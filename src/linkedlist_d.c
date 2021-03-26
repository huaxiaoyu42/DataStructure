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

bool DeleteNextDNode(DNode *p){
    if(p == NULL){
        return false;
    }
    DNode *q = p->next;
    if(q == NULL){
        return false;
    }
    p->next = q->next;
    if(q->next != NULL){
        q->next->prior = q;
    }
    free(q);
    return true;
}

void DestoryList(DNode **l){

   while((*l)->next != NULL){
         DeleteNextDNode(*l);
   }
   free(*l);

   (*l) = NULL;

}


