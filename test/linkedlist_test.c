#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include "../include/linkedlist.h"

#define PRINT     p  = l->next;\
    while(p != NULL){\
        printf("%d ",p->data);\
        p = p->next;\
    }\
    printf("\n");\


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

void Sort_linkedlist_test(){
    LNode *l;

    InitList(&l);

    for(int i = 1;i<10;i++){
        ListInsert(l,i,rand()%10);
    }
    LNode *p;

    PRINT

    Sort_linkedlist(l);

    PRINT

}

void Range_delete_test(){
    LNode *l;

    InitList(&l);

    for(int i = 1;i<20;i++){
        ListInsert(l,i,rand()%20);
    }
    LNode *p;
    PRINT

    Range_delete(l,5,10);

    PRINT
}

void Print_and_delete_min_test(){
    LNode *l;

    InitList(&l);

    for(int i = 1;i<10;i++){
        ListInsert(l,i,rand()%10);
    }
    LNode *p;
    PRINT
    Print_and_delete_min(l);
}

int main(){
    srand((unsigned)time(NULL));
    Print_and_delete_min_test();

    return 0;
}