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


/**
 * 删除所有值为x的结点，并释放其空间
*/

void Delete_x(LNode *l,ElemType x);


/**
 * 从尾到头反向输出每个结点的值
*/
void Reverse_print(LNode *l);

/**
 * 删除一个最小值结点，假设最小值结点是唯一的
*/
void Delete_min(LNode *l);

/**
 * 反转链表
*/
void Reverse_linkedlist(LNode *l);


#endif