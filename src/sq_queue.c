#include"../include/sq_queue.h"


void initqueue(SqQueue *q){
    q->front = 0;
    q->rear = 0;
}

int queuelength(SqQueue *q){
    int length = (q->rear - q->front + MAXSIZE) % MAXSIZE;

    return length;
}

bool enqueue(SqQueue *q,ElemType e){
    if((q->rear+1)%MAXSIZE == q->front){
        return false;
    }
    q->data[q->rear] = e;
    q->rear = (q->rear+1)%MAXSIZE;

    return true;
}

bool dequeue(SqQueue *q,ElemType *e){
    if(q->rear == q->front){
        return false;
    }

    *e = q->data[q->front];
    q->front = (q->front+1)%MAXSIZE;
    return true;
}

bool gethead(SqQueue *q,ElemType *e){
    if(q->front == q->rear){
        return false;
    }
    *e = q->data[q->front];
    return true;
}