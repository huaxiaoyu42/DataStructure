#ifndef LINEARLIST_H
#define LINEARLIST_H




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

bool Merge(SqList a, SqList b,SqList *c);

#endif