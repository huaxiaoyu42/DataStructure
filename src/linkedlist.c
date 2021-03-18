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

bool ListInsert(LNode *L,int i, ElemType e){
    if(i<1){
        return false;
    }
    LNode *p;
    int j = 0;
    p = L;
    while(p != NULL && j < i - 1){
        p = p->next;
        j++;
    }
    if(p == NULL){
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
    
bool InsertNextNode(LNode *L, ElemType e){
    if(L == NULL){
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(ElemType));
    s->data = e;
    s->next = L->next;
    L->next = s;
    return true;
}

bool InsertPriorNode(LNode *L, ElemType e){
    if(L == NULL){
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL){
        return false;
    }
    s->next = L->next;
    L->next = s;
    s->data = L->data;
    L->data = e;
    return true;
}

int main(void){
    LNode *L;
    InitList(&L);
    (*L).data = 10;
    printf("%d\n",(*L).data);

    return 0;
}