#include<stdio.h>
#include"../include/sqstack.h"
#include"../include/linkedlist.h"



bool is_palindrome(LNode *p){
    LNode *p1 = p->next;
    LNode *p2 = p1->next;
    SqStack s;

    

    while(p2 != NULL){
        Push(&s,p1->data);
        p1 = p1->next;
        p2 = p1->next->next;
    }

    int top;
    while(p1 != NULL){
        Pop(&s,&top);
        if(top != p1->data){
            return false;
        }
        p1 = p1->next;
    }
    return true;
}


int main(){

    LNode *p;
    InitList(&p);

    ListInsert(p,1,1);
    ListInsert(p,2,2);
    ListInsert(p,3,3);
    ListInsert(p,4,2);
    ListInsert(p,5,1);

    bool res = is_palindrome(p);

    if(res){
        printf("OK\n");
    }else{
        printf("FUCK\n");
    }


    return 0;
}