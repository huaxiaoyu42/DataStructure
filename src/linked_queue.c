#include<stdlib.h>
#include "../include/linked_queue.h"

/**
 * 不带头节点的链式队列
*/


void initqueue(LinkQueue *q){
    q->front = NULL;
    q->rear = NULL;
}

bool enqueue(LinkQueue *q,ElemType e){
    QNode *s = (QNode *)malloc(sizeof(QNode));
    if(s == NULL){
        return false;
    }
    s->data = e;
    s->next = NULL;

    if (q->rear != NULL){
        q->rear->next = s;
    }
    else {
        q->front = s;
    }

    q->rear = s;
    
    return true;

}

bool dequeue(LinkQueue *q,ElemType *e){
    if(q->front == NULL && q->rear == NULL){
        return false;
    }

    *e = q->front->data;

    QNode *s = q->front;

    q->front = q->front ->next;

    if(q->rear == s){
        q->rear = NULL;
    }

    free(s);
    return true;
}