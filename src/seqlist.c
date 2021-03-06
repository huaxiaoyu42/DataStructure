#include<stdio.h>
#include<stdlib.h>

typedef enum { false, true} bool;

#define ElemType int // 定义数据的类型
#define InitSize 10  // 定义顺序表的初始长度

/**
 * 
 * 定义顺序表的结构体 -- 动态分配
 * data: 数据的头指针 
 * MaxSize: 顺序表的最大容量
 * length:  顺序表的当前长度
 * 
*/
typedef struct{
    ElemType *data;
    int MaxSize;
    int length;
}SeqList;

/**
 * 
 * 初始化顺序表,根据初始长度申请内存空间
 * 
*/
void InitList(SeqList *L){
    L->data = (ElemType *)malloc(InitSize * sizeof(ElemType));
    L->length = 0;
    L->MaxSize = InitSize;
}

/**
 *
 * 增加动态数组的长度
 * len 为要增加的长度
 * 
*/
void IncreaseSize(SeqList *L, int len){
    ElemType *p = L->data;
    L->data = (ElemType *)malloc((L->MaxSize + len) * sizeof(ElemType));
    for(int i = 0; i < L->length; i++){
        L->data[i] = p[i];
    }
    L->MaxSize = L->MaxSize + len;
    free(p); // 释放原来的内存空间
}

void ListInsert(SeqList *L, int i, ElemType e){
    for(int j = L->length; j >= i; j--){
        L->data[j] = L->data[j-1];
    }
    L->data[i-1] = e;
    L->length++;
}


bool ListDelete(SeqList *L, int i, ElemType *e){
    if(i < 1 || i > L->length){
        return false;
    }
    *e = L->data[i - 1];
    for(int j = i; j < L->length; j++){
        L->data[j-1] = L->data[j];
    }
    L->length--;
    return true;
}


int main(void){

    SeqList l;
    InitList(&l);
    for(int i = 1; i<= 10;i++){
        ListInsert(&l,i,i);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",l.data[i]);        
    } 

    return 0;
}