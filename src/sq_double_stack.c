#include "../include/sq_double_stack.h"


void initstack(SqDoubleStack *s){
    s->top1 = -1;
    s->top2 = MAXSIZE;
}

bool push(SqDoubleStack *s,ElemType e,int stacknumber){
    if(s->top1 + 1 == s->top2){
        return false;
    }
    if(stacknumber == 1){
        s->top1++;
        s->data[s->top1] = e;
    }
    if(stacknumber == 2){
        s->top2--;
        s->data[s->top2] = e;
    }
    return true;
}

bool pop(SqDoubleStack *s,ElemType *e,int stacknumber){
    if(stacknumber == 1){
        if(s->top1 == -1){
            return false;
        }
        *e = s->data[s->top1];
        s->top1--;
    }
    if( stacknumber == 2){
        if(s->top2 == MAXSIZE){
            return false;
        }
        *e = s->data[s->top2];
        s->top2++;
    }
    return true;
}