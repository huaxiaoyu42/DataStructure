/**
 * 顺序栈
*/

#ifndef SQSTACK_H
#define SQSTACK_H

#include<stdbool.h>
#define MaxSize 10


#define ElemType int

typedef struct {
    ElemType data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack *s);

bool Push(SqStack *s,ElemType x);

bool Pop(SqStack *s,ElemType *x);

bool GetTop(SqStack *s,ElemType *x);

#endif