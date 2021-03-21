#ifndef LINEARLIST_H
#define LINEARLIST_H

#ifndef BOOLSTD_H
#define BOOLSTD_H

#include<stdbool.h>

#endif 


#define ElemType int // 定义数据的类型
#define MaxSize 10   // 定义最大长度
/**
 * 
 * 定义顺序表的结构体 -- 静态分配
 * data: 存储数据的数组
 * length: 顺序表当前的长度 
 * 
*/
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;


void InitList(SqList *L);

void ListInsert(SqList *L, int i, ElemType e);


bool ListDelete(SqList *L, int i, ElemType *e);

ElemType GetElem(SqList *L, int i);

int LocateElem(SqList *L, ElemType e);

ElemType DelMin(SqList *L);

bool ReverseList(SqList *L);

void Del_X(SqList *L, ElemType x);

void Del_bt_s_t(SqList *L,int s, int t );

void Del_Dup(SqList *L);

/** 
 * 2.2.7 将两个有序顺序表合并成为一个新的有序顺序表，
 *       并由函数返回结果顺序表
*/
bool Merge(SqList a, SqList b,SqList *c);

/**
 * 2.2.8 将数组中两个顺序表的位置互换
 * 
*/
void Reverse_two_list(ElemType a[],int left,int right,int arraySize);


/**
 * 2.2.9 查找数值为x的元素，若找到，则将其与后继元素位置相交换，
 *       若找不到，则将其插入表中，并使表中的元素仍递增
*/
void SearchExchangeInsert(SqList *l,ElemType x);

#endif