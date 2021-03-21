#ifndef LINKEDLIST_H
#define LINKEDLISR_H

#include<stdbool.h>

#define ElemType int

typedef struct LNode{
    ElemType data;
    struct LNode *next; 
}LNode,*LinkedList;



bool InitList(LNode **L);

LNode* ListHeadInsert(LNode *l);


bool ListInsert(LNode *L,int i, ElemType e);

bool InsertNextNode(LNode *L, ElemType e);

bool InsertPriorNode(LNode *L, ElemType e);


#endif