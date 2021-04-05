#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ElemType int

typedef struct LNode{
    ElemType data;
    struct LNode *next; 
}LNode;




bool ListInsert(LNode **l,int n,ElemType e){
    if(n == 1){
        LNode *q;
        q = (LNode *)malloc(sizeof(LNode));
        q->data = e;
        // if(*l == NULL){
        //     q->next = NULL;
        // }else{
        //     q->next = (*l)->next;
        // }
        q->next = *l;

        (*l) = q;
        
    }

    LNode *p = *l;
    int j = 1;
    while(p != NULL && j < n -1){
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

    return 0;
}


bool delete(LNode **l,int n,ElemType *e){

    if(n == 1){
        (*l)->next = (*l)->next->next;
    }

    LNode *p = *l;
    int j = 1;
    while(p != NULL && j < n - 1){
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
 * 设计一个递归算法，删除不带头节点的单链表中的所有值为x的结点
*/

void recursion_delete(LNode **l,ElemType x){
    LNode *p;
    if( *l == NULL){
        return;
    }
    if((*l)->data == x){
        p = *l;
        *l = (*l)->next;
        free(p);
        recursion_delete(l,x);
    }else{
        recursion_delete(&((*l)->next),x);
    }
}

int main(){

    LNode *l = NULL;

    for(int i =1;i<=10;i++){
        ListInsert(&l,i,i%2);
    }


    LNode *p;
    p = l;

    for(int i = 0;i<10;i++){
        printf("%d ",p->data);
        p = p->next;

    }

    printf("\n");

    recursion_delete(&l,0);

    p = l;
    while(p->next != NULL){
        printf("%d ",p->data);
        p = p->next;
    }

    return 0;
}







