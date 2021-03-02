#include<stdio.h>

#define ElemType int // 定义数据的类型
#define MaxSize 10   // 定义最大长度
/**
 * 
 * 定义顺序表的结构体 -- 静态分配
 * data: 存储数据的数组
 * length: 顺序表当前的长度 
 * 
*/
typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;

/**
 * 
 * 初始化顺序表，将data中的每个元素值为零
 * 
*/
void InitList(SqList *L){
    for(int i = 0; i < MaxSize; i++){
        L->data[i] = 0;
    }
    L->length = 0;
}


void ListInsert(SqList *L, int i, ElemType e){
    for(int j = L->length; j >= i; j--){
        L->data[j] = L->data[j-1];
    }
    L->data[i-1] = e;
    L->length++;
}

int main(void){
    SqList l;
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