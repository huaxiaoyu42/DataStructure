#include<stdlib.h>;
#include "../include/linked_stack.h"

void initstack(LinkStack *s){
    s->count = 0;
    s->top = NULL;
}

bool push(LinkStack *s,ElemType e){
    StackNode *n = (StackNode *)malloc(sizeof(StackNode));
    n->data = e;
    n->next = s->top;
    s->top = n;
    s->count++;
    return true;
}

bool pop(LinkStack *s,ElemType *e){
    if(s->top == NULL){
        return false;
    }
    *e = s->top->data;
    StackNode *p = s->top;
    s->top = s->top->next;
    free(p);
    s->count--;
    return true;
}