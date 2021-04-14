#include"../include/sqstack.h"

void InitStack(SqStack* s){
    s->top = -1;
}

bool Push(SqStack *s,ElemType x){
    if(s->top == MaxSize-1){
        return false;
    }
    s->top = s->top + 1;
    s->data[s->top] = x;
    return true;
}

bool Pop(SqStack *s,ElemType *x){
    if(s->top == -1){
        return false;
    }
    *x = s->data[s->top];
    s->top = s->top - 1;
    return true;
}

bool GetTop(SqStack *s,ElemType *x){
    if(s->top == -1){
        return false;
    }
    *x = s->data[s->top];
    
    return true;
}

bool stack_is_empty(SqStack *s){
    if(s->top == -1){
        return true;
    }else{
        return false;
    }
}


