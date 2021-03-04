#include<stdio.h>
#include<stdlib.h>

#define ElemType int
typedef enum {false,true} bool;

typedef struct LNode{
    ElemType data;
    struct LNode *next; 
}LNode,*LinkedList;

bool InitList(LNode **L){
    *L = (LNode *)malloc(sizeof(LNode));
    if(*L == NULL){
        return false;
    } 
    (*L)->next = NULL;
    return true;
}

int main(void){
    LNode *L;
    InitList(&L);
    (*L).data = 10;
    printf("%d\n",(*L).data);

    return 0;
}