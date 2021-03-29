#ifndef SQ_DOUBLE_STACK_H
#define SQ_DOUBLE_STACK_H

#include<stdbool.h>
#define ElemType int

#define MAXSIZE 10

typedef struct{
    ElemType data[MAXSIZE];
    int top1; //栈1的栈顶指针
    int top2; //栈2的栈顶指针
}SqDoubleStack;

void initstack(SqDoubleStack *s);

bool push(SqDoubleStack *s,ElemType e,int stacknumber);

bool pop(SqDoubleStack *s,ElemType *e,int stacknumber);

#endif