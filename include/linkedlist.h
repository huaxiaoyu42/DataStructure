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

/**
 * 带头节点的单链表，使其元素递增有序
*/

void Sort_linkedlist(LNode *l);

/**
 * 单链表中元素无序，删除介于给定的两个值之间的元素
*/

void Range_delete(LNode *l,int min,int max);

/**
 * 按照递增次序输出单链表中的各个结点的数据元素，并释放结点所占的存储空间
*/
void Print_and_delete_min(LNode *l);

/**
    按照奇偶拆分链表
*/
void Split_linkedlist(LNode *l,LNode *a,LNode *b);

/**
 * 按照奇偶顺序拆分链表，偶链表逆序
*/
void Split_linkedlist_2(LNode *l,LNode *a,LNode *b);

/**
 * 删除链表中重复的元素
*/

void Delete_same(LNode *l);

/**
 * 合并两个有序递增的链表，结果链表递减
*/

void Merge_linkedlist(LNode *a,LNode *b);

#endif