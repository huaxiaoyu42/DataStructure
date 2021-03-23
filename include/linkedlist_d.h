
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


#endif