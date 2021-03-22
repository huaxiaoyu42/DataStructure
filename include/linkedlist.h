#ifndef LINKEDLIST_H
#define LINKEDLISR_H

#include<stdbool.h>

#define ElemType int

typedef struct LNode{
    ElemType data;
    struct LNode *next; 
}LNode,*LinkedList;


/**
 * 初始化带有头节点的链表
*/
bool InitList(LNode **L);

/**
 * 头插法建立链表
*/
LNode* ListHeadInsert(LNode *l);

/**
 * 尾插法建立链表
*/
LNode* ListTailInsert(LNode *l);

LNode* GetElem(LNode *l,int i){
    int j = 0;
    LNode *p = l->next;
    if(i == 0){
        return l;
    }
    // if(i < xcm/)
}


bool ListInsert(LNode *L,int i, ElemType e);

bool InsertNextNode(LNode *L, ElemType e);

bool InsertPriorNode(LNode *L, ElemType e);



#endif