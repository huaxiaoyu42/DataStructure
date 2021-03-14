#include <stdio.h>

typedef enum
{
    false,
    true
} bool;

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

/**
 * 
 * 初始化顺序表，将data中的每个元素值为零
 * 
*/
void InitList(SqList *L)
{
    for (int i = 0; i < MaxSize; i++)
    {
        L->data[i] = 0;
    }
    L->length = 0;
}

void ListInsert(SqList *L, int i, ElemType e)
{
    for (int j = L->length; j >= i; j--)
    {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;
    L->length++;
}

bool ListDelete(SqList *L, int i, ElemType *e)
{
    if (i < 1 || i > L->length)
    {
        return false;
    }
    *e = L->data[i - 1];
    for (int j = i; j < L->length; j++)
    {
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return true;
}

ElemType GetElem(SqList *L, int i)
{
    return L->data[i - 1];
}

int LocateElem(SqList *L, ElemType e)
{
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}

ElemType DelMin(SqList *L)
{
    ElemType min = L->data[0];
    int min_index = 0;

    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] < min)
        {
            min_index = i;
            min = L->data[i];
        }

        L->data[min_index] = L->data[L->length - 1];
        L->length--;
        return min;
    }
}

bool ReverseList(SqList *L){
    int pre = 0;
    int tail = L->data[L->length -1];
    ElemType tmp;

    while(pre < tail){
       tmp = L->data[pre]; 
       L->data[pre] = L->data[tail];
       L->data[tail] = tmp;
       pre++;
       tail--;
    }


}

int main(void)
{
    SqList l;
    InitList(&l);
    for (int i = 1; i <= 10; i++)
    {
        ListInsert(&l, i, i);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", l.data[i]);
    }
 //   printf("min is %d\n", DelMin(&l));
    ReverseList(&l);

    for (int i = 0; i < l.length; i++)
    {
        printf("%d ", l.data[i]);
    }

    return 0;
}