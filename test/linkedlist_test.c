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



void Split_linkedlist_test(){
    LNode *l;

    InitList(&l);

    for(int i = 1;i<10;i++){
        ListInsert(l,i,i);
    }
    LNode *p;
    PRINT

    LNode *a;
    LNode *b;
    InitList(&a);
    InitList(&b);

    Split_linkedlist(l,a,b);

    p = a->next;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");

    p = b->next;
    while(p != NULL){
        printf("%d ",p->data);
    p = p->next;
    }
    printf("\n");
}

void Split_linkedlist_2_test(){
    LNode *l;

    InitList(&l);

    for(int i = 1;i<10;i++){
        ListInsert(l,i,i);
    }
    LNode *p;
    PRINT

    LNode *a;
    LNode *b;
    InitList(&a);
    InitList(&b);

    Split_linkedlist_2(l,a,b);

    p = a->next;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");

    p = b->next;
    while(p != NULL){
        printf("%d ",p->data);
    p = p->next;
    }
    printf("\n");
}


void Delete_same_test(){
    LNode *l;

    InitList(&l);

    for(int i = 1;i<10;i++){
        ListInsert(l,i,rand()%10);
    }
    LNode *p;
    PRINT

    Delete_same(l);

    PRINT
}

void Merge_linkedlist_test(){
    LNode *a;
    LNode *b;
    InitList(&a);
    InitList(&b);

    for(int i = 1;i<7;i++){
        ListInsert(a,i,i);
    }
    int k = 1;
    for(int i = 5;i<8;i++){
        ListInsert(b,k,i); 
        k++;
    }

    Merge_linkedlist(a,b);
    LNode *p = a->next;

    while( p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    //srand((unsigned)time(NULL));
    
    Merge_linkedlist_test();

    return 0;
}