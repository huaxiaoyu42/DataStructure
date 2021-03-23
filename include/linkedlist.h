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

/**
 * 按序号查找结点
*/
LNode* GetElem(LNode *l, int i);

/**
 * 按值查找结点
*/
LNode* LocateElem(LNode *l,ElemType e);

/**
 * 在第i个位置插入元素e
*/
bool ListInsert(LNode *L,int i, ElemType e);

/**
 * 在L结点之后插入结点
*/
bool InsertNextNode(LNode *L, ElemType e);

/**
 * 在L结点之前插入结点
*/
bool InsertPriorNode(LNode *L, ElemType e);


/**
 * 按位序删除结点
*/
bool ListDelete(LNode *l,int i,ElemType *e);

/**
 * 删除指定结点p
*/

bool DeleteNode(LNode *p);


#endif