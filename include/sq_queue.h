#ifndef SQ_QUEUE_H
#define SQ_QUEUE_H

#include<stdbool.h>

#define ElemType int
#define MAXSIZE 10

typedef struct{
    ElemType data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

void initqueue(SqQueue *q);

int queuelength(SqQueue *q);

bool enqueue(SqQueue *q,ElemType e);

bool dequeue(SqQueue *q,ElemType *e);

bool gethead(SqQueue *q,ElemType *e);



#endif