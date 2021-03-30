#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include<stdbool.h>
#define ElemType int

typedef struct QNode{
    ElemType data;
    struct QNode *next;
}QNode;

typedef struct{
    QNode *front;
    QNode *rear;
}LinkQueue;

void initqueue(LinkQueue *q);

bool enqueue(LinkQueue *q,ElemType e);

bool dequeue(LinkQueue *q,ElemType *e);

#endif