#include<stdio.h>
#include "../include/sqlist.h"

int main(){


printf("hello\n");

    SqList l;
    InitList(&l);

    ListInsert(&l,1,1);
    ListInsert(&l,2,2);
    ListInsert(&l,3,3);
    ListInsert(&l,4,4);
    ListInsert(&l,5,5);
    ListInsert(&l,6,6);
    ListInsert(&l,7,7);
    ListInsert(&l,8,8);
    ListInsert(&l,9,9);
    


    for(int i = 0;i<9;i++){
        printf("%d ",l.data[i]);
    }
printf("\n");
    MoveList(&l,3);


    for(int i = 0;i<9;i++){
        printf("%d ",l.data[i]);
    }

    return 0;
}