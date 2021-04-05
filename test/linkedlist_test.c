#include<stdlib.h>
#include<stdio.h>
#include "../include/linkedlist.h"


void Delete_x_test(){
    LNode *l;

    InitList(&l);

    for(int i = 1;i<10;i++){
        ListInsert(l,i,i%2);
    }
    LNode *p = l->next;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
    Delete_x(l,0);
    p = l->next;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
}

void Reverse_print_test(){
    LNode *l;

    InitList(&l);

    for(int i = 1;i<10;i++){
        ListInsert(l,i,i);
    }
    LNode *p = l->next;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n"); 

    Reverse_print(l);
}

void Delete_min_test(){
    LNode *l;

    InitList(&l);

    for(int i = 1;i<10;i++){
        ListInsert(l,i,i);
    }
    LNode *p = l->next;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n"); 
    Delete_min(l);
    p = l->next;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
}

void Reverse_linkedlist_test(){
    LNode *l;

    InitList(&l);

    for(int i = 1;i<10;i++){
        ListInsert(l,i,i);
    }
    LNode *p = l->next;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n"); 

    Reverse_linkedlist(l);

    p = l->next;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
}
int main(){

    Reverse_linkedlist_test();

    return 0;
}