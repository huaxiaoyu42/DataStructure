#include<stdio.h>
#include "../include/sqlist.h"

int main(){

    // int a[10]={1,2,3,4,5,6,7,8,9};


    SqList *l;
    InitList(l);

    l->data[0] = 0;
    l->data[1] = 1;
    l->data[2] = 2;
    l->data[3] = 3;
    l->data[4] = 4;
    l->data[5] = 5;
    l->data[6] = 6;
    l->data[7] = 7;
    l->data[8] = 8;
    l->data[9] = 9;

    l->length = 10;


    // Reverse_two_list(a,5,5,10);
    MoveList(l,2);


    for(int i = 0;i<10;i++){
        printf("%d ",l->data[i]);
    }

    return 0;
}