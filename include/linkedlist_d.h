
/**
 * 
 * 双向链表
*/

#ifndef LINKEDLIST_D_H
#define LINKEDLIST_D_H

#include <stdbool.h>

#define ElemType int

typedef struct DNode{
   ElemType data;
   struct DNode *prior;
   struct DNode *next; 
}DNode,*DLinkedList;


/**
 * 初始化带头节点的双向链表
*/
bool InitDLinkedList(DNode **l);


/**
 * 在p结点之后插入s结点
*/
bool InsertNextDNode(DNode *p,DNode *s);


/**
 * 删除p结点之后的结点
*/
bool DeleteNextDNode(DNode *p);

/**
 * 销毁链表
*/
void DestoryList(DNode **l);



#endif