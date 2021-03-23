#include<stdio.h>
#include<stdlib.h>
#include "../include/linkedlist.h"

bool InitList(LNode **L){
    *L = (LNode *)malloc(sizeof(LNode));
    if(*L == NULL){
        return false;
    } 
    (*L)->next = NULL;
    return true;
}

LNode* ListHeadInsert(LNode *l){
    ElemType x;
    LNode *s;
    scanf("%d",&x);

    while(x != 9999){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = l->next;
        l->next = s;
        scanf("%d",&x);
    }

    return l;
}

LNode* ListTailInsert(LNode *l){
    ElemType x;
    LNode *s,*r=l;
    scanf("%d",&x);
    while(x != 9999){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d",&x);
    }
    r->next = NULL;
    return l;
}

LNode* GetElem(LNode *l, int i){
    int j = 1;
    LNode *p = l->next;
    if(i == 0){
        return l;
    }
    if(i < 1){
        return NULL;
    }
    while(p && j < i){
        p = p->next;
        j++;
    }
    return p;
}

LNode* LocateElem(LNode *l,ElemType e){
    LNode *p = l->next;
    while(p != NULL && p->data != e){
        p = p->next;
    }
    return p;
}

bool ListInsert(LNode *L,int i, ElemType e){
    if(i<1){    //位序从 1 开始，i < 1 为不合法 
        return false;
    }
    LNode *p; // 当前扫描到的结点
    int j = 0; // 当前扫描到的结点的位序
    p = L; // 将p指向头节点
    while(p != NULL && j < i - 1){  // 将p指向第i个结点的前一个结点
        p = p->next;
        j++;
    }
    if(p == NULL){ // i的值不合法
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
    if( s == NULL){
        return false;
    }
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

bool ListDelete(LNode *l,int i,ElemType *e){
    if(i < 1){
        return false;
    }
    LNode *p = l;
    int j = 0;
    while(p != NULL && j < i - 1){
        p = p->next;
        j++;
    }
    if(p == NULL){
        return false;
    }

    LNode *q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return true;


}

/**
 * 存在BUG，如果要删除的结点是最后一个，那么它就没有下一个结点。
*/
bool DeleteNode(LNode *p){
    if(p == NULL){
        return false;
    }
    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}