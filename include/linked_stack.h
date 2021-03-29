#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include<stdbool.h>

#define ElemType int

typedef struct StackNode{
    ElemType data;
    struct StackNode *next;
}StackNode;

typedef struct LinkStack{
    StackNode *top;
    int count;
}LinkStack;


void initstack(LinkStack *s);

bool push(LinkStack *s,ElemType e);

bool pop(LinkStack *s,ElemType *e);


#endif